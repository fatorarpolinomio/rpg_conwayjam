#include "Amalgama.hpp"
#include "../../../sistemas/globais.hpp"
#include "raymath.h"

Amalgama::Amalgama(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        setSpritesheet(LoadTexture("../assets/Spritesheets/Inimigos/amalgamo.png"));
        
        setIdle({
            Rectangle{0,0,128,64},
            Rectangle{128,0,128,64},
            Rectangle{256,0,128,64}
        });

        setAnimacaoAtual(getIdle());

    }

void Amalgama::Ataque(){

}

void Amalgama::Update(){
    Entidade::Update();
    Protagonista *player = Globais::GetPlayer();
    setEstadoPor(PARADO, 0);
    if(Vector2Distance(player->getPosicao(), getPosicao()) < 75.0f && getEstado() != ATACANDO){
        setEstadoPor(ATACANDO, 5, true);
        Ataque();

    }

    if(getEstado() == ATACANDO){
        tempoAteProxSprite -= GetFrameTime() * 3;
    }
}

void Amalgama::Draw(){
    Entidade::Draw();
}