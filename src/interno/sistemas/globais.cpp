#include "globais.hpp"

Protagonista* Globais::violeta;
vector<Inimigo*> Globais::Inimigos;
vector<Entidade*> Globais::NPCS;

Globais::Globais(Protagonista *player){
    violeta = player;
}