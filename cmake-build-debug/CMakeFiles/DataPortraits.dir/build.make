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
CMAKE_SOURCE_DIR = /home/rjzhb/Project/DataPortraits

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rjzhb/Project/DataPortraits/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DataPortraits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataPortraits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataPortraits.dir/flags.make

CMakeFiles/DataPortraits.dir/benchmark.cpp.o: CMakeFiles/DataPortraits.dir/flags.make
CMakeFiles/DataPortraits.dir/benchmark.cpp.o: ../benchmark.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataPortraits.dir/benchmark.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataPortraits.dir/benchmark.cpp.o -c /home/rjzhb/Project/DataPortraits/benchmark.cpp

CMakeFiles/DataPortraits.dir/benchmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataPortraits.dir/benchmark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DataPortraits/benchmark.cpp > CMakeFiles/DataPortraits.dir/benchmark.cpp.i

CMakeFiles/DataPortraits.dir/benchmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataPortraits.dir/benchmark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DataPortraits/benchmark.cpp -o CMakeFiles/DataPortraits.dir/benchmark.cpp.s

CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.o: CMakeFiles/DataPortraits.dir/flags.make
CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.o: ../src/filter/bloom_filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.o -c /home/rjzhb/Project/DataPortraits/src/filter/bloom_filter.cpp

CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DataPortraits/src/filter/bloom_filter.cpp > CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.i

CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DataPortraits/src/filter/bloom_filter.cpp -o CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.s

CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.o: CMakeFiles/DataPortraits.dir/flags.make
CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.o: ../src/filter/strided_bloom_filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.o -c /home/rjzhb/Project/DataPortraits/src/filter/strided_bloom_filter.cpp

CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DataPortraits/src/filter/strided_bloom_filter.cpp > CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.i

CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DataPortraits/src/filter/strided_bloom_filter.cpp -o CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.s

CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.o: CMakeFiles/DataPortraits.dir/flags.make
CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.o: ../src/dataloader/dataloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.o -c /home/rjzhb/Project/DataPortraits/src/dataloader/dataloader.cpp

CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rjzhb/Project/DataPortraits/src/dataloader/dataloader.cpp > CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.i

CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rjzhb/Project/DataPortraits/src/dataloader/dataloader.cpp -o CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.s

# Object files for target DataPortraits
DataPortraits_OBJECTS = \
"CMakeFiles/DataPortraits.dir/benchmark.cpp.o" \
"CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.o" \
"CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.o" \
"CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.o"

# External object files for target DataPortraits
DataPortraits_EXTERNAL_OBJECTS =

DataPortraits: CMakeFiles/DataPortraits.dir/benchmark.cpp.o
DataPortraits: CMakeFiles/DataPortraits.dir/src/filter/bloom_filter.cpp.o
DataPortraits: CMakeFiles/DataPortraits.dir/src/filter/strided_bloom_filter.cpp.o
DataPortraits: CMakeFiles/DataPortraits.dir/src/dataloader/dataloader.cpp.o
DataPortraits: CMakeFiles/DataPortraits.dir/build.make
DataPortraits: CMakeFiles/DataPortraits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DataPortraits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataPortraits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataPortraits.dir/build: DataPortraits

.PHONY : CMakeFiles/DataPortraits.dir/build

CMakeFiles/DataPortraits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataPortraits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataPortraits.dir/clean

CMakeFiles/DataPortraits.dir/depend:
	cd /home/rjzhb/Project/DataPortraits/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjzhb/Project/DataPortraits /home/rjzhb/Project/DataPortraits /home/rjzhb/Project/DataPortraits/cmake-build-debug /home/rjzhb/Project/DataPortraits/cmake-build-debug /home/rjzhb/Project/DataPortraits/cmake-build-debug/CMakeFiles/DataPortraits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataPortraits.dir/depend

