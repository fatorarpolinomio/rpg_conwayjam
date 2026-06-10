#ifndef ITENS_H
#define ITENS_H

#include <stdlib.h>
#include <string>

class Item {
private:
    std::string nome;
    std::string tipo;
    double dano;
    double regeneracao;
    std::string alvo;
    Texture2D sprite;

public:
    Item();


    std::string GetTipo() {return tipo;}
    double GetDano() {return dano;}
    double GetRegeneracao() {return regeneracao;}
    std::string GetAlvo() {return alvo;}
	Texture2D GetSprite() {return sprite;}

    void SetTipo(std::string newTipo) {tipo = newTipo;}
    void SetDano(double newDano) {dano = newDano;}
    void SetRegeneracao(double newReg) {regeneracao = newReg;}
    void SetAlvo(std::string newAlvo) {alvo = newAlvo;}
	void SetSprite(Texture2D newSprite) {sprite = newSprite;}

    void Use(Item item, Protagonista& protagonista, Inimigo& inimigo);

};
#endif