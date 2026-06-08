#pragma once
#include <raylib.h>
#include <vector>
#include <random>

struct estrela{
    Vector2 posicao{float(std::rand() % 400), 0};
    void desenhar(){
        DrawCircle(this->posicao.x, this->posicao.y, 1, WHITE);
    }
};

class Espaco{
    protected:
        std::vector<estrela> estrelas;

    public:
        Espaco(){}
        ~Espaco(){}
        void adiciona_estrela();
        void atualiza_estrelas();


};
