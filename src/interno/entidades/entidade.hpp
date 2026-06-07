#pragma once

#include <raylib.h>
#include <vector>

using namespace std;

class Entidade {
protected:
  Vector2 posicao;
  double velocidade;

  bool andando = false;

  vector<Rectangle> idle;
  vector<Rectangle> andarCima;
  vector<Rectangle> andarBaixo;
  vector<Rectangle> andarEsquerda;
  vector<Rectangle> andarDireita;

  // Variaveis da animação
  Texture2D spritesheet;
  vector<Rectangle> AnimacaoAtual;

  double tempoAteProxSprite;
  int frameAtual = 0;

public:
  // Construtor
  Entidade(){}

  // Destrutor
  ~Entidade(){}

  // Getters
  Vector2 getPosicao() { return posicao; }
  double getVelocidade() { return velocidade; }
  Texture2D getSpritesheet(){return spritesheet;}
  vector<Rectangle> getIdle() { return idle; }
  vector<Rectangle> getAndarCima() { return andarCima; }
  vector<Rectangle> getAndarBaixo() { return andarBaixo; }
  vector<Rectangle> getAndarEsquerda() { return andarEsquerda; }
  vector<Rectangle> getAndarDireita() { return andarDireita; }
  vector<Rectangle> getAnimacaoAtual() { return AnimacaoAtual; }


  // Setters
  void setPosicao(Vector2 novaPosicao) { this->posicao = novaPosicao; }
  void setVelocidade(double novaVelocidade) {
    this->velocidade = novaVelocidade;
  }
  void setSpritesheet(Texture2D newSpritesheet){this->spritesheet = newSpritesheet;}
  void setIdle(vector<Rectangle> newIdle) { this->idle = newIdle; }
  void setAndarCima(vector<Rectangle> newAndarCima) { this->andarCima = newAndarCima; }
  void setAndarBaixo(vector<Rectangle> newAndarBaixo) { this->andarBaixo = newAndarBaixo; }
  void setAndarEsquerda(vector<Rectangle> newAndarEsquerda) { this->andarEsquerda = newAndarEsquerda; }
  void setAndarDireita(vector<Rectangle> newAndarDireita) { this->andarDireita = newAndarDireita; }
  void setAnimacaoAtual(vector<Rectangle> newAnimacaoAtual) { this->AnimacaoAtual = newAnimacaoAtual; }

  virtual void Update() = 0; // Atualização da entidade a cada frame
  virtual void Draw() = 0;   // Desenha entidade a cada frame
};
