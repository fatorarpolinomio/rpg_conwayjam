#ifndef ITENS_H
#define ITENS_H

#include <stdlib.h>
#include <string>

class Item : public Entidade {
private:
    std::string tipo;
    double taxa;
    std::string alvo;
    Vector2 posicao;
    Texture2D sprite;

public:
    Item(std::string tipo, double taxa, std::string alvo, const char *caminhoSpritesheet, Vector2 Posicao);


    std::string GetTipo() {return tipo;}
    double GetTaxa() {return taxa;}
    std::string GetAlvo() {return alvo;}
	Texture2D GetSprite() {return sprite;}
    Vector2 GetPosicao() {return posicao;}

    void SetTipo(std::string newTipo) {tipo = newTipo;}
    void SetTaxa(double newTaxa) {taxa = newTaxa;}
    void SetAlvo(std::string newAlvo) {alvo = newAlvo;}
	void SetSprite(Texture2D newSprite) {sprite = newSprite;}
    void SetPosicao(Vector2 newPosicao) {posicao = newPosicao;}

    void Get(Item item, Protagonista& protagonista);

    virtual void Draw();

};
#endif