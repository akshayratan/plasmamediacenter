# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/akshay/PMC/plasma-mediacenter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akshay/PMC/plasma-mediacenter/build

# Utility rule file for plasma-mediacenter_automoc.

# Include the progress variables for this target.
include shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/progress.make

shells/newshell/CMakeFiles/plasma-mediacenter_automoc:
	cd /home/akshay/PMC/plasma-mediacenter/build/shells/newshell && /usr/bin/automoc4 /home/akshay/PMC/plasma-mediacenter/build/shells/newshell/plasma-mediacenter_automoc.cpp /home/akshay/PMC/plasma-mediacenter/shells/newshell /home/akshay/PMC/plasma-mediacenter/build/shells/newshell /usr/bin/moc-qt4 /usr/bin/cmake

plasma-mediacenter_automoc: shells/newshell/CMakeFiles/plasma-mediacenter_automoc
plasma-mediacenter_automoc: shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/build.make
.PHONY : plasma-mediacenter_automoc

# Rule to build all files generated by this target.
shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/build: plasma-mediacenter_automoc
.PHONY : shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/build

shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/clean:
	cd /home/akshay/PMC/plasma-mediacenter/build/shells/newshell && $(CMAKE_COMMAND) -P CMakeFiles/plasma-mediacenter_automoc.dir/cmake_clean.cmake
.PHONY : shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/clean

shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/depend:
	cd /home/akshay/PMC/plasma-mediacenter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akshay/PMC/plasma-mediacenter /home/akshay/PMC/plasma-mediacenter/shells/newshell /home/akshay/PMC/plasma-mediacenter/build /home/akshay/PMC/plasma-mediacenter/build/shells/newshell /home/akshay/PMC/plasma-mediacenter/build/shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shells/newshell/CMakeFiles/plasma-mediacenter_automoc.dir/depend
