# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "/Users/salayna/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/salayna/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/salayna/Documents/dev/C_C++_Projects/svg_creator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SVGCreator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SVGCreator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SVGCreator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SVGCreator.dir/flags.make

CMakeFiles/SVGCreator.dir/main.cpp.o: CMakeFiles/SVGCreator.dir/flags.make
CMakeFiles/SVGCreator.dir/main.cpp.o: ../main.cpp
CMakeFiles/SVGCreator.dir/main.cpp.o: CMakeFiles/SVGCreator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SVGCreator.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SVGCreator.dir/main.cpp.o -MF CMakeFiles/SVGCreator.dir/main.cpp.o.d -o CMakeFiles/SVGCreator.dir/main.cpp.o -c /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/main.cpp

CMakeFiles/SVGCreator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SVGCreator.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/main.cpp > CMakeFiles/SVGCreator.dir/main.cpp.i

CMakeFiles/SVGCreator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SVGCreator.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/main.cpp -o CMakeFiles/SVGCreator.dir/main.cpp.s

# Object files for target SVGCreator
SVGCreator_OBJECTS = \
"CMakeFiles/SVGCreator.dir/main.cpp.o"

# External object files for target SVGCreator
SVGCreator_EXTERNAL_OBJECTS =

SVGCreator: CMakeFiles/SVGCreator.dir/main.cpp.o
SVGCreator: CMakeFiles/SVGCreator.dir/build.make
SVGCreator: CMakeFiles/SVGCreator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SVGCreator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SVGCreator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SVGCreator.dir/build: SVGCreator
.PHONY : CMakeFiles/SVGCreator.dir/build

CMakeFiles/SVGCreator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SVGCreator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SVGCreator.dir/clean

CMakeFiles/SVGCreator.dir/depend:
	cd /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/salayna/Documents/dev/C_C++_Projects/svg_creator /Users/salayna/Documents/dev/C_C++_Projects/svg_creator /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug /Users/salayna/Documents/dev/C_C++_Projects/svg_creator/cmake-build-debug/CMakeFiles/SVGCreator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SVGCreator.dir/depend

