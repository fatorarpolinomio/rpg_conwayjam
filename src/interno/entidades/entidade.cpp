#include "entidade.hpp"
#include <iostream>
#include "../sistemas/globais.hpp"

Entidade::Entidade(){
  Globais::adicionaraListaRenderizacao(this);
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
    // 1ª Camada de Segurança
    if (AnimacaoAtual.empty()) return;

    // Aproveitei para corrigir um pequeno bug de precedência lógica do C++ aqui:
    // O correto é getEstado() != ANDANDO em vez de !getEstado() == ANDANDO
    if (getEstado() != ANDANDO) {
        frameAtual = 0;
    } else if(getEstado() == ANDANDO) {
        if(frameAtual == 0) frameAtual = 1;
    }

    // 2ª Camada de Segurança Anti-Crash
    int frameSeguro = frameAtual % AnimacaoAtual.size();
    DrawTextureRec(spritesheet, AnimacaoAtual[frameSeguro], getPosicao(), WHITE);
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
