#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include "../inimigos.hpp"

class Tripulante : public Inimigo{

    public:
        Tripulante(double max, double regen, double infec, double dano);

};

#endif