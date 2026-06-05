#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <cstdlib>
#include <string>

class Protagonista {

	private:
		int integridade;
		int oxigenio;
		int nivelInfeccao;

	public:
		Protagonista();

		bool diminuirIntegridade(int dano);
		bool diminuirOxigenio(int vazamento);
		void diminuirNivelInfeccao(int recuperacao);

		void aumentarIntegridade(int recuperacao);
		void aumentarOxigenio(int recuperacao);
		bool aumentarNivelInfeccao(int dano);

		void setIntegridade(int novaIntegridade);
		void setOxigenio(int novoOxigenio);
		void setInfeccao(int novoNivelInfeccao);

		int getIntegridade();
		int getOxigenio();
		int getInfeccao();

};

#endif 
