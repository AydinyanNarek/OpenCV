################################################################################
######
###### CompVision Configuration File
######
################################################################################
######
###### Example Usage
######

cmake_minimum_required(VERSION 3.3.0)

project(CompVision)

set(PROJECT_NAME CompVision)
set(PROJECT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "None" "Debug" "Release")
endif()

# verbose output - useful for debugging, but turned off by default
set(CMAKE_VERBOSE_MAKEFILE OFF CACHE BOOL "Verbose")

set(UTILITIES_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/Utilities/" CACHE PATH "Location of Utilities sources.")
mark_as_advanced(UTILITIES_SOURCE_DIR)

set(COMPVISION_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/" CACHE PATH "Location of Utilities sources.")


#guard to prevent this file from running twice
if(NOT TARGET CompVision)

    #=============================================
	#============== DEPENDENCIES =================
    #=============================================
    
    set(UTILITIES_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/Utilities" CACHE PATH "Location of Utilities installation.")
	# If Utilities is not installed on the system, try building from sources
    if(NOT EXISTS "${UTILITIES_INSTALL_DIR}")
    
        if(NOT EXISTS "${UTILITIES_SOURCE_DIR}")
            # Here we could also checkout the appropriate version of Utilities from Stash
            message(FATAL_ERROR "A path to Utilities installation or Utilities sources must be provided.")
        endif()

        message(STATUS "Building Utilities from sources.")

        # Choose build directory for UTILITIES.
		set(UTILITIES_BUILD_DIR "${CMAKE_BINARY_DIR}/Utilities/build")
        file(MAKE_DIRECTORY "${UTILITIES_BUILD_DIR}")

        # Install UTILITIES_BUILD_DIR in the build tree
        set(UTILITIES_INSTALL_DIR "${CMAKE_BINARY_DIR}/Utilities/install")
        
		# Configure UTILITIES_BUILD_DIR_INSTALL_DIR
		set(UTILITIES_CMAKE_OPTIONS
			"-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
			"-DCMAKE_INSTALL_PREFIX=${UTILITIES_INSTALL_DIR}"
            )
            
        list(APPEND UTILITIES_CMAKE_OPTIONS -G ${CMAKE_GENERATOR})
        if(CMAKE_GENERATOR_TOOLSET)
            list(APPEND UTILITIES_CMAKE_OPTIONS -T ${CMAKE_GENERATOR_TOOLSET})
        endif()
        if(CMAKE_GENERATOR_PLATFORM)
            list(APPEND UTILITIES_CMAKE_OPTIONS -A ${CMAKE_GENERATOR_PLATFORM})
        endif()

        execute_process(
            COMMAND ${CMAKE_COMMAND} ${UTILITIES_CMAKE_OPTIONS} "${UTILITIES_SOURCE_DIR}"
            WORKING_DIRECTORY "${UTILITIES_BUILD_DIR}"
        )
        # Build and install UTILITIES
		execute_process(
			COMMAND ${CMAKE_COMMAND} --build "${UTILITIES_BUILD_DIR}" --config ${CMAKE_BUILD_TYPE} --target install
		)
    endif ()
endif()

# Add cmake scripts distributed with utilities to cmake prefix path
set(CMAKE_PREFIX_PATH "${UTILITIES_INSTALL_DIR}/cmake")

# Set OpenCV library directory
set(OPENCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/Linux-x-86-64/OpenCV")

set(OPENCV_BINARY_LOCATION "${OPENCV_DIR}/lib")
set(OPENCV_INCLUDE_LOCATION "${OPENCV_DIR}/include/opencv4")

include_directories(${OPENCV_INCLUDE_LOCATION})
include_directories("${UTILITIES_SOURCE_DIR}/include")


if(UNIX)
    set(OPENCV_LIBRARY_FILES
    ${OPENCV_BINARY_LOCATION}/libopencv_tracking.so
    ${OPENCV_BINARY_LOCATION}/libopencv_core.so
    ${OPENCV_BINARY_LOCATION}/libopencv_flann.so
    ${OPENCV_BINARY_LOCATION}/libopencv_imgproc.so
    ${OPENCV_BINARY_LOCATION}/libopencv_ml.so
    ${OPENCV_BINARY_LOCATION}/libopencv_photo.so
    ${OPENCV_BINARY_LOCATION}/libopencv_imgcodecs.so
    ${OPENCV_BINARY_LOCATION}/libopencv_video.so
    ${OPENCV_BINARY_LOCATION}/libopencv_videoio.so
    ${OPENCV_BINARY_LOCATION}/libopencv_highgui.so
    ${OPENCV_BINARY_LOCATION}/libopencv_features2d.so
    ${OPENCV_BINARY_LOCATION}/libopencv_calib3d.so
    ${OPENCV_BINARY_LOCATION}/libopencv_objdetect.so
    ${OPENCV_BINARY_LOCATION}/libopencv_stitching.so
    ${OPENCV_BINARY_LOCATION}/libopencv_dnn.so
    ${OPENCV_BINARY_LOCATION}/libopencv_bgsegm.so
    )
endif()

# define source files
set(comp_vision_source_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(comp_vision_source_files
    ${comp_vision_source_dir}/src/main.cpp 
    ${comp_vision_source_dir}/src/CVDecoder.cpp
    ${comp_vision_source_dir}/src/CVEncoder.cpp
    ${comp_vision_source_dir}/src/Filters.cpp
    ${comp_vision_source_dir}/src/VideoOverlayer.cpp
)

set(comp_vision_header_files 
    ${comp_vision_source_dir}/include/BaseVideo.h
    ${comp_vision_source_dir}/include/CVDecoder.h
    ${comp_vision_source_dir}/include/CVEncoder.h
    ${comp_vision_source_dir}/include/Filters.h
    ${comp_vision_source_dir}/include/VideoOverlayer.h
)

set(UTIL
    ${CMAKE_CURRENT_SOURCE_DIR}/build/Utilities/install/lib/libUTILITIES.a
)

SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${OPENCV_BINARY_LOCATION}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


add_executable(exe  ${comp_vision_source_files} )

target_link_libraries(exe PRIVATE 
    ${UTIL}
    ${OPENCV_LIBRARY_FILES}
)


set_source_files_properties(
  ${UTIL}
  ${OPENCV_LIBRARY_FILES}
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true
)

if(CMAKE_COMPILER_IS_GNUCC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif(CMAKE_COMPILER_IS_GNUCC)

#compilation options
set_target_properties(exe
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    CXX_VISIBILITY_PRESET hidden
    ARCHIVE_OUTPUT_DIRECTORY "${comp_vision_source_dir}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${comp_vision_source_dir}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${comp_vision_source_dir}/../bin"
)

target_compile_options(exe
    PRIVATE "-Wall"
    PRIVATE "-Wextra"
    PRIVATE "-Wfloat-equal"
    PRIVATE "-pedantic"
    PRIVATE "$<$<NOT:$<CONFIG:Debug>>:-O3>"
)

