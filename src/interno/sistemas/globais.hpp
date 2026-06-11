#pragma once

#include "../entidades/protagonista/protagonista.hpp"
#include "../entidades/inimigos/inimigos.hpp"

class Globais{
    private:
        static Protagonista *violeta;

    public:
        static vector<Inimigo*> Inimigos;
        static vector<Entidade*>ListaDeRenderizacao;
        static int listaRenderizacaoCount;

        Globais(Protagonista *player);
        Globais();
        ~Globais();

        static Protagonista* GetPlayer(){return violeta;}
        static void removerListaRenderizacao(Entidade *entidade);
        static void adicionaraListaRenderizacao(Entidade *entidade);
        static void UpdateListaRenderizacao();

        
};