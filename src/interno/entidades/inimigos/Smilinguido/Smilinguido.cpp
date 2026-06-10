#include "Smilinguido.hpp"
#include "../../protagonista/protagonista.hpp"
#include "../../../sistemas/globais.hpp"
#include "../../../cenario/mapa.hpp"
#include <iostream>
#include <thread>
#include "raymath.h"
#include <chrono>

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
        setEstadoPor(STUNNED, 5, true);
    }
}

bool Smilinguido::UpdateTimer(){
    timer -=  1 * GetFrameTime();

    if(timer <= 0) {
        timerLiberado = true;
        setVelocidade(10.0f);
        setEstadoPor(ATACANDO, 3, true);
        std::cout << ": " << getEstado() << std::endl;
        return true;
    }
    else {
        setEstadoPor(PARADO, 5);
        return false;
    }
}

void Smilinguido::setTimer(float time){
    if(timerLiberado){
        Vector2 dir = Vector2Subtract(Globais::GetPlayer()->getPosicao(), getPosicao());
        dir = Vector2Normalize(dir);
        SetDir(dir);
        timer = time;
        timerLiberado = false;
    }
}

void Smilinguido::Ataque(){
    if(getEstado() != ATACANDO && getEstado() != STUNNED){
        setTimer(2);
        UpdateTimer();
    }
}
void Smilinguido::Update(){
    Entidade::Update();

    setEstadoPor(ANDANDO, 0);

    Protagonista *player = Globais::GetPlayer();

    if(CheckCollisionRecs(getCaixaColisao(), player->getCaixaColisao()) && getEstado() != STUNNED){
        player->diminuirIntegridade(GetDano());
        player->aumentarNivelInfeccao(GetInfec());
        setEstadoPor(STUNNED, 1);
    }
    
    if(getEstado() == ATACANDO){
        setVelocidade(getVelocidade() + .2f);
        Seguir(getPosicao() + GetDir() * velocidade);
    }else if(getEstado() != ATACANDO){
        setVelocidade(GetMaxVelocidade());
    }
    
    if(getEstado() == ANDANDO){
        Seguir(player->getPosicao());
    }

    float distPlayer = Vector2Distance(player->getPosicao(), getPosicao());
    if(distPlayer < 150.0f){
        Ataque();
    }else if(distPlayer < 300.0f){
        setEstadoPor(ANDANDO,0);
    }else{
        setEstadoPor(PARADO,0);
    }
}
void Smilinguido::Draw() {
    Entidade::Draw();
}