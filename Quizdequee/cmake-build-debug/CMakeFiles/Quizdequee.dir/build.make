# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/ryanj/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/ryanj/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Quizdequee.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Quizdequee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Quizdequee.dir/flags.make

CMakeFiles/Quizdequee.dir/main.cpp.o: CMakeFiles/Quizdequee.dir/flags.make
CMakeFiles/Quizdequee.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Quizdequee.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quizdequee.dir/main.cpp.o -c /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/main.cpp

CMakeFiles/Quizdequee.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quizdequee.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/main.cpp > CMakeFiles/Quizdequee.dir/main.cpp.i

CMakeFiles/Quizdequee.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quizdequee.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/main.cpp -o CMakeFiles/Quizdequee.dir/main.cpp.s

# Object files for target Quizdequee
Quizdequee_OBJECTS = \
"CMakeFiles/Quizdequee.dir/main.cpp.o"

# External object files for target Quizdequee
Quizdequee_EXTERNAL_OBJECTS =

Quizdequee.exe: CMakeFiles/Quizdequee.dir/main.cpp.o
Quizdequee.exe: CMakeFiles/Quizdequee.dir/build.make
Quizdequee.exe: CMakeFiles/Quizdequee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Quizdequee.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Quizdequee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Quizdequee.dir/build: Quizdequee.exe

.PHONY : CMakeFiles/Quizdequee.dir/build

CMakeFiles/Quizdequee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Quizdequee.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Quizdequee.dir/clean

CMakeFiles/Quizdequee.dir/depend:
	cd /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug /cygdrive/c/Users/ryanj/OneDrive/221/Quizdequee/cmake-build-debug/CMakeFiles/Quizdequee.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Quizdequee.dir/depend
