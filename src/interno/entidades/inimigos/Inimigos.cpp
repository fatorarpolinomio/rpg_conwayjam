#include "inimigos.hpp"
#include <algorithm>
#include "../../cenario/mapa.hpp"
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

void Inimigo::Seguir(Vector2 pos)
{
    
    Vector2 seguindoPlayer = Vector2MoveTowards(getPosicao(), pos, velocidade);
    Vector2 offset = Vector2Subtract(seguindoPlayer, getPosicao());
    if(!Mapa::estaCollidindo(offset, getCaixaColisao())){
        setPosicao(seguindoPlayer);
    }
    
    // Mudar animação de acordo com sa posição do player
    Vector2 Offset = Vector2Subtract(pos, getPosicao());

    if (Offset.x > 0.0f)
    {
        AnimacaoAtual = andarDireita;
    }
    else
    {
        AnimacaoAtual = andarEsquerda;
    }

    if (Offset.y > 80.0f)
    {
        AnimacaoAtual = andarBaixo;
    }
    else if (Offset.y < -80.0f) 
    {
        AnimacaoAtual = andarCima;
    }
    
}

// Passar para globais? faz sentido? (pra poder colocar um que desenha TODAS as entidades)
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