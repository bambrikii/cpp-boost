cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0048 NEW)

# set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-14")


project(App1 VERSION "1.0.0")

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(boost_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/include)
message(STATUS "boost_INCLUDE_DIRS: ${boost_INCLUDE_DIRS}")

set(boost_LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib/)
message(STATUS "boost_LIBS_DIR: ${boost_LIBS_DIR}")

set(boost_COMPILE_OPTIONS
    -std=c++17
    -lboost_regex
    -lboost_iostreams
    -lboost_program_options
    -lboost_filesystem
    -lboost_system
    -lboost_timer
    -lboost_thread
    -lboost_date_time
    -lboost_chrono
    -lboost_container
    -lboost_coroutine
    -lboost_random
    -lboost_serialization
    -lboost_wserialization
    -lboost_context
    -fdiagnostics-color=always
    --save-temps
    -dumpdir build
    -I${boost_LIBS_DIR}
    -D_FILE_OFFSET_BITS=64
    -pthread
    -L${boost_LIBS_DIR}
    -pthread
    -Wl,-rpath,${boost_LIBS_DIR}
)
message(STATUS "boost_COMPILE_OPTIONS: ${boost_COMPILE_OPTIONS}")

# find_package(fmt CONFIG REQUIRED)
# Or use the header-only version
#find_package(fmt CONFIG REQUIRED)
#target_link_libraries(main PRIVATE fmt::fmt-header-only)


add_compile_options(${boost_COMPILE_OPTIONS})

add_executable(app1_boost app1_boost.cpp)
target_include_directories(app1_boost PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app1_boost PUBLIC ${boost_LIBS_DIR})
target_link_directories(app1_boost PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib)
# target_link_libraries(app1_boost PRIVATE fmt::fmt)
set_target_properties(app1_boost PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
)
# add_custom_target(clean_all ALL "rm *.bc *.o *.ii *.ss *.s")


add_executable(app2 app2_boost.cpp)
target_include_directories(app2 PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app2 PUBLIC ${boost_LIBS_DIR})
target_link_directories(app2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib)
set_target_properties(app2 PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
)


add_executable(app_NRVO app_NRVO.cpp)
target_include_directories(app_NRVO PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app_NRVO PUBLIC ${boost_LIBS_DIR})
target_link_directories(app_NRVO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib)
set_target_properties(app_NRVO PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
)


add_executable(app_containers app_containers.cpp)
target_include_directories(app_containers PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app_containers PUBLIC ${boost_LIBS_DIR})
target_link_directories(app_containers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib)
set_target_properties(app_containers PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
)


add_executable(app_io app_io.cpp)
target_include_directories(app_io PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app_io PUBLIC ${boost_LIBS_DIR})
target_link_directories(app_io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib)
set_target_properties(app_io PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
)

add_executable(app_asio app_asio.cpp)
target_include_directories(app_asio PUBLIC ${boost_INCLUDE_DIRS})
target_link_directories(app_asio PUBLIC ${boost_LIBS_DIR})
target_link_directories(app_asio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-linux/lib)
set_target_properties(app_asio PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/
)