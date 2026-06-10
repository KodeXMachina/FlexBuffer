cmake_minimum_required(VERSION 3.21)

project(flexbuf VERSION 0.1.0 LANGUAGES CXX)

include(cmake/flexbufOptions.cmake)
include(cmake/flexbufCompiler.cmake)
include(cmake/flexbufInstall.cmake)
include(GenerateExportHeader)

add_library(${PROJECT_NAME}
  src/flexbuf.cc
)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_20
)

flexbuf_configure_cxx_target(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_include_directories(${PROJECT_NAME}
  SYSTEM PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  OUTPUT_NAME flexbuf
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
)

generate_export_header(${PROJECT_NAME}
  BASE_NAME ${PROJECT_NAME}
  EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/flexbuf/export.h
)

if(${PROJECT_NAME}_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if(${PROJECT_NAME}_INSTALL)
  flexbuf_install_package(${PROJECT_NAME})
endif()
