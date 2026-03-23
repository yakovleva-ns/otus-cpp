cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(ip_filter VERSION 0.0.1)

add_library(ip_filter STATIC ip_filter.cpp ip_filter.h)

set_target_properties(ip_filter PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_include_directories(
  ip_filter PRIVATE
  ${CMAKE_SOURCE_DIR}/build
  ${CMAKE_SOURCE_DIR}/version_lib
  ${CMAKE_SOURCE_DIR}/2_ip_filter
)

target_link_libraries(${PROJECT_NAME}
  version_lib
  ip_filter
)

add_executable(${PROJECT_NAME} main.cpp)

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()