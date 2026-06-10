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

// bool Mapa::estaCollidindo(Vector2 pos){

//     Color pixel = GetImageColor(mapasImage[mapaAtual], pos.x, pos.y);
//     if(pixel.r == 0 && pixel.g == 0 && pixel.b == 0){
//         return true;
//     }

//     return false;
// }

bool Mapa::estaCollidindo(Vector2 Offset, Rectangle colisao){

    colisao.x += Offset.x;
    colisao.y += Offset.y;

    for(int i = colisao.x; i < (colisao.x+colisao.width); i++){
        if(Offset.y <= 0){
            Color pixelCima = GetImageColor(mapasImage[mapaAtual], i, colisao.y);
            if(pixelCima.r == 0 && pixelCima.g == 0 && pixelCima.b == 0){
                return true;
            }
        }

        if(Offset.y >= 0){
            Color pixelBaixo = GetImageColor(mapasImage[mapaAtual], i, colisao.y+colisao.height);
            if(pixelBaixo.r == 0 && pixelBaixo.g == 0 && pixelBaixo.b == 0){
                return true;
            }
        }
    }

    for(int i = colisao.y; i < (colisao.y+colisao.height); i++){
        
        if(Offset.x <= 0){
            Color pixelEsquerda = GetImageColor(mapasImage[mapaAtual], colisao.x, i);
            if(pixelEsquerda.r == 0 && pixelEsquerda.g == 0 && pixelEsquerda.b == 0){
                return true;
            }
        }

        if(Offset.x >= 0){
            Color pixelDireita = GetImageColor(mapasImage[mapaAtual], colisao.x+colisao.width, i);
            if(pixelDireita.r == 0 && pixelDireita.g == 0 && pixelDireita.b == 0){
                return true;
            }
        }
    }


    return false;
}

void Mapa::Draw(){
    DrawTextureV(mapasTextures[mapaAtual], Vector2{0,0}, WHITE);
}