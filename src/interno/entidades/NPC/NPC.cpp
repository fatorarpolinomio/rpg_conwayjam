#include "../entidade.hpp"
#include "NPC.hpp"
#include "../../sistemas/globais.hpp"


NPC::NPC(const char *caminhoSpritesheet, Vector2 Posicao){
    setSpritesheet(LoadTexture(caminhoSpritesheet));

    setAndarCima({
        Rectangle{0, 128, 64, 64},
        Rectangle{64, 128, 64, 64},
        Rectangle{128, 128, 64, 64},
    });
    setAndarDireita({
      Rectangle{0, 192, 64, 64},
      Rectangle{64, 192, 64, 64},
      Rectangle{128, 192, 64, 64},
    });
    setAndarEsquerda({      
      Rectangle{0, 64, 64, 64},
      Rectangle{64, 64, 64, 64},
      Rectangle{128, 64, 64, 64},
    });
    setAndarBaixo({
      Rectangle{0, 0, 64, 64},
      Rectangle{64, 0, 64, 64},
      Rectangle{128, 0, 64, 64},
    });
    setIdle({Rectangle{0, 0, 64, 64}});
    
    setPosicao(Posicao);
    setAnimacaoAtual(getIdle());

}

void NPC::Update() {
    
}
