#pragma once
#include "estados.hpp"
#include "../cenario/mapa.hpp"
#include "../entidades/protagonista/protagonista.hpp"
#include <vector>
#include <raylib.h>
#include "raymath.h"

extern std::string idDialogoAtual;
extern bool IsDialogueActive;

class Atos{
private:
    HistoryState atoAtual;
    Mapa* mapa;
    Protagonista* violeta;
    std::vector<Music>* trilha;

    // Novas travas para a história não repetir a cada frame
    bool ativouDialogoInicial = false;
    bool ativouInterfone = false;
    bool ativouNaoSobrouNada = false;

    // NOVAS TRAVAS PARA O ROTEIRO DO METEORO E DORMIR
    bool consertouMeteoro = false;
    bool foiDormir = false;
    bool acordouInfectados = false;
public:
    Atos(Mapa* mapa, Protagonista* violeta, std::vector<Music>* trilha);
    HistoryState getAtoAtual() const{return this->atoAtual;}
    void iniciarAto(HistoryState novoAto);
    void Update();

};
