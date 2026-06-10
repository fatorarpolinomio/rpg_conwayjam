#include "Smilinguido.hpp"
#include "../../protagonista/protagonista.hpp"
#include "../../../sistemas/globais.hpp"
#include "../../../cenario/mapa.hpp"
#include "raymath.h"
#include <iostream>

Smilinguido::Smilinguido(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        SetMaxVelocidade(.6f);
        setVelocidade(.6f);

        spritesheet = LoadTexture("../assets/Spritesheets/Inimigos/smilinguido.png");

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

        setCaixaColisao(Rectangle{20,48,28,16});
    }

void Smilinguido::Seguir(Vector2 pos){
    Vector2 posAnterior = getPosicao();
    Inimigo::Seguir(pos);

    if(posAnterior == getPosicao() && getEstado() == ATACANDO){
        std::cout << "BATEU" << std::endl;
        setEstadoPor(STUNNED, 5, true);
    }
    // FICAR STUNNED QUANDO BATER NA PAREDE
}

void Smilinguido::Ataque(){
    if(getEstado() != ATACANDO && getEstado() != STUNNED){
        Vector2 dir = Vector2Subtract(Globais::GetPlayer()->getPosicao(), getPosicao());
        dir = Vector2Normalize(dir);
        SetDir(dir);
        setVelocidade(10.0f);
        setEstadoPor(ATACANDO, 1);
    }
}
void Smilinguido::Update(){
    Entidade::Update();

    setEstadoPor(ANDANDO, 0);
    std::cout << getEstado() << std::endl;

    Protagonista *player = Globais::GetPlayer();

    if(getEstado() == ATACANDO){
        setVelocidade(getVelocidade() + .2f);
        Seguir(getPosicao() + GetDir() * velocidade);
    }else if(getEstado() != ATACANDO){
        setVelocidade(GetMaxVelocidade());
    }
    
    if(getEstado() == ANDANDO){
        Seguir(player->getPosicao());
    }

    if(Vector2Distance(player->getPosicao(), getPosicao()) < 150.0f){
        Ataque();
    }else{
        setEstadoPor(ANDANDO,0);
    }
}
void Smilinguido::Draw() {
    Entidade::Draw();
}