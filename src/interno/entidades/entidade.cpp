#include "entidade.hpp"
#include <iostream>

void Entidade::Update(){
    if (tempoAteProxSprite <= 0) {
        frameAtual++;
        if (frameAtual >= AnimacaoAtual.size()) {
          frameAtual = 1;
        }
        tempoAteProxSprite = .35f;
    }

    if (getEstado() == ANDANDO) {
        tempoAteProxSprite -= 1 * GetFrameTime();
    }

    Rectangle col = Rectangle{getPosicao().x + caixaDeColisao.x, getPosicao().y + caixaDeColisao.y, caixaDeColisao.width, caixaDeColisao.height};
    caixaDeColisaoAtualizada = col;
    
    if(timer > 0) timer -= 1 * GetFrameTime();
}

void Entidade::Draw(){
  if (!getEstado() == ANDANDO) {
    frameAtual = 0;
  }else if(getEstado() == ANDANDO){ // Talvez tenha um jeito melhor, mas foi assim que eu tirei aquele delay antes de começar a animação
    if(frameAtual == 0) frameAtual = 1;
  }
  DrawTextureRec(spritesheet, AnimacaoAtual[frameAtual], getPosicao(), WHITE);
}

void Entidade::setEstadoPor(estadosEntidade newEstado, float tempo){

  if(timer > 0) return;

  
  timer = tempo;

  estado = newEstado;

}

void Entidade::setEstadoPor(estadosEntidade newEstado, float tempo, bool override){

  if(!override){
    if(timer > 0) return;
  }
  
  timer = tempo;

  estado = newEstado;

}