#include "inimigos.hpp"

#include <vector>

using namespace std;

vector<Inimigo*> Inimigo::Inimigos;

Inimigo::Inimigo(double max, double regen, double infec, double dano)
    :MaxVida(max), TaxaRegen(regen), TaxaInfec(infec), Dano(dano){
        Vida = MaxVida;
        Inimigos.push_back(this);
    }


void Inimigo::Morrer(){}
void Inimigo::Ataque(){}
void Inimigo::Ataque2(){}

void Inimigo::Update(){
    for(Inimigo *i : Inimigos){
        i->Update();
    }
}


void Inimigo::Draw(){
    for(Inimigo *i : Inimigos){
        i->Draw();
    }
}