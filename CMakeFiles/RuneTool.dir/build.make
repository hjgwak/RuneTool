# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.5.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.5.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Kelvin/Programming/gitHub/RuneTool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Kelvin/Programming/gitHub/RuneTool

# Include any dependencies generated for this target.
include CMakeFiles/RuneTool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RuneTool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RuneTool.dir/flags.make

CMakeFiles/RuneTool.dir/src/main.cpp.o: CMakeFiles/RuneTool.dir/flags.make
CMakeFiles/RuneTool.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RuneTool.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RuneTool.dir/src/main.cpp.o -c /Users/Kelvin/Programming/gitHub/RuneTool/src/main.cpp

CMakeFiles/RuneTool.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RuneTool.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Kelvin/Programming/gitHub/RuneTool/src/main.cpp > CMakeFiles/RuneTool.dir/src/main.cpp.i

CMakeFiles/RuneTool.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RuneTool.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Kelvin/Programming/gitHub/RuneTool/src/main.cpp -o CMakeFiles/RuneTool.dir/src/main.cpp.s

CMakeFiles/RuneTool.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/RuneTool.dir/src/main.cpp.o.requires

CMakeFiles/RuneTool.dir/src/main.cpp.o.provides: CMakeFiles/RuneTool.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/RuneTool.dir/build.make CMakeFiles/RuneTool.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/RuneTool.dir/src/main.cpp.o.provides

CMakeFiles/RuneTool.dir/src/main.cpp.o.provides.build: CMakeFiles/RuneTool.dir/src/main.cpp.o


CMakeFiles/RuneTool.dir/src/Rune.cpp.o: CMakeFiles/RuneTool.dir/flags.make
CMakeFiles/RuneTool.dir/src/Rune.cpp.o: src/Rune.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RuneTool.dir/src/Rune.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RuneTool.dir/src/Rune.cpp.o -c /Users/Kelvin/Programming/gitHub/RuneTool/src/Rune.cpp

CMakeFiles/RuneTool.dir/src/Rune.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RuneTool.dir/src/Rune.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Kelvin/Programming/gitHub/RuneTool/src/Rune.cpp > CMakeFiles/RuneTool.dir/src/Rune.cpp.i

CMakeFiles/RuneTool.dir/src/Rune.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RuneTool.dir/src/Rune.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Kelvin/Programming/gitHub/RuneTool/src/Rune.cpp -o CMakeFiles/RuneTool.dir/src/Rune.cpp.s

CMakeFiles/RuneTool.dir/src/Rune.cpp.o.requires:

.PHONY : CMakeFiles/RuneTool.dir/src/Rune.cpp.o.requires

CMakeFiles/RuneTool.dir/src/Rune.cpp.o.provides: CMakeFiles/RuneTool.dir/src/Rune.cpp.o.requires
	$(MAKE) -f CMakeFiles/RuneTool.dir/build.make CMakeFiles/RuneTool.dir/src/Rune.cpp.o.provides.build
.PHONY : CMakeFiles/RuneTool.dir/src/Rune.cpp.o.provides

CMakeFiles/RuneTool.dir/src/Rune.cpp.o.provides.build: CMakeFiles/RuneTool.dir/src/Rune.cpp.o


CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o: CMakeFiles/RuneTool.dir/flags.make
CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o: src/RuneIO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o -c /Users/Kelvin/Programming/gitHub/RuneTool/src/RuneIO.cpp

CMakeFiles/RuneTool.dir/src/RuneIO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RuneTool.dir/src/RuneIO.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Kelvin/Programming/gitHub/RuneTool/src/RuneIO.cpp > CMakeFiles/RuneTool.dir/src/RuneIO.cpp.i

CMakeFiles/RuneTool.dir/src/RuneIO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RuneTool.dir/src/RuneIO.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Kelvin/Programming/gitHub/RuneTool/src/RuneIO.cpp -o CMakeFiles/RuneTool.dir/src/RuneIO.cpp.s

CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.requires:

.PHONY : CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.requires

CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.provides: CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.requires
	$(MAKE) -f CMakeFiles/RuneTool.dir/build.make CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.provides.build
.PHONY : CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.provides

CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.provides.build: CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o


CMakeFiles/RuneTool.dir/src/Error.cpp.o: CMakeFiles/RuneTool.dir/flags.make
CMakeFiles/RuneTool.dir/src/Error.cpp.o: src/Error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RuneTool.dir/src/Error.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RuneTool.dir/src/Error.cpp.o -c /Users/Kelvin/Programming/gitHub/RuneTool/src/Error.cpp

CMakeFiles/RuneTool.dir/src/Error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RuneTool.dir/src/Error.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Kelvin/Programming/gitHub/RuneTool/src/Error.cpp > CMakeFiles/RuneTool.dir/src/Error.cpp.i

