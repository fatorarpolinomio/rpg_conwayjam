#include "mapa.hpp"
#include "raylib.h"
#include <iostream>

using namespace std;

int Mapa::mapaAtual;
vector<Texture2D> Mapa::mapasTextures;
vector<Image> Mapa::mapasImage;

Mapa::Mapa(){
    mapaAtual = 0;
}

void Mapa::carregarMapas(vector<Texture2D> mapas){
    mapasTextures = mapas;
}

void Mapa::carregarImagensDeColisao(vector<Image> imagens){
    mapasImage = imagens;
}

bool Mapa::estaCollidindo(Vector2 pos){

    Color pixel = GetImageColor(mapasImage[mapaAtual], pos.x, pos.y);
    if(pixel.r == 0 && pixel.g == 0 && pixel.b == 0){
        return true;
    }

    return false;
}

void Mapa::Draw(){
    
    DrawTextureV(mapasTextures[mapaAtual], Vector2{0,0}, WHITE);
}