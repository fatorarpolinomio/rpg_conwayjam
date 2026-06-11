#include "globais.hpp"
#include <algorithm>

Protagonista* Globais::violeta;
vector<Inimigo*> Globais::Inimigos;
vector<Entidade*> Globais::ListaDeRenderizacao;
int Globais::listaRenderizacaoCount = 0;

Globais::Globais(Protagonista *player){
    violeta = player;
}

void Globais::adicionaraListaRenderizacao(Entidade *entidade){
    ListaDeRenderizacao.push_back(entidade);
}

void Globais::removerListaRenderizacao(Entidade *entidade){
    ListaDeRenderizacao.erase(std::remove(ListaDeRenderizacao.begin(), ListaDeRenderizacao.end(), entidade), ListaDeRenderizacao.end());
}


void Globais::UpdateListaRenderizacao(){
    std::sort(ListaDeRenderizacao.begin(), ListaDeRenderizacao.end(), [](const Entidade*a, const Entidade*b){
        return a->getPosicao().y < b->getPosicao().y;
    });
}

Globais::~Globais(){
}