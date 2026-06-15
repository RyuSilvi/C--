cmake_minimum_required(VERSION 3.31)
project(hello_world)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)


add_executable(hello)
target_sources(hello PRIVATE 
    main.cpp
)

target_compile_options(hello PRIVATE
-Werror             #Treat all warnings as errors
-Wall               #Enable all of the common warnings
-Wextra             #Enable extra warnings
-Wconversion        #Warn about implicit conversions
-Wshadow            #Warn about shadowed variables
)