#include "globais.hpp"
#include <algorithm>

Protagonista* Globais::violeta;
vector<Inimigo*> Globais::Inimigos;
vector<Entidade*> Globais::ListaDeRenderização;
int Globais::listaRenderizacaoCount = 0;

Globais::Globais(Protagonista *player){
    violeta = player;
}

void Globais::adicionaraListaRenderizacao(Entidade *entidade){
    ListaDeRenderização.push_back(entidade);
}

void Globais::UpdateListaRenderizacao(){
    std::sort(ListaDeRenderização.begin(), ListaDeRenderização.end(), [](const Entidade*a, const Entidade*b){
        return a->getPosicao().y < b->getPosicao().y;
    });
}

Globais::~Globais(){
}