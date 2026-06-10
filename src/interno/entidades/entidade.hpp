#pragma once

#include <raylib.h>
#include <vector>

using namespace std;

enum estadosEntidade{
    PARADO,
    ANDANDO,
    ATACANDO,
    DANO,
    STUNNED // Não sei se precisa desse, talvez possa usar só o PARADO
};

// Talvez seja bom essa classe ficar com alguns atributos que funcionam igual para o player e os inimigos
// A classe tomar dano acho que os dois usam
class Entidade {
protected:
  Vector2 posicao;
  Rectangle caixaDeColisaoAtualizada;
  Rectangle caixaDeColisao;
  double velocidade;

  estadosEntidade estado = PARADO; 

  vector<Rectangle> idle;
  vector<Rectangle> andarCima;
  vector<Rectangle> andarBaixo;
  vector<Rectangle> andarEsquerda;
  vector<Rectangle> andarDireita;

  float timer = 0;

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
  estadosEntidade getEstado(){ return estado;}
  Rectangle getCaixaColisao(){ return caixaDeColisaoAtualizada;}
  float getCaixaColisaoWidth(){ return caixaDeColisao.width;}
  float getCaixaColisaoHeight(){ return caixaDeColisao.height;}


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
  void setEstadoIntantaneo(estadosEntidade newEstado){estado = newEstado;} // Para quando querer mudar o estado imediatamente, sem se importar se acabou o tempo do estado anterior
  void setEstadoPor(estadosEntidade newEstado, float tempo); // Mudar o estado por um tempo, ignora outras mudanças de estado se o tempo do estado não tiver acabado(a menos que use o setEstadoInstantaneo). Geralmente use esse com o tempo = 0
  void setEstadoPor(estadosEntidade newEstado, float tempo, bool override); // Mudar o estado por um tempo, ignora outras mudanças de estado se o tempo do estado não tiver acabado(a menos que use o override = true). Geralmente use esse com o tempo = 0
  void setCaixaColisao(Rectangle novaCaixa){ caixaDeColisao = novaCaixa;}

  virtual void Update(); // Atualização da entidade a cada frame
  virtual void Draw();   // Desenha entidade a cada frame
};
