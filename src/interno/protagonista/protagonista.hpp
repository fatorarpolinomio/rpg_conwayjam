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

		void Protagonista::setIntegridade(int novaIntegridade) {integridade = novaIntegridade;}

		void Protagonista::setOxigenio(int novoOxigenio) {oxigenio = novoOxigenio;}

		void Protagonista::setInfeccao(int novoNivelInfeccao) {nivelInfeccao = novoNivelInfeccao;}

		int Protagonista::getIntegridade() {return integridade;}

		int Protagonista::getOxigenio() {return oxigenio;}

		int Protagonista::getInfeccao() {return nivelInfeccao;}

};

#endif 
