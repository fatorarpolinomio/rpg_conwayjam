#include "menu.hpp"
#include "estados.hpp"
#include "raylib.h"
#include "raygui.h"
#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>

Menu::Menu() {
    nave = LoadTexture("../assets/Backgrounds/nave.png");
}

GameState Menu::desenhar(int screenWidth, int screenHeight){

    using namespace std::chrono_literals;

    GameState proximoEstado = GameState::GAME_MENU;

    float posYBase = 0.0f;
    float amplitude = 20.0f;
    float velocidade = 1.5f;

    float posYAnimada = posYBase + sin(GetTime() * velocidade) * amplitude;

    DrawTexturePro(
        nave,
        Rectangle{ 0, 0, (float)nave.width, (float)nave.height },
        Rectangle{ 150, posYAnimada, (float)screenWidth, (float)screenHeight },
        Vector2{ 0, 0 },
        0.0f,
        WHITE
    );


    DrawText("SOMEWHERE IN A SPACESHIP", screenWidth / 4 - MeasureText("SOMEWHERE IN A SPACESHIP",50)/4, 100, 50, RED);

    if(GuiButton({(float)screenWidth/4 - 200, 300, 200, 50}, "JOGAR")){
        proximoEstado = GameState::GAMEPLAY;
    }

    if(GuiButton({(float)screenWidth/4 - 200, 380, 200, 50}, "SAIR")){
        proximoEstado = GameState::GAME_EXIT;
    }

    return proximoEstado;
}
