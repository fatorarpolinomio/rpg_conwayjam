#include "interno/entidades/protagonista/protagonista.hpp"
#include "interno/sistemas/trilhaSonora.hpp"
#include "interno/estados/estados.hpp"
#include "raylib.h"
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

	std::vector<Music> trilha = {LoadMusicStream("../assets/audio/musica/tema0.ogg"),
	                              LoadMusicStream("../assets/audio/musica/tema1.ogg"),
	                              LoadMusicStream("../assets/audio/musica/tema2.ogg")};

	// Definindo estados com Enum declarado em estados.hpp
	GameState estadoAtual = ACT_0;
	GameState estadoAnterior = ACT_0;

	// Colocando a trilha do ato 0 para rodar
	PlayMusicStream(trilha[0]);

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
		update_trilha_sonora(estadoAnterior, estadoAtual, trilha);
		camera.Update();
		inimigoManager.Update();

		BeginDrawing();
			BeginMode2D(camera.GetCamera());
				ClearBackground(WHITE);
				DrawRectangle(0,0,40,40, RED); // Retangulo pra testar a camera

				violeta.Draw();
			EndMode2D();
				inimigoManager.Draw();
			EndMode2D();	
		EndDrawing();
	}

	UnloadMusicStream(trilha[0]);
	UnloadMusicStream(trilha[1]);
	UnloadMusicStream(trilha[2]);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
