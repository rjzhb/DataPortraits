# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/rjzhb/Project/DataPortraits

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rjzhb/Project/DataPortraits/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/dataset_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/dataset_test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/dataset_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/dataset_test.dir/flags.make

test/CMakeFiles/dataset_test.dir/dataset_test.cpp.o: test/CMakeFiles/dataset_test.dir/flags.make
test/CMakeFiles/dataset_test.dir/dataset_test.cpp.o: ../test/dataset_test.cpp
test/CMakeFiles/dataset_test.dir/dataset_test.cpp.o: test/CMakeFiles/dataset_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/dataset_test.dir/dataset_test.cpp.o"
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/dataset_test.dir/dataset_test.cpp.o -MF CMakeFiles/dataset_test.dir/dataset_test.cpp.o.d -o CMakeFiles/dataset_test.dir/dataset_test.cpp.o -c /home/rjzhb/Project/DataPortraits/test/dataset_test.cpp

test/CMakeFiles/dataset_test.dir/dataset_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dataset_test.dir/dataset_test.cpp.i"
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DataPortraits/test/dataset_test.cpp > CMakeFiles/dataset_test.dir/dataset_test.cpp.i

test/CMakeFiles/dataset_test.dir/dataset_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dataset_test.dir/dataset_test.cpp.s"
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DataPortraits/test/dataset_test.cpp -o CMakeFiles/dataset_test.dir/dataset_test.cpp.s

# Object files for target dataset_test
dataset_test_OBJECTS = \
"CMakeFiles/dataset_test.dir/dataset_test.cpp.o"

# External object files for target dataset_test
dataset_test_EXTERNAL_OBJECTS =

test/dataset_test: test/CMakeFiles/dataset_test.dir/dataset_test.cpp.o
test/dataset_test: test/CMakeFiles/dataset_test.dir/build.make
test/dataset_test: src/libDataPortraits_lib.a
test/dataset_test: test/CMakeFiles/dataset_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dataset_test"
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dataset_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/dataset_test.dir/build: test/dataset_test
.PHONY : test/CMakeFiles/dataset_test.dir/build

test/CMakeFiles/dataset_test.dir/clean:
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/dataset_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/dataset_test.dir/clean

test/CMakeFiles/dataset_test.dir/depend:
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/DataPortraits /home/rjzhb/Project/DataPortraits/test /home/rjzhb/Project/DataPortraits/cmake-build-debug /home/rjzhb/Project/DataPortraits/cmake-build-debug/test /home/rjzhb/Project/DataPortraits/cmake-build-debug/test/CMakeFiles/dataset_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/dataset_test.dir/depend
