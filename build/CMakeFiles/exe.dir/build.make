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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nareka/Desktop/GITHUBProjects/OpenCV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nareka/Desktop/GITHUBProjects/OpenCV/build

# Include any dependencies generated for this target.
include CMakeFiles/exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exe.dir/flags.make

CMakeFiles/exe.dir/src/src/main.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/src/main.cpp.o: ../src/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exe.dir/src/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exe.dir/src/src/main.cpp.o -c /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/main.cpp

CMakeFiles/exe.dir/src/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/main.cpp > CMakeFiles/exe.dir/src/src/main.cpp.i

CMakeFiles/exe.dir/src/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/main.cpp -o CMakeFiles/exe.dir/src/src/main.cpp.s

CMakeFiles/exe.dir/src/src/CVDecoder.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/src/CVDecoder.cpp.o: ../src/src/CVDecoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exe.dir/src/src/CVDecoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exe.dir/src/src/CVDecoder.cpp.o -c /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/CVDecoder.cpp

CMakeFiles/exe.dir/src/src/CVDecoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/src/CVDecoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/CVDecoder.cpp > CMakeFiles/exe.dir/src/src/CVDecoder.cpp.i

CMakeFiles/exe.dir/src/src/CVDecoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/src/CVDecoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/CVDecoder.cpp -o CMakeFiles/exe.dir/src/src/CVDecoder.cpp.s

CMakeFiles/exe.dir/src/src/CVEncoder.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/src/CVEncoder.cpp.o: ../src/src/CVEncoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/exe.dir/src/src/CVEncoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exe.dir/src/src/CVEncoder.cpp.o -c /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/CVEncoder.cpp

CMakeFiles/exe.dir/src/src/CVEncoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/src/CVEncoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/CVEncoder.cpp > CMakeFiles/exe.dir/src/src/CVEncoder.cpp.i

CMakeFiles/exe.dir/src/src/CVEncoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/src/CVEncoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/CVEncoder.cpp -o CMakeFiles/exe.dir/src/src/CVEncoder.cpp.s

CMakeFiles/exe.dir/src/src/Filters.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/src/Filters.cpp.o: ../src/src/Filters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/exe.dir/src/src/Filters.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exe.dir/src/src/Filters.cpp.o -c /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/Filters.cpp

CMakeFiles/exe.dir/src/src/Filters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/src/Filters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/Filters.cpp > CMakeFiles/exe.dir/src/src/Filters.cpp.i

CMakeFiles/exe.dir/src/src/Filters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/src/Filters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/Filters.cpp -o CMakeFiles/exe.dir/src/src/Filters.cpp.s

CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.o: CMakeFiles/exe.dir/flags.make
CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.o: ../src/src/VideoOverlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.o -c /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/VideoOverlayer.cpp

CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/VideoOverlayer.cpp > CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.i

CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nareka/Desktop/GITHUBProjects/OpenCV/src/src/VideoOverlayer.cpp -o CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.s

# Object files for target exe
exe_OBJECTS = \
"CMakeFiles/exe.dir/src/src/main.cpp.o" \
"CMakeFiles/exe.dir/src/src/CVDecoder.cpp.o" \
"CMakeFiles/exe.dir/src/src/CVEncoder.cpp.o" \
"CMakeFiles/exe.dir/src/src/Filters.cpp.o" \
"CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.o"

# External object files for target exe
exe_EXTERNAL_OBJECTS =

../bin/exe: CMakeFiles/exe.dir/src/src/main.cpp.o
../bin/exe: CMakeFiles/exe.dir/src/src/CVDecoder.cpp.o
../bin/exe: CMakeFiles/exe.dir/src/src/CVEncoder.cpp.o
../bin/exe: CMakeFiles/exe.dir/src/src/Filters.cpp.o
../bin/exe: CMakeFiles/exe.dir/src/src/VideoOverlayer.cpp.o
../bin/exe: CMakeFiles/exe.dir/build.make
../bin/exe: Utilities/install/lib/libUTILITIES.a
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_tracking.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_core.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_flann.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_imgproc.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_ml.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_photo.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_imgcodecs.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_video.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_videoio.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_highgui.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_features2d.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_calib3d.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_objdetect.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_stitching.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_dnn.so
../bin/exe: ../external/Linux-x-86-64/OpenCV/lib/libopencv_bgsegm.so
../bin/exe: CMakeFiles/exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exe.dir/build: ../bin/exe

.PHONY : CMakeFiles/exe.dir/build

CMakeFiles/exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exe.dir/clean

CMakeFiles/exe.dir/depend:
	cd /home/nareka/Desktop/GITHUBProjects/OpenCV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nareka/Desktop/GITHUBProjects/OpenCV /home/nareka/Desktop/GITHUBProjects/OpenCV /home/nareka/Desktop/GITHUBProjects/OpenCV/build /home/nareka/Desktop/GITHUBProjects/OpenCV/build /home/nareka/Desktop/GITHUBProjects/OpenCV/build/CMakeFiles/exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exe.dir/depend

