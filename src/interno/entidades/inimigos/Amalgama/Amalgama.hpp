#ifndef AMALGAMA_H
#define AMALGAMA_H

#include "../inimigos.hpp"

class Amalgama : public Inimigo{

    public:
        Amalgama(double max, double regen, double infec, double dano);

        void Update() override;
        void Draw() override;
        void Ataque() override;
};

#endif