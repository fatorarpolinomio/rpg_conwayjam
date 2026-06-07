#include "Tripulante.hpp"
#include <algorithm>
#include "../../../sistemas/globais.hpp"
#include <raymath.h>

Tripulante::Tripulante(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        velocidade = .002f;

        spritesheet = LoadTexture("../assets/Spritesheets/Inimigos/spriteTemporario.png");

        idle = {
            Rectangle{0,0,64,64}
        };
        AnimacaoAtual = idle;
    }

void Tripulante::Morrer(){

    Inimigos.erase(remove(Inimigos.begin(), Inimigos.end(), this));
    //Animação de morte e logica também
}

void Tripulante::Update(){
    if(GetVida() <= 0){
        Morrer();
    }
    posicao.x += .005f;
}

void Tripulante::Draw(){
  if (!andando) {
    frameAtual = 0;
  }
  DrawTextureRec(spritesheet, AnimacaoAtual[frameAtual], getPosicao(), WHITE);
}

void Tripulante::Ataque(){
    Globais global;
    
    

}