CMakeFiles/RuneTool.dir/src/Error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RuneTool.dir/src/Error.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Kelvin/Programming/gitHub/RuneTool/src/Error.cpp -o CMakeFiles/RuneTool.dir/src/Error.cpp.s

CMakeFiles/RuneTool.dir/src/Error.cpp.o.requires:

.PHONY : CMakeFiles/RuneTool.dir/src/Error.cpp.o.requires

CMakeFiles/RuneTool.dir/src/Error.cpp.o.provides: CMakeFiles/RuneTool.dir/src/Error.cpp.o.requires
	$(MAKE) -f CMakeFiles/RuneTool.dir/build.make CMakeFiles/RuneTool.dir/src/Error.cpp.o.provides.build
.PHONY : CMakeFiles/RuneTool.dir/src/Error.cpp.o.provides

CMakeFiles/RuneTool.dir/src/Error.cpp.o.provides.build: CMakeFiles/RuneTool.dir/src/Error.cpp.o


CMakeFiles/RuneTool.dir/src/programs.cpp.o: CMakeFiles/RuneTool.dir/flags.make
CMakeFiles/RuneTool.dir/src/programs.cpp.o: src/programs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RuneTool.dir/src/programs.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RuneTool.dir/src/programs.cpp.o -c /Users/Kelvin/Programming/gitHub/RuneTool/src/programs.cpp

CMakeFiles/RuneTool.dir/src/programs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RuneTool.dir/src/programs.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Kelvin/Programming/gitHub/RuneTool/src/programs.cpp > CMakeFiles/RuneTool.dir/src/programs.cpp.i

CMakeFiles/RuneTool.dir/src/programs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RuneTool.dir/src/programs.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Kelvin/Programming/gitHub/RuneTool/src/programs.cpp -o CMakeFiles/RuneTool.dir/src/programs.cpp.s

CMakeFiles/RuneTool.dir/src/programs.cpp.o.requires:

.PHONY : CMakeFiles/RuneTool.dir/src/programs.cpp.o.requires

CMakeFiles/RuneTool.dir/src/programs.cpp.o.provides: CMakeFiles/RuneTool.dir/src/programs.cpp.o.requires
	$(MAKE) -f CMakeFiles/RuneTool.dir/build.make CMakeFiles/RuneTool.dir/src/programs.cpp.o.provides.build
.PHONY : CMakeFiles/RuneTool.dir/src/programs.cpp.o.provides

CMakeFiles/RuneTool.dir/src/programs.cpp.o.provides.build: CMakeFiles/RuneTool.dir/src/programs.cpp.o


# Object files for target RuneTool
RuneTool_OBJECTS = \
"CMakeFiles/RuneTool.dir/src/main.cpp.o" \
"CMakeFiles/RuneTool.dir/src/Rune.cpp.o" \
"CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o" \
"CMakeFiles/RuneTool.dir/src/Error.cpp.o" \
"CMakeFiles/RuneTool.dir/src/programs.cpp.o"

# External object files for target RuneTool
RuneTool_EXTERNAL_OBJECTS =

RuneTool: CMakeFiles/RuneTool.dir/src/main.cpp.o
RuneTool: CMakeFiles/RuneTool.dir/src/Rune.cpp.o
RuneTool: CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o
RuneTool: CMakeFiles/RuneTool.dir/src/Error.cpp.o
RuneTool: CMakeFiles/RuneTool.dir/src/programs.cpp.o
RuneTool: CMakeFiles/RuneTool.dir/build.make
RuneTool: CMakeFiles/RuneTool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable RuneTool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RuneTool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RuneTool.dir/build: RuneTool

.PHONY : CMakeFiles/RuneTool.dir/build

CMakeFiles/RuneTool.dir/requires: CMakeFiles/RuneTool.dir/src/main.cpp.o.requires
CMakeFiles/RuneTool.dir/requires: CMakeFiles/RuneTool.dir/src/Rune.cpp.o.requires
CMakeFiles/RuneTool.dir/requires: CMakeFiles/RuneTool.dir/src/RuneIO.cpp.o.requires
CMakeFiles/RuneTool.dir/requires: CMakeFiles/RuneTool.dir/src/Error.cpp.o.requires
CMakeFiles/RuneTool.dir/requires: CMakeFiles/RuneTool.dir/src/programs.cpp.o.requires

.PHONY : CMakeFiles/RuneTool.dir/requires

CMakeFiles/RuneTool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RuneTool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RuneTool.dir/clean

CMakeFiles/RuneTool.dir/depend:
	cd /Users/Kelvin/Programming/gitHub/RuneTool && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Kelvin/Programming/gitHub/RuneTool /Users/Kelvin/Programming/gitHub/RuneTool /Users/Kelvin/Programming/gitHub/RuneTool /Users/Kelvin/Programming/gitHub/RuneTool /Users/Kelvin/Programming/gitHub/RuneTool/CMakeFiles/RuneTool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RuneTool.dir/depend

