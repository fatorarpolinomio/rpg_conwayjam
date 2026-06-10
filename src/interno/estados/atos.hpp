#pragma once
#include "estados.hpp"
#include "../cenario/mapa.hpp"
#include "../entidades/protagonista/protagonista.hpp"
#include <vector>
#include <raylib.h>

class Atos{
private:
    HistoryState atoAtual;
    Mapa* mapa;
    Protagonista* violeta;
    std::vector<Music>* trilha;

public:
    Atos(Mapa* mapa, Protagonista* violeta, std::vector<Music>* trilha);
    HistoryState getAtoAtual() const{return this->atoAtual;}
    void iniciarAto(HistoryState novoAto);
    void Update();

};
