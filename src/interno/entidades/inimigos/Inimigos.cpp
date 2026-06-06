#include "inimigos.hpp"

Inimigo::Inimigo(double max, double regen, double infec, double dano)
    :MaxVida(Vida), TaxaRegen(regen), TaxaInfec(infec), Dano(dano){
        Vida = MaxVida;
    }