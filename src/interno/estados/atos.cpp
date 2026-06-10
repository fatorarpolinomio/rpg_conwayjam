#include "atos.hpp"
#include "estados.hpp"
#include "../cenario/mapa.hpp"
#include "../sistemas/trilhaSonora.hpp"
#include "raylib.h"

Atos::Atos(Mapa* mapa, Protagonista* violeta, std::vector<Music>* trilha) {
    this->mapa = mapa;
    this->violeta = violeta;
    this->trilha = trilha;
    this->atoAtual = HistoryState::ACT_0;
}

void Atos::iniciarAto(HistoryState novoAto) {

    this->atoAtual = novoAto;

    for(auto& musica: *trilha){
        StopMusicStream(musica);
    }

    if(novoAto == HistoryState::ACT_0){
        this->mapa->setMapa(0);
        PlayMusicStream((*trilha)[0]);

        // - Dar spawn nos NPCs iniciais
    } else if(novoAto == HistoryState::ACT_1){
        this->mapa->setMapa(1);
        PlayMusicStream((*trilha)[1]);

        // - Dar spawn nos inimigos novos
        // - Remover NPCs antigos
    } else if(novoAto == HistoryState::ACT_2){
        this->mapa->setMapa(2);
        PlayMusicStream((*trilha)[2]);
    }
}

void Atos::Update(){
    if (atoAtual == HistoryState::ACT_0) {
        UpdateMusicStream((*trilha)[0]);
    } else if (atoAtual == HistoryState::ACT_1) {
        UpdateMusicStream((*trilha)[1]);
    } else if (atoAtual == HistoryState::ACT_2) {
        UpdateMusicStream((*trilha)[2]);
    }

    // GATILHOS DE MUDANÇA DE ESTADO
    if (atoAtual == HistoryState::ACT_0) {
        // Exemplo: Se a Violeta andar até a porta (ex: X for maior que 2000), vai pro Ato 1
        if (violeta->getPosicao().x > 2000) {
            iniciarAto(HistoryState::ACT_1);
        }
    } else if (atoAtual == HistoryState::ACT_1) {
        // Exemplo: Se a infecção chegar a 50, muda pro Ato 2
        // if (violeta->getInfeccao() > 50) { IniciarAto(HistoryState::ACT_2); }
    } else if (atoAtual == HistoryState::ACT_2) {

    }
}
