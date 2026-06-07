#include "interno/entidades/protagonista/protagonista.hpp"
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include "interno/sistemas/camera.hpp"
#include "interno/entidades/inimigos/Tripulante/Tripulante.hpp"
#include "interno/sistemas/globais.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400


int main() {

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");

	InitAudioDevice();
	if (!IsAudioDeviceReady()) {
		std::cout << "ERROR: Dispositivo de som não foi inicializado" << endl;
	}


  	Protagonista violeta(Vector2{20,20});
	Inimigo inimigoManager;

	Globais globais(&violeta, &inimigoManager);

	Tripulante inimigoTeste(100,0,0,0);
	inimigoTeste.setPosicao(Vector2{50,50});

	Tripulante inimigoTeste2(100,0,0,0);
	inimigoTeste2.setPosicao(Vector2{50,150});

	Tripulante inimigoTeste3(100,0,0,0);
	inimigoTeste3.setPosicao(Vector2{150,50});
	// Camera

  	MainCamera camera(&violeta, Vector2{ WINDOW_WIDTH/2, WINDOW_HEIGHT/2}, 0, 1.0f);
	while (!WindowShouldClose())
	{
		violeta.Update();
		camera.Update();
		inimigoManager.Update();

		BeginDrawing();
			BeginMode2D(camera.GetCamera());
				ClearBackground(WHITE);
				DrawRectangle(0,0,40,40, RED); // Retangulo pra testar a camera

				violeta.Draw();
				inimigoManager.Draw();
			EndMode2D();	
		EndDrawing();
	}
	
	CloseAudioDevice();               
	CloseWindow();
	return 0;
}
