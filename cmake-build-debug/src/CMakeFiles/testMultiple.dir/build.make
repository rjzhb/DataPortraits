# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rjzhb/Project/CppModelProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rjzhb/Project/CppModelProject/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/testMultiple.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/testMultiple.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/testMultiple.dir/flags.make

src/CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.o: src/CMakeFiles/testMultiple.dir/flags.make
src/CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.o: ../Test/MultipleTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.o"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.o -c /home/rjzhb/Project/CppModelProject/Test/MultipleTest.cpp

src/CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.i"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/CppModelProject/Test/MultipleTest.cpp > CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.i

src/CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.s"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/CppModelProject/Test/MultipleTest.cpp -o CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.s

# Object files for target testMultiple
testMultiple_OBJECTS = \
"CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.o"

# External object files for target testMultiple
testMultiple_EXTERNAL_OBJECTS =

src/testMultiple: src/CMakeFiles/testMultiple.dir/__/Test/MultipleTest.cpp.o
src/testMultiple: src/CMakeFiles/testMultiple.dir/build.make
src/testMultiple: src/libCppModelProject_lib.a
src/testMultiple: /usr/lib/x86_64-linux-gnu/libgtest.a
src/testMultiple: /usr/lib/x86_64-linux-gnu/libgtest_main.a
src/testMultiple: src/CMakeFiles/testMultiple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testMultiple"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testMultiple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/testMultiple.dir/build: src/testMultiple

.PHONY : src/CMakeFiles/testMultiple.dir/build

src/CMakeFiles/testMultiple.dir/clean:
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/testMultiple.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/testMultiple.dir/clean

src/CMakeFiles/testMultiple.dir/depend:
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/CppModelProject /home/rjzhb/Project/CppModelProject/src /home/rjzhb/Project/CppModelProject/cmake-build-debug /home/rjzhb/Project/CppModelProject/cmake-build-debug/src /home/rjzhb/Project/CppModelProject/cmake-build-debug/src/CMakeFiles/testMultiple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/testMultiple.dir/depend

