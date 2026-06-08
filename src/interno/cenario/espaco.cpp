#include "cenario.hpp"
#include <raylib.h>
#include <vector>


void Espaco::adiciona_estrela(){
    estrela novaEstrela;
    this->estrelas.push_back(novaEstrela);
}

void Espaco::atualiza_estrelas(){
    for(estrela cada_estrela: this->estrelas){
        -- cada_estrela.posicao.x;
        cada_estrela.desenhar();
    }
}
