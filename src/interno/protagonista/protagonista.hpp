#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <cstdlib>
#include <string>
#include <raylib.h>
#include <vector>

using namespace std;

class Protagonista {

	private:
		int integridade;
		int oxigenio;
		int nivelInfeccao;
		double velocidade = .02f;
		Vector2 posicao;

		bool andando = false;

		// Variaveis da animação
		Texture2D spritesheet;
		vector<Rectangle> AnimacaoAtual;
		

		vector<Rectangle> idle;
		vector<Rectangle> andarCima;
		vector<Rectangle> andarBaixo;
		vector<Rectangle> andarEsquerda;
		vector<Rectangle> andarDireita;

		double tempoAteProxSprite;
		int frameAtual = 0;

	public:
		Protagonista(Vector2 pos);

		Vector2 getPosicao(){ return posicao; }

		bool diminuirIntegridade(int dano);
		bool diminuirOxigenio(int vazamento);
		void diminuirNivelInfeccao(int recuperacao);

		void aumentarIntegridade(int recuperacao);
		void aumentarOxigenio(int recuperacao);
		bool aumentarNivelInfeccao(int dano);

		void setPosicao(Vector2 pos){ posicao = pos; }
		
		void Update();
		void Draw();

		void setIntegridade(int novaIntegridade) {integridade = novaIntegridade;}

		void setOxigenio(int novoOxigenio) {oxigenio = novoOxigenio;}

		void setInfeccao(int novoNivelInfeccao) {nivelInfeccao = novoNivelInfeccao;}

		int getIntegridade() {return integridade;}

		int getOxigenio() {return oxigenio;}

		int getInfeccao() {return nivelInfeccao;}

};

#endif 
