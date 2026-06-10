#include "Tentaculo.hpp"
#include "../../../sistemas/globais.hpp"
#include "raymath.h"

Tentaculo::Tentaculo(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        setSpritesheet(LoadTexture("../assets/Spritesheets/Inimigos/Tentaculo.png"));

        SetMaxVelocidade(.8f);
        setVelocidade(.8f);

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

        setCaixaColisao(Rectangle{8, 48, 48,16});
        setAnimacaoAtual(getIdle());
    }

void Tentaculo::Ataque(){

}

void Tentaculo::Update(){
    Entidade::Update();
    
    Protagonista *player = Globais::GetPlayer();
    
    if(CheckCollisionRecs(getCaixaColisao(), player->getCaixaColisao()) && getEstado() != STUNNED){
        player->diminuirIntegridade(GetDano());
        player->aumentarNivelInfeccao(GetInfec());
        setEstadoPor(STUNNED, 2);
    }

    if(ativo) setEstadoPor(ANDANDO,0);
    else setEstadoPor(PARADO,0);


    if(Vector2Distance(player->getPosicao(), getPosicao()) < 225.0f){
        sumir = true;
        ativo = true;
    }else{
        aparecer = true;
        ativo = false;
    }

    if(!ativo && sumir){
        frameAtual = 1;
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
        frameAtual = 1;
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
    if (!getEstado() == ANDANDO) {
        frameAtual = 0;
    }else if(getEstado() == ANDANDO){ // Talvez tenha um jeito melhor, mas foi assim que eu tirei aquele delay antes de começar a animação
        if(frameAtual == 0) frameAtual = 1;
    }
    DrawTextureRec(spritesheet, AnimacaoAtual[frameAtual], {getPosicao().x, getPosicao().y-64}, WHITE);
}