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
include CMakeFiles/test_MyClass.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_MyClass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_MyClass.dir/flags.make

CMakeFiles/test_MyClass.dir/Test/test.cpp.o: CMakeFiles/test_MyClass.dir/flags.make
CMakeFiles/test_MyClass.dir/Test/test.cpp.o: ../Test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_MyClass.dir/Test/test.cpp.o"
	/usr/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_MyClass.dir/Test/test.cpp.o -c /home/rjzhb/Project/CppModelProject/Test/test.cpp

CMakeFiles/test_MyClass.dir/Test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_MyClass.dir/Test/test.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/CppModelProject/Test/test.cpp > CMakeFiles/test_MyClass.dir/Test/test.cpp.i

CMakeFiles/test_MyClass.dir/Test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_MyClass.dir/Test/test.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/CppModelProject/Test/test.cpp -o CMakeFiles/test_MyClass.dir/Test/test.cpp.s

# Object files for target test_MyClass
test_MyClass_OBJECTS = \
"CMakeFiles/test_MyClass.dir/Test/test.cpp.o"

# External object files for target test_MyClass
test_MyClass_EXTERNAL_OBJECTS =

test_MyClass: CMakeFiles/test_MyClass.dir/Test/test.cpp.o
test_MyClass: CMakeFiles/test_MyClass.dir/build.make
test_MyClass: /usr/lib/x86_64-linux-gnu/libgtest.a
test_MyClass: /usr/lib/x86_64-linux-gnu/libgtest_main.a
test_MyClass: CMakeFiles/test_MyClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_MyClass"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_MyClass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_MyClass.dir/build: test_MyClass

.PHONY : CMakeFiles/test_MyClass.dir/build

CMakeFiles/test_MyClass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_MyClass.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_MyClass.dir/clean

CMakeFiles/test_MyClass.dir/depend:
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/CppModelProject /home/rjzhb/Project/CppModelProject /home/rjzhb/Project/CppModelProject/cmake-build-debug /home/rjzhb/Project/CppModelProject/cmake-build-debug /home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles/test_MyClass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_MyClass.dir/depend

