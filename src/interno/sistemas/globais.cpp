#include "globais.hpp"

Protagonista* Globais::violeta;
Inimigo* Globais::gerenciaInimigos;

Globais::Globais(Protagonista *player, Inimigo *inimigos){
    violeta = player;
    gerenciaInimigos = inimigos;
}