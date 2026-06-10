#pragma once

#include "../entidade.hpp"
#include <raylib.h>

class NPC : public Entidade{

    public:
        NPC(const char *caminhoSpritesheet, Vector2 Posicao);
        ~NPC() = default;
        virtual void Update(); // Se precisar que ele ande
        void Interagir();
};