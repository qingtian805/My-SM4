cmake_minimum_required(VERSION 3.5.0)

project(my-sm4 VERSION 0.0.0)

include_directories(${PROJECT_SOURCE_DIR}/include)# -I

set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS} -g) #DEBUG
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS} -O2) #RELEASE

file(GLOB SRC_FILES_SM4
    ${PROJECT_SOURCE_DIR}/src/sm4/*.cpp
    ${PROJECT_SOURCE_DIR}/src/sm4/*.c
)#搜索src中所有c/c++文件，并存在全局变量SRC_FILES中

file(GLOB SRC_FILES_SM4AVX
    ${PROJECT_SOURCE_DIR}/src/sm4avx/*.cpp
    ${PROJECT_SOURCE_DIR}/src/sm4avx/*.c)

#添加编译文件,使用SRC_FILES变量中的所有文件
add_executable(avxtest ./test/codetest/avxtest.c)
add_executable(basetest ./test/codetest/basetest.c ${PROJECT_SOURCE_DIR}/src/sm4/sm4base.c)
add_executable(kdftest ./test/functest/kdftest.c ${PROJECT_SOURCE_DIR}/src/sm4/sm4base.c ${PROJECT_SOURCE_DIR}/src/sm4/sm4kdf.c)
add_executable(sm4test ./test/functest/sm4test.c ${SRC_FILES_SM4})
add_executable(speedtest ./test/functest/speedtest.c ${SRC_FILES_SM4})

add_executable(speedtestavx ./test/functest/speedtest_avx.c ${SRC_FILES_SM4AVX})

target_compile_options(avxtest PRIVATE -mavx2 PRIVATE -mavx)
target_compile_options(speedtestavx PRIVATE -mavx2 PRIVATE -mavx)

#target_link_libraries(chaos-enc-test ${OpenCV_LIBS})
