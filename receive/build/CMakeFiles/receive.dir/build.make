# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/deven/Desktop/amqp/receive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/deven/Desktop/amqp/receive/build

# Include any dependencies generated for this target.
include CMakeFiles/receive.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/receive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/receive.dir/flags.make

CMakeFiles/receive.dir/receive.cpp.o: CMakeFiles/receive.dir/flags.make
CMakeFiles/receive.dir/receive.cpp.o: ../receive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deven/Desktop/amqp/receive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/receive.dir/receive.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/receive.dir/receive.cpp.o -c /home/deven/Desktop/amqp/receive/receive.cpp

CMakeFiles/receive.dir/receive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/receive.dir/receive.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deven/Desktop/amqp/receive/receive.cpp > CMakeFiles/receive.dir/receive.cpp.i

CMakeFiles/receive.dir/receive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/receive.dir/receive.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deven/Desktop/amqp/receive/receive.cpp -o CMakeFiles/receive.dir/receive.cpp.s

CMakeFiles/receive.dir/src/amqpConnect.cpp.o: CMakeFiles/receive.dir/flags.make
CMakeFiles/receive.dir/src/amqpConnect.cpp.o: ../src/amqpConnect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deven/Desktop/amqp/receive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/receive.dir/src/amqpConnect.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/receive.dir/src/amqpConnect.cpp.o -c /home/deven/Desktop/amqp/receive/src/amqpConnect.cpp

CMakeFiles/receive.dir/src/amqpConnect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/receive.dir/src/amqpConnect.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deven/Desktop/amqp/receive/src/amqpConnect.cpp > CMakeFiles/receive.dir/src/amqpConnect.cpp.i

CMakeFiles/receive.dir/src/amqpConnect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/receive.dir/src/amqpConnect.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deven/Desktop/amqp/receive/src/amqpConnect.cpp -o CMakeFiles/receive.dir/src/amqpConnect.cpp.s

CMakeFiles/receive.dir/src/streamBuffer.cpp.o: CMakeFiles/receive.dir/flags.make
CMakeFiles/receive.dir/src/streamBuffer.cpp.o: ../src/streamBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/deven/Desktop/amqp/receive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/receive.dir/src/streamBuffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/receive.dir/src/streamBuffer.cpp.o -c /home/deven/Desktop/amqp/receive/src/streamBuffer.cpp

CMakeFiles/receive.dir/src/streamBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/receive.dir/src/streamBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/deven/Desktop/amqp/receive/src/streamBuffer.cpp > CMakeFiles/receive.dir/src/streamBuffer.cpp.i

CMakeFiles/receive.dir/src/streamBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/receive.dir/src/streamBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/deven/Desktop/amqp/receive/src/streamBuffer.cpp -o CMakeFiles/receive.dir/src/streamBuffer.cpp.s

# Object files for target receive
receive_OBJECTS = \
"CMakeFiles/receive.dir/receive.cpp.o" \
"CMakeFiles/receive.dir/src/amqpConnect.cpp.o" \
"CMakeFiles/receive.dir/src/streamBuffer.cpp.o"

# External object files for target receive
receive_EXTERNAL_OBJECTS =

receive: CMakeFiles/receive.dir/receive.cpp.o
receive: CMakeFiles/receive.dir/src/amqpConnect.cpp.o
receive: CMakeFiles/receive.dir/src/streamBuffer.cpp.o
receive: CMakeFiles/receive.dir/build.make
receive: CMakeFiles/receive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/deven/Desktop/amqp/receive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable receive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/receive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/receive.dir/build: receive

.PHONY : CMakeFiles/receive.dir/build

CMakeFiles/receive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/receive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/receive.dir/clean

CMakeFiles/receive.dir/depend:
	cd /home/deven/Desktop/amqp/receive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/deven/Desktop/amqp/receive /home/deven/Desktop/amqp/receive /home/deven/Desktop/amqp/receive/build /home/deven/Desktop/amqp/receive/build /home/deven/Desktop/amqp/receive/build/CMakeFiles/receive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/receive.dir/depend

