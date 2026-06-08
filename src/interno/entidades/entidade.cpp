#include "entidade.hpp"

void Entidade::Update(){
    if (tempoAteProxSprite <= 0) {
        frameAtual++;
        if (frameAtual >= AnimacaoAtual.size()) {
          frameAtual = 1;
        }
        tempoAteProxSprite = .35f;
    }

    if (getEstado() == ANDANDO) {
        tempoAteProxSprite -= 1 *GetFrameTime();
    }

    caixaDeColisao = Rectangle{getPosicao().x, getPosicao().y, 32,54};

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