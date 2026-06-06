#include "interno/entidades/protagonista/protagonista.hpp"
#include "raylib.h"
#include <cstdlib>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

int main() {

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");

  InitAudioDevice();
  if (!IsAudioDeviceReady()) {
    std::cout << "ERROR: Dispositivo de som não foi inicializado" << endl;
  }

  Protagonista violeta(Vector2{20, 20});

  while (!WindowShouldClose()) {

    violeta.Update();

    BeginDrawing();
    ClearBackground(WHITE);

    violeta.Draw();
    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();
  return 0;
}
