#include "interno/entidades/protagonista/protagonista.hpp"
#include "interno/sistemas/trilhaSonora.hpp"
#include "interno/estados/estados.hpp"
#include "raylib.h"
#include <iostream>
#include "interno/sistemas/camera.hpp"
#include "interno/entidades/inimigos/Tripulante/Tripulante.hpp"
#include "interno/sistemas/globais.hpp"
#include "interno/cenario/cenario.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

int main() {

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");
	SetTargetFPS(60);

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

	Globais globais(&violeta);

	// TESTE
	Tripulante inimigoTeste(100,0,0,0);
	inimigoTeste.setPosicao(Vector2{250,50});

	Tripulante inimigoTeste2(100,0,0,0);
	inimigoTeste2.setPosicao(Vector2{250,150});

	Tripulante inimigoTeste3(100,0,0,0);
	inimigoTeste3.setPosicao(Vector2{350,50});

	Espaco espaco;

	// Camera
	int x = 400;
  	MainCamera camera(&violeta, Vector2{ WINDOW_WIDTH/2, WINDOW_HEIGHT/2}, 0, 1.0f);
	while (!WindowShouldClose())
	{
	    // Lidando com eventos #TODO

	    // Atualizações
		violeta.Update();
		update_trilha_sonora(estadoAnterior, estadoAtual, trilha);
		camera.Update();
		inimigoManager.Update();

		// Desenhando
		BeginDrawing();
			BeginMode2D(camera.GetCamera());
				ClearBackground(BLACK);
				DrawRectangle(0,0,40,40, RED); // Retangulo pra testar a camera
				espaco.adiciona_estrela();
				espaco.atualiza_estrelas();


				violeta.Draw();
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
