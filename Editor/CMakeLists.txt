cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_library(editor STATIC Controller.cpp Model.cpp ObjectsPrimitive.cpp Primitive.cpp View.cpp)

target_include_directories(
  editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

if (MSVC)
    target_compile_options(editor PRIVATE
        /W4
    )
else ()
    target_compile_options(editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_executable(editor_cli main.cpp)

target_link_libraries(editor_cli PUBLIC ip_filter
)

if (MSVC)
    target_compile_options(editor_cli PRIVATE
        /W4
    )
else ()
    target_compile_options(editor_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)
