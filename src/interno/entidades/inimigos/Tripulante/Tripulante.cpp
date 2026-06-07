#include "Tripulante.hpp"
#include <algorithm>
#include "../../../sistemas/globais.hpp"
#include <raymath.h>

Tripulante::Tripulante(double max, double regen, double infec, double dano)
    : Inimigo(max,regen,infec,dano){
        velocidade = .005f;

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
    Globais::Inimigos.erase(remove(Globais::Inimigos.begin(), Globais::Inimigos.end(), this));
    //Animação de morte e logica também
}

void Tripulante::Update(){
    if(GetVida() <= 0){
        Morrer();
    }

    if (tempoAteProxSprite <= 0) {
        frameAtual++;
        if (frameAtual >= AnimacaoAtual.size()) {
          frameAtual = 1;
        }
        tempoAteProxSprite = .35f;
    }

    Protagonista *player = Globais::GetPlayer();
    
    // Seguir player
    Vector2 seguindoPlayer = Vector2MoveTowards(getPosicao(),player->getPosicao(),velocidade);
    setPosicao(seguindoPlayer);

    // Mudar animação de acordo com sa posição do player
    Vector2 Offset = Vector2Subtract(player->getPosicao(), getPosicao());

    if(Offset.x > 0.0f){
        AnimacaoAtual = andarDireita;
    }else{
        AnimacaoAtual = andarEsquerda;
    }

    if(Offset.y > 80.0f){
        AnimacaoAtual = andarBaixo;
    }else if(Offset.y < -80.0f){
        AnimacaoAtual = andarCima;
    }


    // Atacar se chegar perto
    if(Vector2Distance(player->getPosicao(), getPosicao()) < 100.0f) Ataque();
    else setVelocidade(GetMaxVelocidade());


    andando = true;
    if (andando) {
        tempoAteProxSprite -= GetFrameTime() * velocidade * 100;
    }
}

void Tripulante::Draw(){
  if (!andando) {
    frameAtual = 0;
  }
  DrawTextureRec(spritesheet, AnimacaoAtual[frameAtual], getPosicao(), WHITE);
}

void Tripulante::Ataque(){

    setVelocidade(0.05f);

}