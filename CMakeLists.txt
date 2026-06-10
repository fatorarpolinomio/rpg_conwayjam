cmake_minimum_required(VERSION 3.15...4.0)

project(RPG_GameJam CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Onde estão os arquivos JSON e Raygui
include_directories(${CMAKE_SOURCE_DIR}/lib)

# Cria o executável
add_executable(rpg
    src/main.cpp
    src/interno/sistemas/globais.cpp
    src/interno/entidades/entidade.cpp
    src/interno/sistemas/camera.cpp
    src/interno/entidades/inimigos/Inimigos.cpp
    src/interno/entidades/protagonista/protagonista.cpp
    src/interno/entidades/inimigos/Tripulante/Tripulante.cpp
    src/interno/entidades/inimigos/Amalgama/Amalgama.cpp
    src/interno/entidades/inimigos/Tentaculo/Tentaculo.cpp
    src/interno/entidades/inimigos/Smilinguido/Smilinguido.cpp
    src/interno/entidades/itens/itens.cpp
    src/interno/entidades/itens/itens.cpp
    src/interno/sistemas/trilhaSonora.cpp
    src/interno/sistemas/transicao.cpp
    src/interno/cenario/espaco.cpp
    src/interno/entidades/NPC/NPC.cpp
    src/interno/estados/estados.cpp
    src/interno/estados/menu.cpp
    src/interno/estados/pause.cpp
    )

# Baixa a Raylib automaticamente do GitHub na primeira vez que o CMake rodar
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
# Desativa a construção de exemplos da Raylib para compilar mais rápido
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# Linka a Raylib ao jogo
target_link_libraries(rpg PRIVATE raylib)
