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
include src/CMakeFiles/CppModelProject_lib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/CppModelProject_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/CppModelProject_lib.dir/flags.make

src/CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.o: src/CMakeFiles/CppModelProject_lib.dir/flags.make
src/CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.o: ../src/MultipleManager/MultipleManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.o"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.o -c /home/rjzhb/Project/CppModelProject/src/MultipleManager/MultipleManager.cpp

src/CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.i"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/CppModelProject/src/MultipleManager/MultipleManager.cpp > CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.i

src/CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.s"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/CppModelProject/src/MultipleManager/MultipleManager.cpp -o CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.s

src/CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.o: src/CMakeFiles/CppModelProject_lib.dir/flags.make
src/CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.o: ../src/MyClass/MyClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.o"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.o -c /home/rjzhb/Project/CppModelProject/src/MyClass/MyClass.cpp

src/CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.i"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/CppModelProject/src/MyClass/MyClass.cpp > CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.i

src/CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.s"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/CppModelProject/src/MyClass/MyClass.cpp -o CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.s

# Object files for target CppModelProject_lib
CppModelProject_lib_OBJECTS = \
"CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.o" \
"CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.o"

# External object files for target CppModelProject_lib
CppModelProject_lib_EXTERNAL_OBJECTS =

src/libCppModelProject_lib.a: src/CMakeFiles/CppModelProject_lib.dir/MultipleManager/MultipleManager.cpp.o
src/libCppModelProject_lib.a: src/CMakeFiles/CppModelProject_lib.dir/MyClass/MyClass.cpp.o
src/libCppModelProject_lib.a: src/CMakeFiles/CppModelProject_lib.dir/build.make
src/libCppModelProject_lib.a: src/CMakeFiles/CppModelProject_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/CppModelProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libCppModelProject_lib.a"
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/CppModelProject_lib.dir/cmake_clean_target.cmake
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppModelProject_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/CppModelProject_lib.dir/build: src/libCppModelProject_lib.a

.PHONY : src/CMakeFiles/CppModelProject_lib.dir/build

src/CMakeFiles/CppModelProject_lib.dir/clean:
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/CppModelProject_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/CppModelProject_lib.dir/clean

src/CMakeFiles/CppModelProject_lib.dir/depend:
	cd /home/rjzhb/Project/CppModelProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/CppModelProject /home/rjzhb/Project/CppModelProject/src /home/rjzhb/Project/CppModelProject/cmake-build-debug /home/rjzhb/Project/CppModelProject/cmake-build-debug/src /home/rjzhb/Project/CppModelProject/cmake-build-debug/src/CMakeFiles/CppModelProject_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/CppModelProject_lib.dir/depend
