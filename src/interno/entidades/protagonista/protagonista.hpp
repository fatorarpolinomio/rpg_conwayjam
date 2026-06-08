#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../../sistemas/camera.hpp"

#include <cstdlib>
#include <string>
#include <raylib.h>
#include <vector>
#include "../entidade.hpp"

using namespace std;

class Protagonista : public Entidade, public CameraTarget{

	private:
		double integridade;
		double oxigenio;
		double nivelInfeccao;

		// Audio
		Sound passos;


	public:
		Protagonista(Vector2 pos);

		Vector2 GetTargetPosicao() override;

		Vector2 getPosicao(){ return posicao; }

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
