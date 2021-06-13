cmake_minimum_required(VERSION 3.17)
project(cpp-snake-game)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        SnakeGameInCpp_master
        main.cpp
        Coordenada.cpp
        Juego.cpp
        Serpiente.cpp
        Jugador.cpp)
