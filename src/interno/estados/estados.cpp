#include "estados.hpp"

// game_state game_difficulties = {
//     GAME_DIFFICULTIES,
//     // TODO: estruturar dificuldades
// };

game_state new_game = {
    NEW_GAME,

};

game_state load_game = {
    LOAD_GAME,

};

game_state game_config = {
    GAME_CONFIG,

};

game_state game_exit = {
    GAME_EXIT,

};

game_state menu = {GAME_MENU, {new_game, load_game, game_config, game_exit}};

void transitar_entre_estados(game_state current_state, game_state next_state) {
  switch (current_state.name) {
  case GAME_MENU:
    if (next_state.name == NEW_GAME) {
      current_state = new_game;
    }
    break;
  case NEW_GAME:
    break;
  case LOAD_GAME:
    break;
  case GAME_CONFIG:
    if (next_state.name == GAME_MENU) {
      current_state = menu;
    }
    break;
  case GAME_EXIT:
    if (next_state.name == GAME_MENU) {
      current_state = menu;
    }
    break;
  }
}
