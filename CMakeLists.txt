cmake_minimum_required(VERSION 3.6)
project(abstract)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Avm.Class.cpp
        Avm.Class.hpp
        AvmException.Class.cpp
        AvmException.Class.hpp
        IOperand.Class.hpp
        main.cpp
        Operand.Class.hpp Factory.cpp Factory.h)

add_executable(abstract ${SOURCE_FILES})