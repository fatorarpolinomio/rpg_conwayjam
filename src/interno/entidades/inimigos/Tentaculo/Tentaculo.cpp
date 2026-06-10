#include "Tentaculo.hpp"
#include "../../../sistemas/globais.hpp"
#include "raymath.h"

Tentaculo::Tentaculo(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        setSpritesheet(LoadTexture("../assets/Spritesheets/Inimigos/Tentaculo.png"));

        SetMaxVelocidade(.6f);
        setVelocidade(.6f);

        setIdle({
            Rectangle{0,0,0,0},
            Rectangle{0,128,64,128},
            Rectangle{64,128,64,128},
            Rectangle{128,128,64,128}
        });

        setAndarBaixo({
            Rectangle{0,0,64,128},
            Rectangle{64,0,64,128},
            Rectangle{128,0,64,128}
        });
        setAndarCima({
            Rectangle{0,0,64,128},
            Rectangle{64,0,64,128},
            Rectangle{128,0,64,128}
        });
        setAndarEsquerda({
            Rectangle{0,0,64,128},
            Rectangle{64,0,64,128},
            Rectangle{128,0,64,128}
        });
        setAndarDireita({
            Rectangle{0,0,64,128},
            Rectangle{64,0,64,128},
            Rectangle{128,0,64,128}
        });

        setCaixaColisao(Rectangle{8, 96, 56,16});
        setAnimacaoAtual(getIdle());
    }

void Tentaculo::Ataque(){

}

void Tentaculo::Update(){
    Entidade::Update();

    if(ativo) setEstadoPor(ANDANDO,0);
    else setEstadoPor(PARADO,0);
    

    Protagonista *player = Globais::GetPlayer();

    if(Vector2Distance(player->getPosicao(), getPosicao()) < 100.0f){
        sumir = true;
        ativo = true;
    }else{
        aparecer = true;
        ativo = false;
    }

    if(!ativo && sumir){
        setIdle({
            Rectangle{0,0,0,0},
            Rectangle{128,128,64,128},
            Rectangle{64,128,64,128},
            Rectangle{0,128,64,128},
            Rectangle{0,128,64,128},
            Rectangle{0,128,64,128}
        });
        setAnimacaoAtual(getIdle());
        setEstadoPor(STUNNED, .5f, true);
        sumir = false;
    }

    if(ativo && aparecer){
        setIdle({
            Rectangle{0,0,0,0},
            Rectangle{0,128,64,128},
            Rectangle{64,128,64,128},
            Rectangle{128,128,64,128},
            Rectangle{128,128,64,128},
            Rectangle{128,128,64,128}
        });
        setAnimacaoAtual(getIdle());

        setEstadoPor(STUNNED, .5f, true);
        aparecer = false;
    }

    if(getEstado() == STUNNED){
        tempoAteProxSprite -= GetFrameTime() * 2.5f;
    }

    if(getEstado() == ANDANDO){
        
        tempoAteProxSprite -= GetFrameTime() * 3;
        Seguir(player->getPosicao());
    }
    
}

void Tentaculo::Draw(){
    Entidade::Draw();
}