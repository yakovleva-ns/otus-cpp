cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(2_ip_filter VERSION 0.0.1)

add_library(2_ip_filter STATIC ip_filter.cpp ip_filter.h)

set_target_properties(2_ip_filter PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

target_include_directories(2_ip_filter
  PRIVATE
  ${CMAKE_BINARY_DIR}
)

if (MSVC)
    target_compile_options(version_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(version_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()