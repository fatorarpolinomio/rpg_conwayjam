#include "inimigos.hpp"
#include <algorithm>

#include <vector>
#include "../../sistemas/globais.hpp"
#include "../protagonista/protagonista.hpp"
#include <raymath.h>

using namespace std;


Inimigo::Inimigo(double max, double regen, double infec, double dano)
    :MaxVida(max), TaxaRegen(regen), TaxaInfec(infec), Dano(dano){
        Vida = MaxVida;
        Globais::Inimigos.push_back(this);
    }


void Inimigo::Ataque(){}
void Inimigo::Ataque2(){}

void Inimigo::Morrer(){
    // Eles não morrer :P
    // Globais::Inimigos.erase(remove(Globais::Inimigos.begin(), Globais::Inimigos.end(), this));
}

void Inimigo::SeguirPlayer(Protagonista *player)
{
    Vector2 seguindoPlayer = Vector2MoveTowards(getPosicao(), player->getPosicao(), velocidade);
    setPosicao(seguindoPlayer);

    // Mudar animação de acordo com sa posição do player
    Vector2 Offset = Vector2Subtract(player->getPosicao(), getPosicao());

    if (Offset.y > 0)
    {
        AnimacaoAtual = andarBaixo;
    }
    else
    {
        AnimacaoAtual = andarCima;
    }

    if (Offset.x > 40.0f)
    {
        AnimacaoAtual = andarDireita;
    }
    else if (Offset.x < -40.0f)
    {
        AnimacaoAtual = andarEsquerda;
    }
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