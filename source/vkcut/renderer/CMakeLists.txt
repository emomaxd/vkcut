set(CMAKE_CXX_STANDARD 23)

set(INC
    .
    ..
)

set(LIB
)

set(SRC
    renderer.cpp

    camera.h
    renderer.h
)

add_library(renderer ${SRC})

target_include_directories(renderer PUBLIC ${INC})

target_link_libraries(renderer PRIVATE ${LIB})
