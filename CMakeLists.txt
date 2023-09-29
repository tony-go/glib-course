cmake_minimum_required(VERSION 3.10)

project(MyGLibProject)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB REQUIRED glib-2.0 gio-2.0)

# Define schema files and compilation
set(SCHEMA_XML "${CMAKE_CURRENT_SOURCE_DIR}/com.tonygo.app.gschema.xml")
set(COMPILED_SCHEMA "${CMAKE_CURRENT_BINARY_DIR}/gschemas.compiled")

file(COPY ${SCHEMA_XML} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Compile the schema
add_custom_command(
    OUTPUT "${COMPILED_SCHEMA}"
    COMMAND glib-compile-schemas ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/com.tonygo.app.gschema.xml
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Make sure the compiled schema is a dependency
add_custom_target(
    compile_schemas ALL
    DEPENDS ${COMPILED_SCHEMA}
)

add_executable(my_app src/main.cc)

# Ensure the app depends on the schema compilation
add_dependencies(my_app compile_schemas)

target_include_directories(my_app PRIVATE ${GLIB_INCLUDE_DIRS})
target_link_libraries(my_app ${GLIB_LIBRARIES})
target_compile_options(my_app PRIVATE ${GLIB_CFLAGS_OTHER})

