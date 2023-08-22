cmake_minimum_required(VERSION 3.10)

project(MyGLibProject)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0)

add_executable(my_app src/main.c)

target_include_directories(my_app PRIVATE ${GLIB_INCLUDE_DIRS})
target_link_libraries(my_app ${GLIB_LIBRARIES})
target_compile_options(my_app PRIVATE ${GLIB_CFLAGS_OTHER})

