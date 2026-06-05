#include <cstdlib>
#include <string>

#include "protagonista.hpp"


Protagonista::Protagonista() {
	integridade = 100;
	oxigenio = 100;
	nivelInfeccao = 0;
}

// getters e setters ------------------------------------
void Protagonista::setIntegridade(int novaIntegridade) {
	integridade = novaIntegridade;
}

void Protagonista::setOxigenio(int novoOxigenio) {
	oxigenio = novoOxigenio;
}

void Protagonista::setInfeccao(int novoNivelInfeccao) {
	nivelInfeccao = novoNivelInfeccao;
}

int Protagonista::getIntegridade() {
	return integridade;
}

int Protagonista::getOxigenio() {
	return oxigenio;
}

int Protagonista::getInfeccao() {
	return nivelInfeccao;
}

// funcoes ------------------------------------

bool Protagonista::diminuirIntegridade(int dano) {
	integridade -= integridade - dano;

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
	nivelInfeccao += nivelInfeccao;

	// se passar de 100, envia um estado para morrer
	if (nivelInfeccao >= 100)
		return false;
	return true;
	
}

