cmake_minimum_required(VERSION 3.5.0)

project(my-sm4 VERSION 0.0.0)

include_directories(${PROJECT_SOURCE_DIR}/include)# -I

set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS} -g) #DEBUG
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS} -O2) #RELEASE

file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c
)#搜索src中所有c/c++文件，并存在全局变量SRC_FILES中

#添加编译文件,使用SRC_FILES变量中的所有文件
add_executable(basetest ./test/codetest/basetest.c ${PROJECT_SOURCE_DIR}/src/sm4base.c)
add_executable(kdftest ./test/functest/kdftest.c ${PROJECT_SOURCE_DIR}/src/sm4base.c ${PROJECT_SOURCE_DIR}/src/sm4kdf.c)
add_executable(sm4test ./test/functest/sm4test.c ${SRC_FILES})
add_executable(speedtest ./test/functest/speedtest.c ${SRC_FILES})

#target_link_libraries(chaos-enc-test ${OpenCV_LIBS})
