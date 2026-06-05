#include <vector>

enum GAME_STATES { GAME_MENU, NEW_GAME, LOAD_GAME, GAME_CONFIG, GAME_EXIT };

struct game_state {
  GAME_STATES name;
  std::vector<game_state> options;
};

void transitar_entre_estados();
