# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tests.dir/flags.make

tests/CMakeFiles/tests.dir/tests.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/tests.cpp.o: /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/tests.cpp
tests/CMakeFiles/tests.dir/tests.cpp.o: tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/tests.dir/tests.cpp.o"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/tests.dir/tests.cpp.o -MF CMakeFiles/tests.dir/tests.cpp.o.d -o CMakeFiles/tests.dir/tests.cpp.o -c /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/tests.cpp

tests/CMakeFiles/tests.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests.cpp.i"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/tests.cpp > CMakeFiles/tests.dir/tests.cpp.i

tests/CMakeFiles/tests.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests.cpp.s"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/tests.cpp -o CMakeFiles/tests.dir/tests.cpp.s

tests/CMakeFiles/tests.dir/slinked_list_t.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/slinked_list_t.cpp.o: /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/slinked_list_t.cpp
tests/CMakeFiles/tests.dir/slinked_list_t.cpp.o: tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/tests.dir/slinked_list_t.cpp.o"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/tests.dir/slinked_list_t.cpp.o -MF CMakeFiles/tests.dir/slinked_list_t.cpp.o.d -o CMakeFiles/tests.dir/slinked_list_t.cpp.o -c /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/slinked_list_t.cpp

tests/CMakeFiles/tests.dir/slinked_list_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/slinked_list_t.cpp.i"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/slinked_list_t.cpp > CMakeFiles/tests.dir/slinked_list_t.cpp.i

tests/CMakeFiles/tests.dir/slinked_list_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/slinked_list_t.cpp.s"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests/slinked_list_t.cpp -o CMakeFiles/tests.dir/slinked_list_t.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/tests.cpp.o" \
"CMakeFiles/tests.dir/slinked_list_t.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

app/tests: tests/CMakeFiles/tests.dir/tests.cpp.o
app/tests: tests/CMakeFiles/tests.dir/slinked_list_t.cpp.o
app/tests: tests/CMakeFiles/tests.dir/build.make
app/tests: tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../app/tests"
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && /usr/bin/cmake -D TEST_TARGET=tests -D TEST_EXECUTABLE=/home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/app/tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=tests_TESTS -D TEST_REPORTER= -D TEST_OUTPUT_DIR= -D TEST_OUTPUT_PREFIX= -D TEST_OUTPUT_SUFFIX= -D CTEST_FILE=/home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests/tests_tests-b12d07c.cmake -P /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/cmake/CatchAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/tests.dir/build: app/tests
.PHONY : tests/CMakeFiles/tests.dir/build

tests/CMakeFiles/tests.dir/clean:
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tests.dir/clean

tests/CMakeFiles/tests.dir/depend:
	cd /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/tests /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests /home/ion-hz/Develop/cpp/tutorial/algos-datastructures-cpp/build/tests/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/tests.dir/depend

