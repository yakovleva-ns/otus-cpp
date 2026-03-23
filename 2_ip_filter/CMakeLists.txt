cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_library(ip_filter STATIC ip_filter.cpp ip_filter.h)

target_include_directories(
  ip_filter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_executable(ip_filter_cli main.cpp)

target_link_libraries(ip_filter_cli PUBLIC ip_filter
)

if (MSVC)
    target_compile_options(ip_filter_cli PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)