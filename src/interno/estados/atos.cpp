#include "atos.hpp"
#include "estados.hpp"
#include "../cenario/mapa.hpp"
#include "../sistemas/trilhaSonora.hpp"

Atos::Atos(Mapa* mapa) {
    this->mapa = mapa;
}

void Atos::iniciarAto(HistoryState novoAto) {
    if(novoAto == HistoryState::ACT_0){
        this->mapa->setMapa(0);
        // - Mudar a música para trilha[0]
        // - Dar spawn nos NPCs iniciais
    } else if(novoAto == HistoryState::ACT_1){
        this->mapa->setMapa(1);
        // - Mudar a música para trilha[1]
        // - Dar spawn nos inimigos novos
        // - Remover NPCs antigos
        // - Adicionar inimigos
    } else if(novoAto == HistoryState::ACT_2){
        this->mapa->setMapa(2);
        // - Mudar a música para trilha[2]
    }

    this->mapa->Draw();
}
