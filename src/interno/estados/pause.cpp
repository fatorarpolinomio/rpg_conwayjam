#include "estados.hpp"
#include "pause.hpp"
#include "raylib.h"
#include "raygui.h"

GameState Pause::desenhar(int screenWidth, int screenHeight){
    GameState proximoEstado = GameState::PAUSE;

    DrawRectangle(0, 0, screenWidth, screenHeight, Color{0, 0, 0, 160});

    DrawText("PAUSE", screenWidth / 2 - MeasureText("PAUSE", 30) / 2, 100, 30, RED);

    if (GuiButton({ (float)screenWidth / 2 - 100, 180, 200, 40 }, "RETORNAR")) {
        proximoEstado = GameState::GAMEPLAY;
    }

    if (GuiButton({ (float)screenWidth / 2 - 100, 240, 200, 40 }, "MENU PRINCIPAL")) {
        proximoEstado = GameState::GAME_MENU;
    }

    if (GuiButton({ (float)screenWidth / 2 - 100, 300, 200, 40 }, "SAIR")) {
        proximoEstado = GameState::GAME_EXIT;
    }

    return proximoEstado;
}
