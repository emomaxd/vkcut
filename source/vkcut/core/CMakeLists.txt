set(CMAKE_CXX_STANDARD 23)

set(INC
    .
    ..
)

set(LIB
    X11
)

set(SRC
  obj_loader.cpp

  base.h
  obj_loader.h
)

add_library(core ${SRC})

target_include_directories(core PUBLIC ${INC})

target_link_libraries(core PRIVATE ${LIB})
