cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_COMPILER g++)

set(HEADERS
    types.h
    bytebuffer.h
    value.h
    array.h
    operators.h
)

project(PolyDataFrame)

add_executable(${PROJECT_NAME} "main.cpp" ${HEADERS})

target_link_libraries(${PROJECT_NAME}
    tcmalloc
#    -pg
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    -fno-omit-frame-pointer
    -flto
    -march=native
    -m64
    -std=c++17
    -O2
#    -O
    -g3
#    -pg
    -floop-parallelize-all
    -ftree-parallelize-loops=4
)
