#pragma once
#include <raylib.h>
#include "../estados/estados.hpp"


void update_trilha_sonora(GameState estadoAnterior, GameState estadoAtual, const std::vector<Music>& trilha);
