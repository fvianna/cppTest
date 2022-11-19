cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(cppTest VERSION 0.1.1)

# specify the C++ standard
add_library(cppTest_compiler_flags INTERFACE)
target_compile_features(cppTest_compiler_flags INTERFACE cxx_std_17)

# sets compiler flags according to the compiler that is being used and
# only when using the BUILD_INTERFACE generator expression
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(cppTest_compiler_flags INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-Werror>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3;-WX>>"
)

option(USE_MYMATH "Use non-default math implementation" ON)

# Makes configuration infos available to the source code
configure_file(src/in/config.hpp.in include/config.hpp)

if(USE_MYMATH)
    # adds the math module
    add_subdirectory(src/math)
    list(APPEND EXTRA_LIBS MyMath)
endif()

# add executables to the project
add_executable(cppTest src/main.cpp)

target_link_libraries(cppTest PUBLIC ${EXTRA_LIBS} cppTest_compiler_flags)

target_include_directories(
    cppTest PUBLIC
    "${PROJECT_BINARY_DIR}/include" # adds the binary directory as a path to be serched for include files
)


# executable installation
install(TARGETS cppTest DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/include/config.hpp" DESTINATION include)

#These tests only work if proper input is given, as for now main reads input from cin
enable_testing()

add_test(NAME Runs COMMAND cppTest)

add_test(NAME Usage COMMAND cppTest)
set_tests_properties(Usage 
    PROPERTIES PASS_REGULAR_EXPRESSION "Versão brasileira"
)

add_test(NAME StandardUse COMMAND cppTest 4)
set_tests_properties(StandardUse 
    PROPERTIES PASS_REGULAR_EXPRESSION "aproximada: 2"
)