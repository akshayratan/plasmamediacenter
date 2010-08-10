/***************************************************************************
 *   Copyright 2010 by Onur-Hayri Bakici <thehayro@gmail.com               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

engine.include('xmldom.js');
engine.include('xmlsax.js');
engine.include('xmlw3cdom.js');
//engine.include('youtube.js');
engine.include('sha1.js');
engine.include('stdutils.js');
//engine.include('picasa.js');

var MediaType = {"photo":0, "video":1};

//The media interface
var nl = '\n';

function WebMedia()
{
  this.type = null;
  this.id = null;
  this.description = null;
  this.keywords = new Array();
  this.author = null;
  this.updated = null;
  this.published = null;
  this.link = null;
  this.width = null;
  this.height = null;
  this.size = null;
  //this.collection = null;
  this.thumbnailLink = null;
//  this.collectionID = null;
  
  this.toString = function()
  {
    var res = this.type + nl +
	      this.id + nl + 
	      this.description + nl;
	      for (var i = 0; i < this.keywords.length; i++)
		res += this.keywords[i] + nl;
	      res += this.author + nl +
	      this.updated.toLocalString() + nl +
	      this.published.toLocalString() + nl +
	      this.link + nl + 
	      this.width + nl +
	      this.height + nl + 
	      this.size + nl + 
	      this.thumbnailLink;
      return res;
  }
  
  this.toArray = function()
  {
    var array = new Array();
    array['type'] = MediaTypeToString(this.type);
    array['id'] = this.id;
    array['title'] = this.title;
    array['author'] = this.author;
    array['description'] = this.description;    
    array['keywords'] = this.keywords;
    array['updated'] = this.updated;
    array['published'] = this.published;
    array['link'] = this.link;
    array['width'] = this.width;
    array['height'] = this.height;
    array['size'] = this.size;
    array['thumbnailLink'] = this.thumbnailLink;
    return array;
  }
  //rating?
  //comments?
}


function MediaTypeToString(mediaType)
{
  switch(mediaType)
  {
    case 0: return "photo";
    case 1: return "video";
    default: return "undefined";
  }
}
//albums and playlists
function WebMediaCollection()
{
  this.id = null;
  this.title = null;
  this.author = null;
  this.description = null;
  this.updated = null;
  this.published = null;
  this.link = null;
  this.webmedia = new Array();
  
  this.toArray = function()
  {
    var arr = new Array()
    arr['id'] = this.id;
    arr['title'] = this.title;
    arr['author'] = this.author;
    arr['description'] = this.description;
    arr['published'] = this.published;
    arr['updated'] = this.updated;
    arr['link'] = this.link;
    return arr;
  }
}

//attributes that only appear in videos: duration, embeddedHTML, resolution, 


var mediaEngine = new WebMediaDataEngine();

function WebMediaDataEngine()
{
  this.addons = new Array();
}

function addonCreated(addon)
{
  print("new addon: " + addon)
  mediaEngine.addons.push(addon);
}

engine.addEventListener("addonCreated", addonCreated)
addons = engine.listAddons("org.kde.plasma.dataengine.webmedia");
print("number of addons: " + addons.length);
for (i in addons) 
{
  print("Addon: " + addons[i].name);
  engine.loadAddon("org.kde.plasma.dataengine.webmedia", addons[i].id);
}

function GetWebMediaEngine()
{
  return mediaEngine;
}

// the traditional sourceRequestEvent
engine.sourceRequestEvent = function (source)
{
 if (source == "providers")
 {
  for (var i = 0; i < mediaEngine.addons.length; i++)
  {
    setData(mediaEngine.addons[i].toString(), "");
  }
  return;
 }
 
 /*
  queries look like this:
  all:media&text=searchstring searches all providers for searchstring
  provider:media&text=searchstring searches a specific provider for searchstring
 */
 if (source.indexOf(":") == -1)
   return;
 var queryParams = new Array();
 var params = source.split("&");
 for (var i = 0; i < params.length; i++)
 {
  var pos = params[i].indexOf("=");
  if (pos > 0)
  {
    var key = params[i].substring(0, pos);
    var val = params[i].substring(pos + 1);
    queryParams[key] = val;
  }
 }
 // params[0] is provider:media
 var p = params[0].split(":");
 
 for (var i = 0; i < mediaEngine.addons.length; i++)
 {
  var provider = mediaEngine.addons[i];
  if (p[0] == "all")
  {
    print("Its " + provider.toString());
    
    if (p[1].toLowerCase() == "media"){
      provider.searchMedia(queryParams);
      continue;
    }
    if (p[1].toLowerCase() == "mediacollection")
    {
     if (provider.searchCollection)
       provider.searchCollection(queryParams);
    continue;
    }
    continue;
  }
  if (p[0] == provider.toString().toLowerCase())
  {
    if (p[1] == "media"){
      provider.searchMedia(queryParams);
      return;
    }
    if (p[1] == "mediaCollection".toLowerCase())
    {
    if (provider.searchCollection)
       provider.searchCollection(queryParams);
    return;
    }
  }
 }
}

// the traditional updateSourceEvent
engine.updateSourceEvent = function(source)
{
  return true;
}