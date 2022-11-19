add_library(MyMath my_sqrt.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(MyMath
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MyMath cppTest_compiler_flags)

# lib instalation
set(libs_to_install MyMath cppTest_compiler_flags)
install(TARGETS ${libs_to_install} DESTINATION lib)
install(FILES my_math.hpp DESTINATION include)