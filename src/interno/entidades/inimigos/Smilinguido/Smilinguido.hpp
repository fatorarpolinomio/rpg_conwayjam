#ifndef SMILINGUIDO_H
#define SMILINGUIDO_H

#include "../inimigos.hpp"

class Smilinguido : public Inimigo{

    public:
        Smilinguido(double max, double regen, double infec, double dano);

};

#endif