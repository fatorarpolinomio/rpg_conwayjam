#include "interno/entidades/protagonista/protagonista.hpp"
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include "interno/sistemas/camera.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400


int main() {

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");

	InitAudioDevice();
	if (!IsAudioDeviceReady()) {
		std::cout << "ERROR: Dispositivo de som não foi inicializado" << endl;
	}


  	Protagonista violeta(Vector2{20,20});

	// Camera

  	MainCamera camera(&violeta, Vector2{ WINDOW_WIDTH/2, WINDOW_HEIGHT/2}, 0, 1.0f);
	while (!WindowShouldClose())
	{
		violeta.Update();

		BeginDrawing();
			BeginMode2D(camera.GetCamera());
				ClearBackground(WHITE);
				DrawRectangle(0,0,40,40, RED); // Retangulo pra testar a camera

				camera.Update();
				violeta.Draw();
			EndMode2D();	
		EndDrawing();
	}
	
	CloseAudioDevice();               
	CloseWindow();
	return 0;
}
