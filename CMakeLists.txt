cmake_minimum_required(VERSION 3.13)
project(cal_proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(cal_proj main.cpp Empresa.cpp Garagem.cpp Deposito.cpp Camiao.cpp Local.cpp)