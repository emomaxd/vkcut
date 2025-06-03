set(CMAKE_CXX_STANDARD 23)

set(INC
)

set(LIB
    X11
)

set(SRC
    main.cpp
)

add_executable(app ${SRC})

target_include_directories(app PUBLIC ${INC})

target_link_libraries(app PRIVATE ${LIB})
