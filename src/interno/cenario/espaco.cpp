#include "cenario.hpp"
#include <raylib.h>
#include <vector>


void Espaco::adiciona_estrela(double x, double y){
        estrela novaEstrela;
        novaEstrela.posicao.x = x;
        novaEstrela.posicao.y = y;
        this->estrelas.push_back(novaEstrela);

}

void atualiza_estrelas(std::vector<estrela>& estrelas){
    for(estrela &cada_estrela: estrelas){
        cada_estrela.posicao.x -= 2;
        cada_estrela.desenhar();
    }
}

void remove_estrelas(double limite_horizontal, std::vector<estrela>& estrelas){
    for(int i = 0; i < estrelas.size(); i++){
        if(estrelas[i].posicao.x < limite_horizontal){
            estrelas.erase(estrelas.begin() + i);
        }
    }
}
