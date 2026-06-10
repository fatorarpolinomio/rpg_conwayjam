#pragma once
#include "estados.hpp"
#include "../cenario/mapa.hpp"

// Do estado "GAMEPLAY", pularemos para a aplicação desta API aqui
// Estaremos no estado de jogo "GAMEPLAY" e em um estado da história.
//
// Vai ser necessário desenhar o mapa correspondente ao estado da história.
// Vai ser necessário spawnar os personagens correspondentes ao estado da história.
// Vai ser necessário colocar os diálogos correspondentes ao estado da história.
// Vai ser necessário colocar a trilha sonora correspondente ao estado da história.

class Atos{
private:
    HistoryState estadoAtual;
    Mapa* mapa;

public:
    Atos(Mapa* mapa);
    HistoryState getAtoAtual() const{return this->estadoAtual;}
    void iniciarAto(HistoryState novoAto);
    void Update();

};
