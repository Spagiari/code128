add_definitions (-D_GNU_SOURCE)

# add the executable
SET(CODE_128_AUTO__FILES
    ${PROJECT_SOURCE_DIR}/src/code128.cpp
    )

add_library(CPPclass STATIC IMPORTED)
set_target_properties(CPPclass PROPERTIES
    IMPORTED_LOCATION ./libCPPclass.a
    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
    )
add_executable (code128 ${CODE_128_AUTO__FILES})
