# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Garyg\Documents\GitHub\APC-Injection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Garyg\Documents\GitHub\APC-Injection\build

# Include any dependencies generated for this target.
include CMakeFiles/APC-Injection.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/APC-Injection.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/APC-Injection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/APC-Injection.dir/flags.make

CMakeFiles/APC-Injection.dir/main.c.obj: CMakeFiles/APC-Injection.dir/flags.make
CMakeFiles/APC-Injection.dir/main.c.obj: C:/Users/Garyg/Documents/GitHub/APC-Injection/main.c
CMakeFiles/APC-Injection.dir/main.c.obj: CMakeFiles/APC-Injection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Garyg\Documents\GitHub\APC-Injection\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/APC-Injection.dir/main.c.obj"
	C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/APC-Injection.dir/main.c.obj -MF CMakeFiles\APC-Injection.dir\main.c.obj.d -o CMakeFiles\APC-Injection.dir\main.c.obj -c C:\Users\Garyg\Documents\GitHub\APC-Injection\main.c

CMakeFiles/APC-Injection.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/APC-Injection.dir/main.c.i"
	C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Garyg\Documents\GitHub\APC-Injection\main.c > CMakeFiles\APC-Injection.dir\main.c.i

CMakeFiles/APC-Injection.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/APC-Injection.dir/main.c.s"
	C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Garyg\Documents\GitHub\APC-Injection\main.c -o CMakeFiles\APC-Injection.dir\main.c.s

CMakeFiles/APC-Injection.dir/syscalls.asm.obj: CMakeFiles/APC-Injection.dir/flags.make
CMakeFiles/APC-Injection.dir/syscalls.asm.obj: C:/Users/Garyg/Documents/GitHub/APC-Injection/syscalls.asm
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Garyg\Documents\GitHub\APC-Injection\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM_MASM object CMakeFiles/APC-Injection.dir/syscalls.asm.obj"
	ml $(ASM_MASM_DEFINES) $(ASM_MASM_INCLUDES) $(ASM_MASM_FLAGS) -c -Fo CMakeFiles\APC-Injection.dir\syscalls.asm.obj C:\Users\Garyg\Documents\GitHub\APC-Injection\syscalls.asm

# Object files for target APC-Injection
APC__Injection_OBJECTS = \
"CMakeFiles/APC-Injection.dir/main.c.obj" \
"CMakeFiles/APC-Injection.dir/syscalls.asm.obj"

# External object files for target APC-Injection
APC__Injection_EXTERNAL_OBJECTS =

APC-Injection.exe: CMakeFiles/APC-Injection.dir/main.c.obj
APC-Injection.exe: CMakeFiles/APC-Injection.dir/syscalls.asm.obj
APC-Injection.exe: CMakeFiles/APC-Injection.dir/build.make
APC-Injection.exe: CMakeFiles/APC-Injection.dir/linkLibs.rsp
APC-Injection.exe: CMakeFiles/APC-Injection.dir/objects1.rsp
APC-Injection.exe: CMakeFiles/APC-Injection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Garyg\Documents\GitHub\APC-Injection\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable APC-Injection.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\APC-Injection.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/APC-Injection.dir/build: APC-Injection.exe
.PHONY : CMakeFiles/APC-Injection.dir/build

CMakeFiles/APC-Injection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\APC-Injection.dir\cmake_clean.cmake
.PHONY : CMakeFiles/APC-Injection.dir/clean

CMakeFiles/APC-Injection.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Garyg\Documents\GitHub\APC-Injection C:\Users\Garyg\Documents\GitHub\APC-Injection C:\Users\Garyg\Documents\GitHub\APC-Injection\build C:\Users\Garyg\Documents\GitHub\APC-Injection\build C:\Users\Garyg\Documents\GitHub\APC-Injection\build\CMakeFiles\APC-Injection.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/APC-Injection.dir/depend

