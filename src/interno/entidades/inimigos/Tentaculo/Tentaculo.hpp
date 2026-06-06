#ifndef TENTACULO_H
#define TENTACULO_H

#include "../inimigos.hpp"

class Tentaculo : public Inimigo{

    public:
        Tentaculo(double max, double regen, double infec, double dano);

};

#endif