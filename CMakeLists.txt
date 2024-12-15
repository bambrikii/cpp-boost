cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0048 NEW)

# set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-14")


project(App1 VERSION "1.0.0")

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(boost_INCLUDE_DIRS /usr/include/boost)
message(STATUS "boost_INCLUDE_DIRS: ${boost_INCLUDE_DIRS}")

set(boost_LIBS_DIR /usr/lib/x86_64-linux-gnu/)
message(STATUS "boost_LIBS_DIR: ${boost_LIBS_DIR}")

set(boost_COMPILE_OPTIONS
    -std=c++17
    -lboost_program_options
    -lboost_filesystem
    -lboost_system
    -lboost_timer
    -fdiagnostics-color=always
    --save-temps
    -dumpdir
    build/
    -I${boost_LIBS_DIR}
    -D_FILE_OFFSET_BITS=64
    -pthread
    -L${boost_LIBS_DIR}
    -pthread
    -Wl,-rpath,${boost_LIBS_DIR}
)
message(STATUS "boost_COMPILE_OPTIONS: ${boost_COMPILE_OPTIONS}")


add_compile_options(${boost_COMPILE_OPTIONS})

add_executable(app1_boost app1_boost.cpp)
target_include_directories(app1_boost PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app1_boost PUBLIC ${boost_LIBS_DIR})
target_link_directories(app1_boost PUBLIC /usr/lib/x86_64-linux-gnu)


add_executable(app2 app2_boost.cpp)
target_include_directories(app2 PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app2 PUBLIC ${boost_LIBS_DIR})
target_link_directories(app2 PUBLIC /usr/lib/x86_64-linux-gnu)


add_executable(app_NRVO app_NRVO.cpp)
target_include_directories(app_NRVO PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app_NRVO PUBLIC ${boost_LIBS_DIR})
target_link_directories(app_NRVO PUBLIC /usr/lib/x86_64-linux-gnu)


add_executable(app_containers app_containers.cpp)
target_include_directories(app_containers PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app_containers PUBLIC ${boost_LIBS_DIR})
target_link_directories(app_containers PUBLIC /usr/lib/x86_64-linux-gnu)
