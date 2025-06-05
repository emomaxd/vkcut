set(CMAKE_CXX_STANDARD 23)

set(INC
    .
    ..
)

set(LIB
    math
)

set(SRC
    scene.cpp
    
    scene.h
    mesh.h
)

add_library(scene ${SRC})

target_include_directories(scene PUBLIC ${INC})

target_link_libraries(scene PRIVATE ${LIB})
