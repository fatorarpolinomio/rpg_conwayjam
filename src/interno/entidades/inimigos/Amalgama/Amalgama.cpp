#include "Amalgama.hpp"
#include "../../../sistemas/globais.hpp"
#include "raymath.h"

Amalgama::Amalgama(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        setSpritesheet(LoadTexture("../../../../../assets/Spritesheets/Inimigos/amalgamo.png"));

        setIdle({
            Rectangle{0,0,128,64},
            Rectangle{128,0,128,64},
            Rectangle{256,0,128,64}
        });

        setAndarCima(getIdle());
        setAndarBaixo(getIdle());
        setAndarEsquerda(getIdle());
        setAndarDireita(getIdle());

        setAnimacaoAtual(getIdle());

        setCaixaColisao(Rectangle{10,16,118,48});

    }

void Amalgama::Ataque(){
    for(Inimigo *i : Globais::Inimigos){
        if(Vector2Distance(getPosicao(), i->getPosicao()) < 100.0f) continue;
        i->setVelocidade(1.0f);
        i->Seguir(Vector2{this->getPosicao().x+caixaDeColisao.width/2, this->getPosicao().y+caixaDeColisao.height/2});
    }
}

void Amalgama::Update(){
    Entidade::Update();
    Protagonista *player = Globais::GetPlayer();
    setEstadoPor(PARADO, 0);
    if(Vector2Distance(player->getPosicao(), getPosicao()) < 100.0f && getEstado() != ATACANDO){
        setEstadoPor(ATACANDO, 5, true);
    }

    if(getEstado() == ATACANDO){
        Ataque();
        tempoAteProxSprite -= GetFrameTime() * 3;
    }
}

void Amalgama::Draw(){
    Entidade::Draw();
}
