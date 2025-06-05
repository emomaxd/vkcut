set(CMAKE_CXX_STANDARD 23)

set(INC
    .
    ..
)

set(LIB
    math
)

set(SRC
    engine.cpp

    engine.h
)

add_library(engine ${SRC})

target_include_directories(engine PUBLIC ${INC})

target_link_libraries(engine PRIVATE ${LIB})
