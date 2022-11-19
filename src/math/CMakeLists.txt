add_library(MyMath my_sqrt.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(MyMath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MyMath cppTest_compiler_flags)