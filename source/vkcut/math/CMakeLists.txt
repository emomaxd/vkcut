set(CMAKE_CXX_STANDARD 23)

set(INC
    .
    ..
)

set(LIB
)

set(SRC
    ray.cpp

    ray.h
    vec2.h
    vec3.h
)

add_library(math ${SRC})

target_include_directories(math PUBLIC ${INC})

target_link_libraries(math PRIVATE ${LIB})
