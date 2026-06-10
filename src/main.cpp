#include "interno/entidades/protagonista/protagonista.hpp"
#include "interno/entidades/NPC/NPC.hpp"
#include "interno/sistemas/trilhaSonora.hpp"
#include "interno/estados/estados.hpp"
#include "interno/estados/menu.hpp"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <iostream>
#include <vector>
#include "interno/sistemas/camera.hpp"
#include "interno/entidades/inimigos/Tripulante/Tripulante.hpp"
#include "interno/entidades/inimigos/Smilinguido/Smilinguido.hpp"
#include "interno/sistemas/globais.hpp"
#include "interno/cenario/cenario.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main() {

	int VIRTUAL_WIDTH = 800;
	int VIRTUAL_HEIGHT = 450;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");
	SetTargetFPS(60);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

	RenderTexture2D canva = LoadRenderTexture(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);


	InitAudioDevice();
	if (!IsAudioDeviceReady()) {
		std::cout << "ERROR: Dispositivo de som não foi inicializado" << endl;
	}

	std::vector<Music> trilha = {LoadMusicStream("../assets/audio/musica/tema0.ogg"),
	                              LoadMusicStream("../assets/audio/musica/tema1.ogg"),
	                              LoadMusicStream("../assets/audio/musica/tema2.ogg")};

	// Definindo Menu e estado atual
	Menu menuPrincipal;
	GameState estadoAnterior = GameState::GAME_MENU; // Isso aqui vai bugar a trilha sonora
	GameState estadoAtual = GameState::GAME_MENU;

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

	// TESTE, MAS COM NPCS
	// Entidade generica
	NPC npc1 = NPC("../assets/Spritesheets/NPCS/tripulante1.png",Vector2{-100,-100});
	NPC npc2 = NPC("../assets/Spritesheets/NPCS/tripulante2.png",Vector2{-80,-100});
	NPC npc3 = NPC("../assets/Spritesheets/NPCS/tripulante3.png",Vector2{-60,-100});
	NPC npc4 = NPC("../assets/Spritesheets/NPCS/tripulante4.png",Vector2{-40,-100});
	NPC npc5 = NPC("../assets/Spritesheets/NPCS/tripulante5.png",Vector2{-20,-100});
	NPC npc6 = NPC("../assets/Spritesheets/NPCS/tripulante6.png",Vector2{0,-100});
	NPC npc7 = NPC("../assets/Spritesheets/NPCS/tripulante7.png",Vector2{20,-100});

    Espaco espaco;

    for(int i = 0; i < 500; i++){
        espaco.adiciona_estrela((std::rand() % (1000 -(-1000) + 1)), (rand() % (400 - (-400) + 1)));
	}

	// Camera
	int x = 400;
  	MainCamera camera(&violeta, Vector2{ (float)VIRTUAL_WIDTH/2, (float)VIRTUAL_HEIGHT/2}, 0, 1.0f);
	while (estadoAtual != GameState::GAME_EXIT && !WindowShouldClose())
	{
	    // Lidando com eventos #TODO

	    // Atualizações
		if(estadoAtual == GameState::GAMEPLAY){
		    if(IsKeyDown(KEY_ESCAPE)){
				estadoAtual = GameState::GAME_MENU;
			}
    		violeta.Update();
    		update_trilha_sonora(estadoAnterior, estadoAtual, trilha);
    		camera.Update();
    		inimigoManager.Update();
		}



		// Estica a tela para a resolução desejada
		BeginDrawing();
			ClearBackground(BLACK);

			if(estadoAtual == GameState::GAME_MENU){
                atualiza_estrelas(espaco.getEstrelas(), WINDOW_WIDTH, WINDOW_HEIGHT);

                estadoAtual = menuPrincipal.desenhar(WINDOW_WIDTH, WINDOW_HEIGHT);
			} else if(estadoAtual == GameState::GAMEPLAY) {
                DrawText("O jogo começou. A energia caiu...", 20, 20, 30, LIGHTGRAY);
          		// Desenhando
          		BeginTextureMode(canva);
                    ClearBackground(BLACK);
                    atualiza_estrelas(espaco.getEstrelas(), WINDOW_WIDTH, WINDOW_HEIGHT);

         			BeginMode2D(camera.GetCamera());

            				for(Entidade * i : Globais::NPCS){
           					i->Draw();
            				}

            				violeta.Draw();
            				inimigoManager.Draw();
         			EndMode2D();
          		EndTextureMode();
    			DrawTexturePro(
    				canva.texture,
    				Rectangle{0,0,(float)VIRTUAL_WIDTH, (float)-VIRTUAL_HEIGHT},
    				Rectangle{0,0,(float)GetScreenWidth(), (float)GetScreenHeight()},
    				Vector2{0,0},
    				0.0f,
    				WHITE
    			);
			}
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
