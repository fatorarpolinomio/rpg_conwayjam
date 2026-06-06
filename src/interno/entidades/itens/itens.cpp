#include <cstdlib>
#include <string>

#include "../inimigos/inimigos.hpp"
#include "../protagonista/protagonista.hpp"
#include "itens.hpp"

Item::Item() {}

Item Xarope() {
  Item xarope;
  xarope.SetTipo("Consumível");
  xarope.SetRegeneracao(20);
  xarope.SetAlvo("Protagonista");
  return xarope;
}

Item Tanque() {
  Item tanque;
  tanque.SetTipo("Consumível");
  tanque.SetRegeneracao(100);
  tanque.SetAlvo("Oxigênio");
  return tanque;
}

Item Capacete() {
  Item capacete;
  capacete.SetTipo("Equipável");
  capacete.SetDurabilidade(100);
  return capacete;
}

Item SilverTape() {
  Item silverTape;
  silverTape.SetTipo("Consumível");
  silverTape.SetRegeneracao(20);
  silverTape.SetAlvo("Capacete");
  return silverTape;
}

Item Martelo() {
  Item martelo;
  martelo.SetTipo("Arma");
  martelo.SetDano(20);
  return martelo;
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
  if (item.GetTipo() == "Consumível") {
    if (item.GetAlvo() == "Protagonista") {
      protagonista.aumentarIntegridade(item.GetRegeneracao());
    } else if (item.GetAlvo() == "Capacete") {
      Item capacete = Capacete();
      capacete.SetDurabilidade(capacete.GetDurabilidade() +
                               item.GetRegeneracao());
    } else if (item.GetAlvo() == "Oxigênio") {
      protagonista.aumentarOxigenio(item.GetRegeneracao());
    }
  } else if (item.GetTipo() == "Arma") {
    inimigo.TomarDano(item.GetDano());
  } else if (item.GetTipo() == "Equipável") {
    protagonista.setIntegridade(protagonista.getIntegridade() +
                                item.GetDurabilidade());
  }
}
