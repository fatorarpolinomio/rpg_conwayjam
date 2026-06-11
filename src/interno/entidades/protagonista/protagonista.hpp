#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../../sistemas/camera.hpp"

#include <cstdlib>
#include <string>
#include <raylib.h>
#include <vector>
#include "../entidade.hpp"


using namespace std;
enum Direcao { CIMA, DIREITA, BAIXO, ESQUERDA };
enum class EstadoProtagonista {NORMAL, TOMANDO_DANO, MORTO};

class Protagonista : public Entidade, public CameraTarget {

private:
	Sound somProximidade;

	double integridade;
	double oxigenio;
	double nivelInfeccao;

	Texture2D hudTexture;
	Texture2D itemFundoTexture;
	Texture2D marteloIconTexture;
	Texture2D taserIconTexture;
	std::string itemAtual;

	Direcao direcaoAtual;
	bool atacando;
	float tempoAtaque;

	std::vector<Rectangle> atacarEsquerdaMartelo;
	std::vector<Rectangle> atacarDireitaMartelo;
	std::vector<Rectangle> atacarEsquerdaTaser;
	std::vector<Rectangle> atacarDireitaTaser;
	

	// VARIÁVEIS DE ANIMAÇÃO DE DANO
	EstadoProtagonista estadoDanoAtual;
	float tempoAnimacaoDano;
	float duracaoDano;
	Rectangle spriteDano;

	// VARIÁVEIS DE MORTE
	Texture2D texturaMorte;
	std::vector<Rectangle> framesMorte;
	int frameMorteAtual;
	float temporizadorMorte;

public:
	// Audio
	Sound passos;

	void PausarSons();

	Protagonista(Vector2 pos);

	Vector2 GetTargetPosicao() override;

	Vector2 getPosicao() { return posicao; }

	Rectangle getHitboxAtaque();
	bool isAtacando() const { return atacando; }
	Direcao getDirecaoAtual() const { return direcaoAtual; }

	bool diminuirIntegridade(int dano);
	bool diminuirOxigenio(int vazamento);
	void diminuirNivelInfeccao(int recuperacao);

	void aumentarIntegridade(int recuperacao);
	void aumentarOxigenio(int recuperacao);
	bool aumentarNivelInfeccao(int dano);

	void setIntegridade(int novaIntegridade) { integridade = novaIntegridade; }
	void setOxigenio(int novoOxigenio) { oxigenio = novoOxigenio; }
	void setInfeccao(int novoNivelInfeccao) { nivelInfeccao = novoNivelInfeccao; }
	void setItemAtual(std::string novoItem) { itemAtual = novoItem; }

	int getIntegridade() { return integridade; }
	int getOxigenio() { return oxigenio; }
	int getInfeccao() { return nivelInfeccao; }
	std::string getItemAtual(){return itemAtual;}

	void TomaDano();
	void Update() override;
	void Draw() override;
	void DrawHUD();
	void Morrer();

};

#endif
