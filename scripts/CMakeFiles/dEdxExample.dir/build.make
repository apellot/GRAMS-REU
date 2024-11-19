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
CMAKE_COMMAND = /nevis/amsterdam/share/seligman/conda/grams/bin/cmake

# The command to remove a file.
RM = /nevis/amsterdam/share/seligman/conda/grams/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nevis/milne/files/apellot/GRAMS/GramsSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nevis/milne/files/apellot/GRAMS/GramsSim-work

# Include any dependencies generated for this target.
include scripts/CMakeFiles/dEdxExample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scripts/CMakeFiles/dEdxExample.dir/compiler_depend.make

# Include the progress variables for this target.
include scripts/CMakeFiles/dEdxExample.dir/progress.make

# Include the compile flags for this target's objects.
include scripts/CMakeFiles/dEdxExample.dir/flags.make

scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.o: scripts/CMakeFiles/dEdxExample.dir/flags.make
scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.o: /nevis/milne/files/apellot/GRAMS/GramsSim/scripts/dEdxExample.cc
scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.o: scripts/CMakeFiles/dEdxExample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/nevis/milne/files/apellot/GRAMS/GramsSim-work/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.o"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.o -MF CMakeFiles/dEdxExample.dir/dEdxExample.cc.o.d -o CMakeFiles/dEdxExample.dir/dEdxExample.cc.o -c /nevis/milne/files/apellot/GRAMS/GramsSim/scripts/dEdxExample.cc

scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dEdxExample.dir/dEdxExample.cc.i"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nevis/milne/files/apellot/GRAMS/GramsSim/scripts/dEdxExample.cc > CMakeFiles/dEdxExample.dir/dEdxExample.cc.i

scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dEdxExample.dir/dEdxExample.cc.s"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nevis/milne/files/apellot/GRAMS/GramsSim/scripts/dEdxExample.cc -o CMakeFiles/dEdxExample.dir/dEdxExample.cc.s

# Object files for target dEdxExample
dEdxExample_OBJECTS = \
"CMakeFiles/dEdxExample.dir/dEdxExample.cc.o"

# External object files for target dEdxExample
dEdxExample_EXTERNAL_OBJECTS =

bin/dEdxExample: scripts/CMakeFiles/dEdxExample.dir/dEdxExample.cc.o
bin/dEdxExample: scripts/CMakeFiles/dEdxExample.dir/build.make
bin/dEdxExample: util/libGramsSimProjectUtilities.so
bin/dEdxExample: libDictionary.so
bin/dEdxExample: /nevis/amsterdam/share/seligman/conda/grams/lib/libHepMC3.so
bin/dEdxExample: /nevis/amsterdam/share/seligman/conda/grams/lib/libHepMC3search.so
bin/dEdxExample: /nevis/amsterdam/share/seligman/conda/grams/lib/libxerces-c.so
bin/dEdxExample: scripts/CMakeFiles/dEdxExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/nevis/milne/files/apellot/GRAMS/GramsSim-work/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/dEdxExample"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dEdxExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scripts/CMakeFiles/dEdxExample.dir/build: bin/dEdxExample
.PHONY : scripts/CMakeFiles/dEdxExample.dir/build

scripts/CMakeFiles/dEdxExample.dir/clean:
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts && $(CMAKE_COMMAND) -P CMakeFiles/dEdxExample.dir/cmake_clean.cmake
.PHONY : scripts/CMakeFiles/dEdxExample.dir/clean

scripts/CMakeFiles/dEdxExample.dir/depend:
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nevis/milne/files/apellot/GRAMS/GramsSim /nevis/milne/files/apellot/GRAMS/GramsSim/scripts /nevis/milne/files/apellot/GRAMS/GramsSim-work /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts /nevis/milne/files/apellot/GRAMS/GramsSim-work/scripts/CMakeFiles/dEdxExample.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : scripts/CMakeFiles/dEdxExample.dir/depend

