#include "Tripulante.hpp"
#include <algorithm>
#include "../../../sistemas/globais.hpp"
#include <raymath.h>
#include <iostream>

using namespace std;

Tripulante::Tripulante(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        SetMaxVelocidade(0.5f);
        SetVelocidade(0.5f);
        

        spritesheet = LoadTexture("../assets/Spritesheets/Inimigos/spriteTemporario.png");

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
    }

void Tripulante::Morrer(){
    Inimigo::Morrer();
    //Animação de morte e logica também
}

void Tripulante::Update(){
    Entidade::Update();

    if(GetVida() <= 0){
        Morrer();
    }


    Protagonista *player = Globais::GetPlayer();
    
    // Seguir player

    if(getEstado() != STUNNED){
        SeguirPlayer(player);
    }

    // Atacar se chegar perto
    if(CheckCollisionRecs(caixaDeColisao, player->getCaixaColisao())){
        player->diminuirIntegridade(20);
        setEstadoPor(STUNNED, 5);
    }

    float distPlayer = Vector2Distance(player->getPosicao(), getPosicao());
    if(distPlayer < 100.0f) Ataque();
    else {
        setVelocidade(GetMaxVelocidade());
        setEstadoPor(ANDANDO,0);
    }

    if(getEstado() == ATACANDO){
        tempoAteProxSprite -= GetFrameTime() * velocidade * 100;
    }
}

void Tripulante::SeguirPlayer(Protagonista *player)
{
    Vector2 seguindoPlayer = Vector2MoveTowards(getPosicao(), player->getPosicao(), velocidade);
    setPosicao(seguindoPlayer);

    // Mudar animação de acordo com sa posição do player
    Vector2 Offset = Vector2Subtract(player->getPosicao(), getPosicao());

    if (Offset.y > 0)
    {
        AnimacaoAtual = andarBaixo;
    }
    else
    {
        AnimacaoAtual = andarCima;
    }

    if (Offset.x > 40.0f)
    {
        AnimacaoAtual = andarDireita;
    }
    else if (Offset.x < -40.0f)
    {
        AnimacaoAtual = andarEsquerda;
    }
}

void Tripulante::Draw(){
    Entidade::Draw();
}

void Tripulante::Ataque(){
    setEstadoPor(ATACANDO,0);
    setVelocidade(3.5f);

}