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
include GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/compiler_depend.make

# Include the progress variables for this target.
include GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/progress.make

# Include the compile flags for this target's objects.
include GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/flags.make

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/flags.make
GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o: /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/gramsreadoutsim.cc
GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/nevis/milne/files/apellot/GRAMS/GramsSim-work/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o -MF CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o.d -o CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o -c /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/gramsreadoutsim.cc

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.i"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/gramsreadoutsim.cc > CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.i

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.s"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/gramsreadoutsim.cc -o CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.s

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/flags.make
GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o: /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/src/AssignPixelID.cc
GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/nevis/milne/files/apellot/GRAMS/GramsSim-work/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o -MF CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o.d -o CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o -c /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/src/AssignPixelID.cc

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.i"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/src/AssignPixelID.cc > CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.i

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.s"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && /nevis/amsterdam/share/seligman/conda/grams/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim/src/AssignPixelID.cc -o CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.s

# Object files for target gramsreadoutsim
gramsreadoutsim_OBJECTS = \
"CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o" \
"CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o"

# External object files for target gramsreadoutsim
gramsreadoutsim_EXTERNAL_OBJECTS =

gramsreadoutsim: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/gramsreadoutsim.cc.o
gramsreadoutsim: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/src/AssignPixelID.cc.o
gramsreadoutsim: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/build.make
gramsreadoutsim: util/libGramsSimProjectUtilities.so
gramsreadoutsim: libDictionary.so
gramsreadoutsim: /nevis/amsterdam/share/seligman/conda/grams/lib/libxerces-c.so
gramsreadoutsim: GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/nevis/milne/files/apellot/GRAMS/GramsSim-work/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../gramsreadoutsim"
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gramsreadoutsim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/build: gramsreadoutsim
.PHONY : GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/build

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/clean:
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim && $(CMAKE_COMMAND) -P CMakeFiles/gramsreadoutsim.dir/cmake_clean.cmake
.PHONY : GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/clean

GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/depend:
	cd /nevis/milne/files/apellot/GRAMS/GramsSim-work && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nevis/milne/files/apellot/GRAMS/GramsSim /nevis/milne/files/apellot/GRAMS/GramsSim/GramsReadoutSim /nevis/milne/files/apellot/GRAMS/GramsSim-work /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim /nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : GramsReadoutSim/CMakeFiles/gramsreadoutsim.dir/depend
