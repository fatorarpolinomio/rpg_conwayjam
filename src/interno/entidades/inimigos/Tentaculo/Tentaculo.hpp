#ifndef TENTACULO_H
#define TENTACULO_H

#include "../inimigos.hpp"

class Tentaculo : public Inimigo{

    private:
        bool ativo = false;
        bool aparecer = true;
        bool sumir = true;

    public:
        Tentaculo(double max, double regen, double infec, double dano);

        void Ataque() override;
        void Update() override;
        void Draw() override;
        void Seguir(Vector2 pos) override;
};

#endif