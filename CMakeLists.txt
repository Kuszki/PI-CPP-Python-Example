cmake_minimum_required(VERSION 3.5)

project(PI-CPP-Python-Example LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS python3 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARY_DIR})

add_executable(cpptest cpptest.cpp
	cppcode.cpp cppcode.hpp
	cppclass.cpp cppclass.hpp)

python_add_module(cppcode
	cppcode.cpp cppcode.hpp)

python_add_module(cppclass
	cppclass.cpp cppclass.hpp)

list(APPEND LIB_LIST
	${Boost_LIBRARIES}
	${PYTHON_LIBRARIES})

target_link_libraries(cppcode ${LIB_LIST})
target_link_libraries(cppclass ${LIB_LIST})
target_link_libraries(cpptest ${LIB_LIST})

add_test(NAME test-cpp COMMAND cpptest)

add_test(NAME test-code COMMAND
	${PYTHON_EXECUTABLE} test-code.py)

add_test(NAME test-class COMMAND
	${PYTHON_EXECUTABLE} test-class.py)

file(COPY test-code.py DESTINATION .)
file(COPY test-class.py DESTINATION .)
file(COPY LICENSE DESTINATION .)
