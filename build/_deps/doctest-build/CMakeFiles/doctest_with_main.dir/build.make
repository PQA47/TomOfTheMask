# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\minhv\Desktop\tomb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\minhv\Desktop\tomb\build

# Include any dependencies generated for this target.
include _deps/doctest-build/CMakeFiles/doctest_with_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/doctest-build/CMakeFiles/doctest_with_main.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/doctest-build/CMakeFiles/doctest_with_main.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/doctest-build/CMakeFiles/doctest_with_main.dir/flags.make

_deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj: _deps/doctest-build/CMakeFiles/doctest_with_main.dir/flags.make
_deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj: _deps/doctest-build/CMakeFiles/doctest_with_main.dir/includes_CXX.rsp
_deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj: _deps/doctest-src/doctest/parts/doctest.cpp
_deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj: _deps/doctest-build/CMakeFiles/doctest_with_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\minhv\Desktop\tomb\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj"
	cd /d C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj -MF CMakeFiles\doctest_with_main.dir\doctest\parts\doctest.cpp.obj.d -o CMakeFiles\doctest_with_main.dir\doctest\parts\doctest.cpp.obj -c C:\Users\minhv\Desktop\tomb\build\_deps\doctest-src\doctest\parts\doctest.cpp

_deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.i"
	cd /d C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\minhv\Desktop\tomb\build\_deps\doctest-src\doctest\parts\doctest.cpp > CMakeFiles\doctest_with_main.dir\doctest\parts\doctest.cpp.i

_deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.s"
	cd /d C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build && C:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\minhv\Desktop\tomb\build\_deps\doctest-src\doctest\parts\doctest.cpp -o CMakeFiles\doctest_with_main.dir\doctest\parts\doctest.cpp.s

# Object files for target doctest_with_main
doctest_with_main_OBJECTS = \
"CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj"

# External object files for target doctest_with_main
doctest_with_main_EXTERNAL_OBJECTS =

_deps/doctest-build/libdoctest_with_main.a: _deps/doctest-build/CMakeFiles/doctest_with_main.dir/doctest/parts/doctest.cpp.obj
_deps/doctest-build/libdoctest_with_main.a: _deps/doctest-build/CMakeFiles/doctest_with_main.dir/build.make
_deps/doctest-build/libdoctest_with_main.a: _deps/doctest-build/CMakeFiles/doctest_with_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\minhv\Desktop\tomb\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdoctest_with_main.a"
	cd /d C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build && $(CMAKE_COMMAND) -P CMakeFiles\doctest_with_main.dir\cmake_clean_target.cmake
	cd /d C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\doctest_with_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/doctest-build/CMakeFiles/doctest_with_main.dir/build: _deps/doctest-build/libdoctest_with_main.a
.PHONY : _deps/doctest-build/CMakeFiles/doctest_with_main.dir/build

_deps/doctest-build/CMakeFiles/doctest_with_main.dir/clean:
	cd /d C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build && $(CMAKE_COMMAND) -P CMakeFiles\doctest_with_main.dir\cmake_clean.cmake
.PHONY : _deps/doctest-build/CMakeFiles/doctest_with_main.dir/clean

_deps/doctest-build/CMakeFiles/doctest_with_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\minhv\Desktop\tomb C:\Users\minhv\Desktop\tomb\build\_deps\doctest-src C:\Users\minhv\Desktop\tomb\build C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build C:\Users\minhv\Desktop\tomb\build\_deps\doctest-build\CMakeFiles\doctest_with_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/doctest-build/CMakeFiles/doctest_with_main.dir/depend

