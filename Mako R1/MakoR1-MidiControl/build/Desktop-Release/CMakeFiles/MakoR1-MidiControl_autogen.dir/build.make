# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release"

# Utility rule file for MakoR1-MidiControl_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/MakoR1-MidiControl_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MakoR1-MidiControl_autogen.dir/progress.make

CMakeFiles/MakoR1-MidiControl_autogen: MakoR1-MidiControl_autogen/timestamp

MakoR1-MidiControl_autogen/timestamp: /usr/lib/qt5/bin/moc
MakoR1-MidiControl_autogen/timestamp: /usr/lib/qt5/bin/uic
MakoR1-MidiControl_autogen/timestamp: CMakeFiles/MakoR1-MidiControl_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MakoR1-MidiControl"
	/usr/bin/cmake -E cmake_autogen "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release/CMakeFiles/MakoR1-MidiControl_autogen.dir/AutogenInfo.json" Release
	/usr/bin/cmake -E touch "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release/MakoR1-MidiControl_autogen/timestamp"

MakoR1-MidiControl_autogen: CMakeFiles/MakoR1-MidiControl_autogen
MakoR1-MidiControl_autogen: MakoR1-MidiControl_autogen/timestamp
MakoR1-MidiControl_autogen: CMakeFiles/MakoR1-MidiControl_autogen.dir/build.make
.PHONY : MakoR1-MidiControl_autogen

# Rule to build all files generated by this target.
CMakeFiles/MakoR1-MidiControl_autogen.dir/build: MakoR1-MidiControl_autogen
.PHONY : CMakeFiles/MakoR1-MidiControl_autogen.dir/build

CMakeFiles/MakoR1-MidiControl_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MakoR1-MidiControl_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MakoR1-MidiControl_autogen.dir/clean

CMakeFiles/MakoR1-MidiControl_autogen.dir/depend:
	cd "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl" "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl" "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release" "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release" "/mnt/hgfs/DevShare/Mako R1/MakoR1-MidiControl/build/Desktop-Release/CMakeFiles/MakoR1-MidiControl_autogen.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/MakoR1-MidiControl_autogen.dir/depend
