#pragma once
#include "estados.hpp"
#include "raylib.h"

class Menu{
private:
    Texture2D nave; 

public:
    Menu();          
    GameState desenhar(int screenWidth, int screenHeight);

};
