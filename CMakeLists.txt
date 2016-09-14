#
# exercises project
#
cmake_minimum_required(VERSION 2.8.8)

project(exercises)

# activate C++ 11 features
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g")

# *********************************************
# third parties
# *********************************************

#gtest
set(GTEST_ROOT third_party/googletest/googletest)
add_library(gtest ${GTEST_ROOT}/src/gtest-all.cc)
target_include_directories(gtest PUBLIC ${GTEST_ROOT} ${GTEST_ROOT}/include)

# *********************************************
# Exercises
# *********************************************

function(declare_exercise target_name sources)
	add_executable(${target_name} ${sources} main.cpp)
	target_link_libraries(${target_name} gtest)
	add_test(NAME ${target_name} COMMAND ${target_name})
endfunction()

declare_exercise(ex1 ex1.cpp)
declare_exercise(ex2 ex2.cpp)
declare_exercise(ex3 ex3.cpp)
declare_exercise(ex4 ex4.cpp)
declare_exercise(ex5 ex5.cpp)
declare_exercise(ex6 ex6.cpp)
declare_exercise(ex7 ex7.cpp)
declare_exercise(ex8 ex8.cpp)
declare_exercise(ex10 ex10.cpp)

