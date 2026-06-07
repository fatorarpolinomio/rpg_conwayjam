#pragma once

#include "../entidades/protagonista/protagonista.hpp"
#include "../entidades/inimigos/inimigos.hpp"

class Globais{
    private:
        static Protagonista *violeta;
        static Inimigo *gerenciaInimigos;

    public:
        Globais(Protagonista *player, Inimigo *inimigos);
        Globais();

        static Protagonista* GetPlayer(){return violeta;}
        static Inimigo* GetGerenciadorInimigos(){return gerenciaInimigos;}

};