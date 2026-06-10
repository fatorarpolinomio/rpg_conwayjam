#include "Tripulante.hpp"
#include <algorithm>
#include "../../../sistemas/globais.hpp"
#include <raymath.h>
#include <iostream>

using namespace std;

Tripulante::Tripulante(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        SetMaxVelocidade(0.2f);
        SetVelocidade(0.2f);
        

        spritesheet = LoadTexture("../assets/Spritesheets/Inimigos/tripulanteInfectados.png");

        andarCima = {
            Rectangle{0, 128, 64, 64},
            Rectangle{64, 128, 64, 64},
            Rectangle{128, 128, 64, 64},
        };
        andarDireita = {
            Rectangle{0, 192, 64, 64},
            Rectangle{64, 192, 64, 64},
            Rectangle{128, 192, 64, 64},
        };
        andarEsquerda = {
            Rectangle{0, 64, 64, 64},
            Rectangle{64, 64, 64, 64},
            Rectangle{128, 64, 64, 64},
        };
        andarBaixo = {
            Rectangle{0, 0, 64, 64},
            Rectangle{64, 0, 64, 64},
            Rectangle{128, 0, 64, 64},
        };
        idle = {
            Rectangle{0,0,64,64}
        };
        AnimacaoAtual = andarBaixo;

        setCaixaColisao(Rectangle{16,48,32,16});
    }

void Tripulante::Morrer(){
    Inimigo::Morrer();
    //Animação de morte e logica também
}

void Tripulante::Update(){
    Entidade::Update();



    Protagonista *player = Globais::GetPlayer();
    
    // Seguir player

    if(getEstado() != STUNNED){
        Inimigo::Seguir(player->getPosicao());
    }

    // Atacar se chegar perto
    if(CheckCollisionRecs(getCaixaColisao(), player->getCaixaColisao()) && getEstado() != STUNNED){
        player->diminuirIntegridade(GetDano());
        player->aumentarNivelInfeccao(GetInfec());
        setEstadoPor(STUNNED, 5);
    }

    float distPlayer = Vector2Distance(player->getPosicao(), getPosicao());
    if(distPlayer < 100.0f) Ataque();
    else if(distPlayer < 300.0f){

        int chance = rand() % 200;
        if(chance < 1){
            TocarAudio(grunir);
        }
    
        setVelocidade(GetMaxVelocidade());
        setEstadoPor(ANDANDO,0);
    }

    if(getEstado() == ATACANDO){
        tempoAteProxSprite -= GetFrameTime() * velocidade * 2;
    }
}


void Tripulante::Draw(){
    Entidade::Draw();
}

void Tripulante::Ataque(){
    setEstadoPor(ATACANDO,0);
    setVelocidade(3.5f);
    
    TocarAudio(scare);
    SetSoundVolume(gritar,2.0f);
    TocarAudio(gritar);

}