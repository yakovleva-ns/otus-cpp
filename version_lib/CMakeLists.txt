cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(version_lib VERSION 0.0.1)

configure_file(version.h.in version.h)

add_library(version_lib STATIC lib.cpp lib.h)

set_target_properties(version_lib PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

target_include_directories(version_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/version)

if (MSVC)
    target_compile_options(version_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(version_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
