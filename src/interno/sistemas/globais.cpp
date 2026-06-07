#include "globais.hpp"

Protagonista* Globais::violeta;
vector<Inimigo*> Globais::Inimigos;

Globais::Globais(Protagonista *player){
    violeta = player;
}