#include "interno/entidades/protagonista/protagonista.hpp"
#include "interno/sistemas/trilhaSonora.hpp"
#include "interno/estados/estados.hpp"
#include "raylib.h"
#include <iostream>
#include "interno/sistemas/camera.hpp"
#include "interno/entidades/inimigos/Tripulante/Tripulante.hpp"
#include "interno/entidades/inimigos/Smilinguido/Smilinguido.hpp"
#include "interno/sistemas/globais.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main() {

	int VIRTUAL_WIDTH = 800;
	int VIRTUAL_HEIGHT = 450;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");
	SetTargetFPS(60);

	RenderTexture2D canva = LoadRenderTexture(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);


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

	Smilinguido inimigoTeste2(100,0,0,0);
	inimigoTeste2.setPosicao(Vector2{250,150});

	Tripulante inimigoTeste3(100,0,0,0);
	inimigoTeste3.setPosicao(Vector2{350,50});
	
	// Camera

  	MainCamera camera(&violeta, Vector2{ VIRTUAL_WIDTH/2, VIRTUAL_HEIGHT/2}, 0, 1.0f);
	while (!WindowShouldClose())
	{
		// Updates
		violeta.Update();
		update_trilha_sonora(estadoAnterior, estadoAtual, trilha);
		camera.Update();
		inimigoManager.Update();


		// Draws
		BeginTextureMode(canva);
			ClearBackground(RAYWHITE);
			
			BeginMode2D(camera.GetCamera());
				ClearBackground(WHITE);
				DrawRectangle(0,0,40,40, RED); // Retangulo pra testar a camera

				violeta.Draw();
				inimigoManager.Draw();
			EndMode2D();
		EndTextureMode();

		// Estica a tela para a resolução desejada
		BeginDrawing();	
			ClearBackground(BLACK);
			DrawTexturePro(	
				canva.texture,
				Rectangle{0,0,(float)VIRTUAL_WIDTH, (float)-VIRTUAL_HEIGHT},
				Rectangle{0,0,(float)GetScreenWidth(), (float)GetScreenHeight()},
				Vector2{0,0},
				0.0f,
				WHITE
			);
		EndDrawing();
	}

	UnloadMusicStream(trilha[0]);
	UnloadMusicStream(trilha[1]);
	UnloadMusicStream(trilha[2]);
	UnloadRenderTexture(canva);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
