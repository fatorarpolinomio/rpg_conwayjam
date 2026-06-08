#pragma once
#include <raylib.h>
#include <vector>

struct estrela{
    Vector2 posicao;
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
        void adiciona_estrela(double x, double y);
        std::vector<estrela>& getEstrelas(){
            return this->estrelas;
        }
};

void atualiza_estrelas(std::vector<estrela>& estrelas);
void remove_estrelas(double limite_horizontal, std::vector<estrela>& estrelas);
