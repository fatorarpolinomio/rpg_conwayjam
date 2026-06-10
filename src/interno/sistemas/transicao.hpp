#pragma once
#include "../estados/estados.hpp"
#include <raylib.h>

class Transicao{
private:
    bool emTransicao;
    bool escurecendo;
    float alphaTransicao;
    float velocidadeFade;
    GameState estadoAlvo;
public:
    Transicao(float velocidade = 5.0f);
    void Iniciar(GameState alvo);
    void Update(GameState& estadoAtual);

    void Draw(int screenWidth, int screenHeight);

    bool IsAtiva() const;

};
