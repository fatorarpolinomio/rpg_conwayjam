#include <cstdlib>
#include <raylib.h>
#include <string>
#include <iostream>
#include <cmath>
#include "../../cenario/mapa.hpp"
#include "protagonista.hpp"
#include <raymath.h>                 
#include "../../sistemas/globais.hpp" 

Protagonista::Protagonista(Vector2 pos) {
    velocidade = 1.0f;
    frameAtual = 0;
    setDepth(10);

    estadoDanoAtual = EstadoProtagonista::NORMAL;
    tempoAnimacaoDano = 0.0f;
    duracaoDano = 0.4f;
    spriteDano = Rectangle{0, 192, 64, 64};

    spritesheet = LoadTexture("../../../assets/Spritesheets/Protagonista/protagonista.png");
    passos = LoadSound("../../../assets/audio/sfx/caminhando.wav");
    SetMasterVolume(0.3f);

    hudTexture = LoadTexture("../../../assets/Spritesheets/UI/HUD.png");
    itemAtualImage = LoadImage("../../../assets/Spritesheets/Itens/KeyCard.png");
    ImageResizeNN(&itemAtualImage, 96, 96);
    itemAtualTexture = LoadTextureFromImage(itemAtualImage);
    UnloadImage(itemAtualImage);

    texturaMorte = LoadTexture("../../../assets/Spritesheets/Protagonista/protagonista morte.png");
    for (int i = 0; i < 2; i++) {
        framesMorte.push_back(Rectangle{0, (float)i * 64, 64, 64});
    }
    frameMorteAtual = 0;
    temporizadorMorte = 0.0f;

  // Animações
  atacarEsquerda = {
        Rectangle{64, 192, 64, 64},  // Levanta o machado
        Rectangle{128, 192, 64, 64}  // Desce o machado
    };

  atacarDireita = {
        Rectangle{192, 192, 64, 64}, // Levanta o machado
        Rectangle{0, 256, 64, 64}    // Desce o machado
    };
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

  somProximidade = LoadSound("../../../assets/audio/sfx/scare.wav");
  SetSoundVolume(somProximidade, 0.0f); 
}

// funcoes ------------------------------------

void Protagonista::Update() {
    float raioMaximo = 100.0f;
    float menorDistancia = raioMaximo;
    bool inimigoPerto = false;


    if (!IsSoundPlaying(passos)) {
        PlaySound(passos);
    }

    setEstadoPor(PARADO, 0);

    if (estadoDanoAtual == EstadoProtagonista::MORTO) return;

    if (estadoDanoAtual == EstadoProtagonista::MORTO) {
            return;
    }

    if (tempoAnimacaoDano > 0) {
        tempoAnimacaoDano -= GetFrameTime(); // Conta os segundos para trás
        if (tempoAnimacaoDano <= 0) {
            estadoDanoAtual = EstadoProtagonista::NORMAL;
        }
    }


    if (atacando) {
            tempoAtaque -= GetFrameTime();

            // Controle manual dos frames do machado
            if (tempoAtaque > 0.15f|| AnimacaoAtual.size() <= 1) {
                frameAtual = 0; // Primeiros 0.15s: Mantém no Frame 0 (Levantando o machado)
            } else {
                frameAtual = 1; // Últimos 0.15s: Pula para o Frame 1 (Descendo o machado)
            }

            if (tempoAtaque <= 0.0f) {
                atacando = false;
                AnimacaoAtual = idle; // Terminou de bater
                frameAtual = 0;       // Reseta o frame para não dar erro
            }
        }

    if (!atacando) {
        // GATILHO DO ATAQUE
        if (IsKeyPressed(KEY_SPACE)) {
            atacando = true;
            tempoAtaque = 0.2f; // Ajuste para ficar sincronizado com os frames da arma

            if (direcaoAtual == ESQUERDA || direcaoAtual == BAIXO) {
                AnimacaoAtual = atacarEsquerda;
            } else {
                AnimacaoAtual = atacarDireita;
            }
        }
        else {
            if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && !Mapa::estaCollidindo(Vector2{(float)(1+velocidade),0}, getCaixaColisao())){
                posicao.x += velocidade;
                AnimacaoAtual = andarDireita;
                direcaoAtual = DIREITA;
                setEstadoPor(ANDANDO, 0);
            }
            else if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && !Mapa::estaCollidindo(Vector2{(float)(-1-velocidade),0}, getCaixaColisao())) {
                posicao.x -= velocidade;
                AnimacaoAtual = andarEsquerda;
                direcaoAtual = ESQUERDA;
                setEstadoPor(ANDANDO, 0);
            }
            else if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && !Mapa::estaCollidindo(Vector2{0,(float)(-1-velocidade)}, getCaixaColisao())){
                posicao.y -= velocidade;
                AnimacaoAtual = andarCima;
                direcaoAtual = CIMA;
                setEstadoPor(ANDANDO, 0);
            }
            else if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && !Mapa::estaCollidindo(Vector2{0,(float)(1+velocidade)}, getCaixaColisao())){
                posicao.y += velocidade;
                AnimacaoAtual = andarBaixo;
                direcaoAtual = BAIXO;
                setEstadoPor(ANDANDO, 0);
            }
        }
    }

    // Controle do áudio dos passos
    if (getEstado() == ANDANDO) {
        ResumeSound(passos);
    } else {
        PauseSound(passos);
    }


    for (Inimigo* inimigo : Globais::Inimigos) {
        if (inimigo != nullptr) {
            float distancia = Vector2Distance(this->getPosicao(), inimigo->getPosicao());
            if (distancia < raioMaximo) {
                inimigoPerto = true;
                if (distancia < menorDistancia) {
                    menorDistancia = distancia; 
                }
            }
        }
    }

    if (inimigoPerto && estadoDanoAtual != EstadoProtagonista::MORTO) {
        if (!IsSoundPlaying(somProximidade)) {
            PlaySound(somProximidade);
        }
        SetSoundVolume(somProximidade, 1.0f);
    }
    else {
        if (IsSoundPlaying(somProximidade)) {
            StopSound(somProximidade);
        }
    }


    Entidade::Update();
}

