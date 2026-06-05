cmake_minimum_required(VERSION 3.15...4.0)

project(RPG_GameJam CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Onde estão os arquivos JSON e Raygui
include_directories(${CMAKE_SOURCE_DIR}/lib)

# Cria o executável
add_executable(rpg 
    src/main.cpp
    src/interno/protagonista/protagonista.cpp
    )

# Baixa a Raylib automaticamente do GitHub na primeira vez que o CMake rodar
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz
)
# Desativa a construção de exemplos da Raylib para compilar mais rápido
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# Linka a Raylib ao jogo
target_link_libraries(rpg PRIVATE raylib)
