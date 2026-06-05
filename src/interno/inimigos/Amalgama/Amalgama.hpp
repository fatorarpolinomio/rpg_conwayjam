#ifndef AMALGAMA_H
#define AMALGAMA_H

#include "../inimigos.hpp"

class Amalgama : public Inimigo{

    public:
        Amalgama(double max, double regen, double infec, double dano);

};

#endif