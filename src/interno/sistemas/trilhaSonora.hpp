#pragma once
#include <raylib.h>
#include "../estados/estados.hpp"
#include <vector>


void update_trilha_sonora(HistoryState estadoAnterior, HistoryState estadoAtual, const std::vector<Music>& trilha);
