#include "inimigos.hpp"
#include <algorithm>

#include <vector>
#include "../../sistemas/globais.hpp"

using namespace std;


Inimigo::Inimigo(double max, double regen, double infec, double dano)
    :MaxVida(max), TaxaRegen(regen), TaxaInfec(infec), Dano(dano){
        Vida = MaxVida;
        Globais::Inimigos.push_back(this);
    }


void Inimigo::Ataque(){}
void Inimigo::Ataque2(){}

void Inimigo::Morrer(){
    Globais::Inimigos.erase(remove(Globais::Inimigos.begin(), Globais::Inimigos.end(), this));
}

void Inimigo::Update(){
    for(Inimigo *i : Globais::Inimigos){
        i->Update();
    }
}

void Inimigo::Draw(){
    for(Inimigo *i : Globais::Inimigos){
        i->Draw();
    }
}