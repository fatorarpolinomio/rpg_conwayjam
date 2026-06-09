#include <cstdlib>
#include <string>

#include "../inimigos/inimigos.hpp"
#include "../protagonista/protagonista.hpp"
#include "itens.hpp"

Item::Item() : nome(""), tipo(""), dano(0.0), regeneracao(0.0), alvo("") {}

Item Xarope() {
  Item xarope;
  xarope.SetTipo("Consum�vel");
  xarope.SetRegeneracao(50);
  xarope.SetAlvo("Infec��o");
  return xarope;
}

Item Tanque() {
  Item tanque;
  tanque.SetTipo("Consum�vel");
  tanque.SetRegeneracao(100);
  tanque.SetAlvo("Oxig�nio");
  return tanque;
}

Item Capacete() {
  Item capacete;
  capacete.SetTipo("Consum�vel");
  capacete.SetRegeneracao(100);
  capacete.SetAlvo("Integridade");
  return capacete;
}

Item SilverTape() {
  Item silverTape;
  silverTape.SetTipo("Consum�vel");
  silverTape.SetRegeneracao(20);
  silverTape.SetAlvo("Integridade");
  return silverTape;
}

Item Martelo() {
  Item martelo;
  martelo.SetTipo("Arma");
  martelo.SetDano(20);
  return martelo;
}

Item Taser() {
    Item taser;
    taser.SetTipo("Arma");
    taser.SetDano(50);
    return taser;
}

Item Chave() {
  Item chave;
  chave.SetTipo("Chave");
  return chave;
}

Item Ferramentas() {
  Item ferramentas;
  ferramentas.SetTipo("Chave");
  return ferramentas;
}

void usarItem(Item item, Protagonista &protagonista, Inimigo &inimigo) {
  if (item.GetTipo() == "Consum�vel") {
    if (item.GetAlvo() == "Infec��o") {
      protagonista.diminuirNivelInfeccao(item.GetRegeneracao());
    } else if (item.GetAlvo() == "Integridade") {
        protagonista.aumentarIntegridade(item.GetRegeneracao());
    } else if (item.GetAlvo() == "Oxig�nio") {
      protagonista.aumentarOxigenio(item.GetRegeneracao());
    }
  } else if (item.GetTipo() == "Arma") {
    inimigo.TomarDano(item.GetDano());
  }
}
