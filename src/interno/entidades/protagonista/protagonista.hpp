#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <cstdlib>
#include <string>
#include <raylib.h>
#include <vector>
#include "../entidade.hpp"

using namespace std;

class Protagonista : public Entidade {

	private:
		int integridade;
		int oxigenio;
		int nivelInfeccao;

		// Audio
		Sound passos;


	public:
		Protagonista(Vector2 pos);

		bool diminuirIntegridade(int dano);
		bool diminuirOxigenio(int vazamento);
		void diminuirNivelInfeccao(int recuperacao);

		void aumentarIntegridade(int recuperacao);
		void aumentarOxigenio(int recuperacao);
		bool aumentarNivelInfeccao(int dano);

		void setIntegridade(int novaIntegridade) {integridade = novaIntegridade;}

		void setOxigenio(int novoOxigenio) {oxigenio = novoOxigenio;}

		void setInfeccao(int novoNivelInfeccao) {nivelInfeccao = novoNivelInfeccao;}

		int getIntegridade() {return integridade;}

		int getOxigenio() {return oxigenio;}

		int getInfeccao() {return nivelInfeccao;}

		void Update() override;
		void Draw() override;

};

#endif
