#pragma once

#include "../entidades/protagonista/protagonista.hpp"
#include "../entidades/inimigos/inimigos.hpp"

class Globais{
    private:
        static Protagonista *violeta;

    public:
        static vector<Inimigo*> Inimigos;
        Globais(Protagonista *player);
        Globais(){}

        static Protagonista* GetPlayer(){return violeta;}

};