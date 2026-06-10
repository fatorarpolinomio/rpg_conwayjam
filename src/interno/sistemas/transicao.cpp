#include "transicao.hpp"

Transicao::Transicao(float velocidade) {
    emTransicao = false;
    escurecendo = false;
    alphaTransicao = 0.0f;
    velocidadeFade = velocidade;
    estadoAlvo = GameState::GAME_MENU; // Estado neutro inicial
}

void Transicao::Iniciar(GameState alvo) {
    if (!emTransicao) {
        emTransicao = true;
        escurecendo = true;
        estadoAlvo = alvo;
    }
}

void Transicao::Update(GameState& estadoAtual) {
    if (!emTransicao) return;

    if (escurecendo) {
        alphaTransicao += velocidadeFade;
        if (alphaTransicao >= 255.0f) {
            alphaTransicao = 255.0f;
            estadoAtual = estadoAlvo; // A mágica da troca de estado acontece aqui!
            escurecendo = false;      // Começa a clarear a tela
        }
    } else {
        alphaTransicao -= velocidadeFade;
        if (alphaTransicao <= 0.0f) {
            alphaTransicao = 0.0f;
            emTransicao = false;      // Transição concluída
        }
    }
}

void Transicao::Draw(int screenWidth, int screenHeight) {
    if (emTransicao) {
        DrawRectangle(0, 0, screenWidth, screenHeight, Color{0, 0, 0, (unsigned char)alphaTransicao});
    }
}

bool Transicao::IsAtiva() const {
    return emTransicao;
}
