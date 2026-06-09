#include "cenario.hpp"
#include <raylib.h>
#include <vector>


void Espaco::adiciona_estrela(double x, double y){
        estrela novaEstrela;
        novaEstrela.posicao.x = x;
        novaEstrela.posicao.y = y;
        this->estrelas.push_back(novaEstrela);

}

void atualiza_estrelas(std::vector<estrela>& estrelas, double largura_tela, double altura_tela){
    for(estrela &cada_estrela: estrelas){
        cada_estrela.posicao.x -= 2;

        if(cada_estrela.posicao.x < 0){
            cada_estrela.posicao.x = largura_tela;
            cada_estrela.posicao.y = GetRandomValue(0, int(altura_tela));
        }
        cada_estrela.desenhar();
    }
}
