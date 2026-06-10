#include <cstdlib>
#include <raylib.h>
#include <string>
#include <iostream>
#include <cmath>
#include "../../cenario/mapa.hpp"
#include "protagonista.hpp"

Protagonista::Protagonista(Vector2 pos) {
    velocidade = 1.0f;
    frameAtual = 0;
    setDepth(10);

  spritesheet =
      LoadTexture("../../../assets/Spritesheets/Protagonista/protagonista.png");
  passos = LoadSound("../../../assets/audio/sfx/caminhando.wav");
  SetMasterVolume(0.3f);

  hudTexture = LoadTexture("../../../assets/Spritesheets/UI/HUD.png");
  itemAtualImage = LoadImage("../../../assets/Spritesheets/Itens/KeyCard.png");
  ImageResizeNN(&itemAtualImage, 96, 96);
  itemAtualTexture = LoadTextureFromImage(itemAtualImage);
  UnloadImage(itemAtualImage);

  // Animações
  andarCima = {
      Rectangle{128, 64, 64, 64},
      Rectangle{192, 64, 64, 64},
      Rectangle{0, 128, 64, 64},
  };
  andarDireita = {
      Rectangle{64, 128, 64, 64},
      Rectangle{128, 128, 64, 64},
      Rectangle{192, 128, 64, 64},
  };
  andarEsquerda = {
      Rectangle{192, 0, 64, 64},
      Rectangle{0, 64, 64, 64},
      Rectangle{64, 64, 64, 64}
  };
  andarBaixo = {
      Rectangle{0, 0, 64, 64},
      Rectangle{64, 0, 64, 64},
      Rectangle{128, 0, 64, 64},
  };
  idle = {
      Rectangle{0, 0, 64, 64},
  };
  AnimacaoAtual = idle;


  posicao = pos;
  integridade = 100;
  oxigenio = 100;
  nivelInfeccao = 0;

  setCaixaColisao(Rectangle{10,48,40,16});

}

// funcoes ------------------------------------

void Protagonista::Update() {
  Entidade::Update();
  if (!IsSoundPlaying(passos)) {
    PlaySound(passos);
  }


  setEstadoPor(PARADO,0);

  // Fazer um metodo pra Input?
  if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !Mapa::estaCollidindo(Vector2{(float)(1+velocidade),0}, getCaixaColisao())){
    posicao.x += velocidade;
    AnimacaoAtual = andarDireita;

    setEstadoPor(ANDANDO, 0);
  }
  if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && !Mapa::estaCollidindo(Vector2{(float)(-1-velocidade),0}, getCaixaColisao())) {
    posicao.x -= velocidade;
    AnimacaoAtual = andarEsquerda;

    setEstadoPor(ANDANDO, 0);
  }
  if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && !Mapa::estaCollidindo(Vector2{0,(float)(-1-velocidade)}, getCaixaColisao())){
    posicao.y -= velocidade;
    AnimacaoAtual = andarCima;

    setEstadoPor(ANDANDO, 0);
  }
  if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && !Mapa::estaCollidindo(Vector2{0,(float)(1+velocidade)}, getCaixaColisao())){
    posicao.y += velocidade;
    AnimacaoAtual = andarBaixo;

    setEstadoPor(ANDANDO, 0);
  }

  if(getEstado() == ANDANDO) {
    ResumeSound(passos);
  }else {
    PauseSound(passos);
  }
}

void Protagonista::Draw() {
  Entidade::Draw();
}

void Protagonista::DrawHUD() {
    float TamanhoBarraHUDX = 72* 3;
	float TamanhoBarraHUDY = 15* 3;
    float infeccaoTreze = 13 - ceil(Protagonista::getInfeccao() * 0.13f);
	float integridadeTreze = 13 - ceil(Protagonista::getIntegridade() * 0.13f);
	float oxigenioTreze = 13 - ceil(Protagonista::getOxigenio() * 0.13f);
  DrawTextureRec(hudTexture, {0*TamanhoBarraHUDX, TamanhoBarraHUDY * infeccaoTreze, TamanhoBarraHUDX, TamanhoBarraHUDY} , {20, 40}, WHITE);
  DrawTextureRec(hudTexture, {1*TamanhoBarraHUDX, TamanhoBarraHUDY * oxigenioTreze, TamanhoBarraHUDX, TamanhoBarraHUDY }, {20, 100}, WHITE);
  DrawTextureRec(hudTexture, {2*TamanhoBarraHUDX, TamanhoBarraHUDY * integridadeTreze, TamanhoBarraHUDX, TamanhoBarraHUDY }, {20, 150}, WHITE);
  //Nn precisa mais do item no HUD, pq arma tem sprite, e consumível e chave só some.
}

bool Protagonista::diminuirIntegridade(int dano) {
  integridade -= dano;
  setEstadoPor(DANO, 1);

  // retorna um estado caso sofra mais dado que deveria
  if (integridade <= 0)
    return false;
  return true;
}

bool Protagonista::diminuirOxigenio(int vazamento) {
  oxigenio -= oxigenio - vazamento;

  // retorna um estado caso oxigenio chegue a 0, para saber se morreu
  if (oxigenio <= 0)
    return false;
  return true;
}

void Protagonista::diminuirNivelInfeccao(int recuperacao) {
  nivelInfeccao -= recuperacao;

  if (nivelInfeccao < 0)
    nivelInfeccao = 0; // não permite ser negativo
}

void Protagonista::aumentarIntegridade(int recuperacao) {
  integridade += recuperacao;

  if (integridade > 100)
    integridade = 100; // não deixa passar de 100
}

void Protagonista::aumentarOxigenio(int recuperacao) {
  oxigenio += recuperacao;

  if (oxigenio > 100)
    oxigenio = 100; // não deixa passar de 100
}

bool Protagonista::aumentarNivelInfeccao(int dano) {
  nivelInfeccao += dano - (integridade/10);

  // se passar de 100, envia um estado para morrer
  if (nivelInfeccao >= 100)
    return false;
  return true;
}

Vector2 Protagonista::GetTargetPosicao(){
  return Vector2{getPosicao().x+32, getPosicao().y+32};
}