void Protagonista::Morrer() {
    if (estadoDanoAtual != EstadoProtagonista::MORTO) {
        estadoDanoAtual = EstadoProtagonista::MORTO;
        frameMorteAtual = 0;
        temporizadorMorte = 0.0f;
    }
}

void Protagonista::Draw() {
    // 1ª Camada de Segurança: Nunca tenta desenhar se o vetor estiver vazio
    if (AnimacaoAtual.empty()) return;

    if (estadoDanoAtual == EstadoProtagonista::MORTO) {

            temporizadorMorte += GetFrameTime();
            if (temporizadorMorte >= 0.15f) {
                temporizadorMorte = 0.0f;

                if (frameMorteAtual < framesMorte.size() - 1) {
                    frameMorteAtual++;
                }
            }

            // Desenha a textura específica de morte
            DrawTextureRec(texturaMorte, framesMorte[frameMorteAtual], getPosicao(), WHITE);

    }
    else if (estadoDanoAtual == EstadoProtagonista::TOMANDO_DANO) {

            Color tintura = WHITE;
            if ((int)(tempoAnimacaoDano * 15) % 2 == 0) {
                tintura = RED;
            } else {
                tintura = Color{255, 255, 255, 150};
            }

            DrawTextureRec(spritesheet, spriteDano, getPosicao(), tintura);
    }
    else if (atacando) {
        int frameSeguro = frameAtual % AnimacaoAtual.size();
        DrawTextureRec(spritesheet, AnimacaoAtual[frameSeguro], getPosicao(), WHITE);
    } else {
        Entidade::Draw();
    }
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

Rectangle Protagonista::getHitboxAtaque() {
    // Pega a base de colisão atual da Violeta
    Rectangle caixa = getCaixaColisao();

    float alcance = 32.0f; // O quão longe a arma acerta
    float larguraGolpe = 45.0f; // A "largura" do arco do golpe

    if (direcaoAtual == ESQUERDA) {
        caixa.x -= alcance; // Joga para a esquerda
        caixa.width = alcance;
        caixa.height = larguraGolpe;
        caixa.y -= (larguraGolpe - getCaixaColisao().height) / 2.0f; // Centraliza no eixo Y
    }
    else if (direcaoAtual == DIREITA) {
        caixa.x += getCaixaColisao().width; // Joga para a direita
        caixa.width = alcance;
        caixa.height = larguraGolpe;
        caixa.y -= (larguraGolpe - getCaixaColisao().height) / 2.0f; // Centraliza no eixo Y
    }

    return caixa;
}

void Protagonista::TomaDano() {
    if (estadoDanoAtual != EstadoProtagonista::TOMANDO_DANO) {
        estadoDanoAtual = EstadoProtagonista::TOMANDO_DANO;
        tempoAnimacaoDano = duracaoDano;
    }
}

bool Protagonista::diminuirIntegridade(int dano) {
  integridade -= dano;
  setEstadoPor(DANO, 1);

  TomaDano();

  // retorna um estado caso sofra mais dado que deveria
  if (integridade <= 0) return false;

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
