include_directories(${CMAKE_SOURCE_DIR}/pcl/include)
include_directories(${CMAKE_SOURCE_DIR}/eigen)

add_library(libboost_date_time STATIC IMPORTED)
set_target_properties(libboost_date_time PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_date_time.a)

add_library(libboost_filesystem STATIC IMPORTED)
set_target_properties(libboost_filesystem PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_filesystem.a)

add_library(libboost_iostreams STATIC IMPORTED)
set_target_properties(libboost_iostreams PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_iostreams.a)

add_library(libboost_program_options STATIC IMPORTED)
set_target_properties(libboost_program_options PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_program_options.a)

add_library(libboost_regex STATIC IMPORTED)
set_target_properties(libboost_regex PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_regex.a)

add_library(libboost_signals STATIC IMPORTED)
set_target_properties(libboost_signals PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_signals.a)

add_library(libboost_system STATIC IMPORTED)
set_target_properties(libboost_system PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_system.a)

add_library(libboost_thread STATIC IMPORTED)
set_target_properties(libboost_thread PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libboost_thread.a)

add_library(libpcl_2d STATIC IMPORTED)
set_target_properties(libpcl_2d PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_2d.a)

add_library(libpcl_common STATIC IMPORTED)
set_target_properties(libpcl_common PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_common.a)

add_library(libpcl_features STATIC IMPORTED)
set_target_properties(libpcl_features PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_features.a)

add_library(libpcl_filters STATIC IMPORTED)
set_target_properties(libpcl_filters PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_filters.a)

add_library(libpcl_io STATIC IMPORTED)
set_target_properties(libpcl_io PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_io.a)

add_library(libpcl_io_ply STATIC IMPORTED)
set_target_properties(libpcl_io_ply PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_io_ply.a)

add_library(libpcl_kdtree STATIC IMPORTED)
set_target_properties(libpcl_kdtree PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_kdtree.a)

add_library(libpcl_keypoints STATIC IMPORTED)
set_target_properties(libpcl_keypoints PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_keypoints.a)

add_library(libpcl_ml STATIC IMPORTED)
set_target_properties(libpcl_ml PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_ml.a)

add_library(libpcl_octree STATIC IMPORTED)
set_target_properties(libpcl_octree PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_octree.a)

add_library(libpcl_recognition STATIC IMPORTED)
set_target_properties(libpcl_recognition PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_recognition.a)

add_library(libpcl_registration STATIC IMPORTED)
set_target_properties(libpcl_registration PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_registration.a)

add_library(libpcl_sample_consensus STATIC IMPORTED)
set_target_properties(libpcl_sample_consensus PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_sample_consensus.a)

add_library(libpcl_search STATIC IMPORTED)
set_target_properties(libpcl_search PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_search.a)

add_library(libpcl_segmentation STATIC IMPORTED)
set_target_properties(libpcl_segmentation PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_segmentation.a)

add_library(libpcl_stereo STATIC IMPORTED)
set_target_properties(libpcl_stereo PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_stereo.a)

add_library(libpcl_surface STATIC IMPORTED)
set_target_properties(libpcl_surface PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_surface.a)

add_library(libpcl_tracking STATIC IMPORTED)
set_target_properties(libpcl_tracking PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libpcl_tracking.a)

add_library(libflann_cpp_s STATIC IMPORTED)
set_target_properties(libflann_cpp_s PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libflann_cpp_s.a)

add_library(libflann_s STATIC IMPORTED)
set_target_properties(libflann_s PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/pcl/lib/libflann_s.a)

target_link_libraries( # Specifies the target library.
        native-lib
        libpcl_2d libpcl_common libpcl_features libpcl_filters libpcl_io libpcl_io_ply libpcl_kdtree libpcl_keypoints libpcl_ml libpcl_octree libpcl_recognition libpcl_registration libpcl_sample_consensus libpcl_search libpcl_segmentation libpcl_stereo libpcl_surface libpcl_tracking
        libboost_date_time libboost_filesystem libboost_iostreams libboost_program_options libboost_regex libboost_signals libboost_system libboost_thread
        libflann_cpp_s libflann_s
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

