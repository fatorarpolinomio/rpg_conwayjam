#pragma once

enum class GameState { GAME_MENU, GAMEPLAY, PAUSE, DEATH, GAME_EXIT };

enum class HistoryState { ACT_0, ACT_1, ACT_2 };

void transitar_entre_estados(GameState estadoAtual, GameState estadoProximo);
