cmake_minimum_required(VERSION 3.10)

project(N-Queens)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)

include_directories(${PROJECT_SOURCE_DIR})

add_library(board src/board.cpp)
add_library(chromosone src/chromosone.cpp)
add_executable(genetic src/genetic.cpp)
target_link_libraries(genetic chromosone board)

find_package(PythonLibs 2.7)
target_include_directories(genetic PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(genetic ${PYTHON_LIBRARIES})

target_include_directories(genetic
    PRIVATE
    matplotlibcpp/matplotlibcpp.h
)

if(BUILD_TESTS)
    include_directories(${GTEST_INCLUDE_DIRS})
    
    set(__CFLAGS "${CMAKE_C_FLAGS}")
    set(__CXXFLAGS "${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "")
    set(CMAKE_CXX_FLAGS "")
    add_subdirectory(googletest EXCLUDE_FROM_ALL)
    set(CMAKE_C_FLAGS "${__CFLAGS}")
    set(CMAKE_CXX_FLAGS "${__CXXFLAGS}")
    unset(__CFLAGS)
    unset(__CXXFLAGS)

    SET(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} --coverage")
    SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage")
    SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} --coverage")
    
    enable_testing()

    add_executable(test_board tests/board_tests.cpp)
    target_link_libraries(test_board board gtest gtest_main)

    add_executable(test_chromosone tests/chromosone_tests.cpp)
    target_link_libraries(test_chromosone chromosone board gtest gtest_main)

    add_test(TestBoard test_board)
    add_test(TestChromosone test_chromosone)
endif()