#include <cstdlib>
#include <string>

#include "../inimigos/inimigos.hpp"
#include "../protagonista/protagonista.hpp"
#include "itens.hpp"

Item::Item() {
    nome = "";
    tipo = "";
    dano = 0.0;
    regeneracao = 0.0;
    alvo = "";
    // spritesheet deve ser inicializado conforme necessário no seu projeto
}

Item Xarope() {
  Item xarope;
  xarope.SetTipo("Consumível");
  xarope.SetRegeneracao(50);
  xarope.SetAlvo("Infecção");
  xarope.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/Xarope.png"));
  return xarope;
}

Item Tanque() {
  Item tanque;
  tanque.SetTipo("Consumível");
  tanque.SetRegeneracao(100);
  tanque.SetAlvo("Oxigênio");
  tanque.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/TanqueO2.png"));
  return tanque;
}

Item SilverTape() {
    Item silverTape;
    silverTape.SetTipo("Consumível");
    silverTape.SetRegeneracao(20);
    silverTape.SetAlvo("Integridade");
    silverTape.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/SilverTape.png"));
    return silverTape;
}

Item Capacete() {
  Item capacete;
  capacete.SetTipo("Consumível");
  capacete.SetRegeneracao(100);
  capacete.SetAlvo("Integridade");
  return capacete;
}

Item Martelo() {
  Item martelo;
  martelo.SetTipo("Arma");
  martelo.SetDano(20);
  martelo.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/Martelo.png"));
  return martelo;
}

Item Taser() {
    Item taser;
    taser.SetTipo("Arma");
    taser.SetDano(50);
	taser.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/Taser.png"));
    return taser;
}

Item Makita(){
    Item makita;
    makita.SetTipo("Arma");
    makita.SetDano(100);
    makita.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/Makita.png"));
    return makita;
}

Item KeyCard() {
  Item keycard;
  keycard.SetTipo("Chave");
  keycard.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/KeyCard.png"));
  return keycard;
}

Item Ferramentas() {
  Item ferramentas;
  ferramentas.SetTipo("Chave");
  ferramentas.SetSprite(LoadTexture("../../../assets/Spritesheets/Itens/CaixaDeFerramentas.png"));
  return ferramentas;
}


void Item::Use(Item item, Protagonista& protagonista, Inimigo& inimigo) {
    if (item.GetTipo() == "Consumível") {
        if (item.GetAlvo() == "Infecção") {
            protagonista.diminuirNivelInfeccao(item.GetRegeneracao());
        }
        else if (item.GetAlvo() == "Integridade") {
            protagonista.aumentarIntegridade(item.GetRegeneracao());
        }
        else if (item.GetAlvo() == "Oxigênio") {
            protagonista.aumentarOxigenio(item.GetRegeneracao());
        }
    }
    else if (item.GetTipo() == "Arma") {
        inimigo.TomarDano(item.GetDano());
    }
}

void usarItem(Item item, Protagonista &protagonista, Inimigo &inimigo) {
  if (item.GetTipo() == "Consumível") {
    if (item.GetAlvo() == "Infecção") {
      protagonista.diminuirNivelInfeccao(item.GetRegeneracao());
    } else if (item.GetAlvo() == "Integridade") {
      protagonista.aumentarIntegridade(item.GetRegeneracao());
    } else if (item.GetAlvo() == "Oxigênio") {
      protagonista.aumentarOxigenio(item.GetRegeneracao());
    }
  } else if (item.GetTipo() == "Arma") {
    inimigo.TomarDano(item.GetDano());
  }
}
