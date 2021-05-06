cmake_minimum_required(VERSION 3.10)

# set the project name
project(Lambdas VERSION 0.1)

#target_include_directories(Lambdas PUBLIC
#                           "${PROJECT_BINARY_DIR}"
#                           )

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(Lambdas ./lambdas/main.cpp)