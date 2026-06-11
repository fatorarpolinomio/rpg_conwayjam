#include "entidade.hpp"
#include <iostream>
#include "../sistemas/globais.hpp"

Entidade::Entidade(){
  Globais::adicionaraListaRenderizacao(this);
}

Entidade::~Entidade(){
  Globais::removerListaRenderizacao(this);
}

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
    if (AnimacaoAtual.empty()) return;

    if (!getEstado() == ANDANDO) {
        frameAtual = 0;
    } else if(getEstado() == ANDANDO) {
        if(frameAtual == 0) frameAtual = 1;
    }

    int frame = frameAtual % AnimacaoAtual.size();
    DrawTextureRec(spritesheet, AnimacaoAtual[frame], getPosicao(), WHITE);
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
