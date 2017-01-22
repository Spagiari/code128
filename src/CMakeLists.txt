add_definitions (-D_GNU_SOURCE)

# add the executable
SET(CODE_128_AUTO__FILES
    ${PROJECT_SOURCE_DIR}/src/code128.cpp
    )

add_executable (code128 ${CODE_128_AUTO__FILES})
target_link_libraries(code128 stdc++)
