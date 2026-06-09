#include "menu.hpp"
#include "estados.hpp"
#include "raylib.h"
#include "raygui.h"

GameState Menu::desenhar(int screenWidth, int screenHeight){
    GameState proximoEstado = GameState::GAME_MENU;

    DrawText("JOGO CONWAYJAM", screenWidth / 2 - MeasureText("JOGO CONWAYJAM",50)/2, 100, 50, RED);

    if(GuiButton({(float)screenWidth/2 - 100, 300, 200, 50}, "JOGAR")){
        proximoEstado = GameState::GAMEPLAY;
    }

    if(GuiButton({(float)screenWidth/2 - 100, 380, 200, 50}, "SAIR")){
        proximoEstado = GameState::GAME_EXIT;
    }

    return proximoEstado;
}
