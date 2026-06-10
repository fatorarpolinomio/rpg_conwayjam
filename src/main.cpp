#include "interno/entidades/protagonista/protagonista.hpp"
#include "interno/entidades/NPC/NPC.hpp"
#include "interno/sistemas/trilhaSonora.hpp"
#include "interno/estados/estados.hpp"
#include "interno/estados/menu.hpp"
#include "interno/estados/pause.hpp"
#include "interno/estados/morte.hpp"
#include "interno/estados/atos.hpp"
#include "raylib.h"
#include "interno/sistemas/dialogo.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <iostream>
#include <vector>
#include "interno/sistemas/camera.hpp"
#include "interno/sistemas/transicao.hpp"
#include "interno/entidades/inimigos/Tripulante/Tripulante.hpp"
#include "interno/entidades/inimigos/Smilinguido/Smilinguido.hpp"
#include "interno/entidades/inimigos/Tentaculo/Tentaculo.hpp"
#include "interno/entidades/inimigos/Amalgama/Amalgama.hpp"
#include "interno/sistemas/globais.hpp"
#include "interno/cenario/cenario.hpp"
#include "interno/cenario/mapa.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main() {

	int VIRTUAL_WIDTH = 600;
	int VIRTUAL_HEIGHT = 300;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "RPG");
	SetTargetFPS(60);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

	SetExitKey(0);

	RenderTexture2D canva = LoadRenderTexture(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);
	InicializarDialogoAssets();

	InitAudioDevice();
	if (!IsAudioDeviceReady()) {
		std::cout << "ERROR: Dispositivo de som não foi inicializado" << endl;
	}

	std::vector<Music> trilha = {LoadMusicStream("../assets/audio/musica/tema0.ogg"),
	                              LoadMusicStream("../assets/audio/musica/tema1.ogg"),
	                              LoadMusicStream("../assets/audio/musica/tema2.ogg")};

	// Definindo Menu e estado atual
	Menu menuPrincipal;
	Pause menuPause;
	Morte telaMorte;
	Transicao transicaoFade(7.0f);
	GameState estadoAnterior = GameState::GAME_MENU; // Isso aqui vai bugar a trilha sonora
	GameState estadoAtual = GameState::GAME_MENU;

  	Protagonista violeta(Vector2{15,1075});
	Inimigo inimigoManager;

	Globais globais(&violeta);

	// TESTE
	Tripulante inimigoTeste(100,0,20,10);
	inimigoTeste.setPosicao(Vector2{375,840});

	Smilinguido inimigoTeste2(100,0,30,10);
	inimigoTeste2.setPosicao(Vector2{675,450});

	Tentaculo inimigoTeste4(100,0,0,0);
	inimigoTeste4.setPosicao(Vector2{575,650});

	Amalgama inimigoTeste3(100,0,0,0);
	inimigoTeste3.setPosicao(Vector2{374,450});

	// TESTE, MAS COM NPCS
	// Entidade generica
	NPC npc1 = NPC("../assets/Spritesheets/NPCS/tripulante1.png",Vector2{600,700});
	NPC npc2 = NPC("../assets/Spritesheets/NPCS/tripulante2.png",Vector2{-80,-100});
	NPC npc3 = NPC("../assets/Spritesheets/NPCS/tripulante3.png",Vector2{-60,-100});
	NPC npc4 = NPC("../assets/Spritesheets/NPCS/tripulante4.png",Vector2{-40,-100});
	NPC npc5 = NPC("../assets/Spritesheets/NPCS/tripulante5.png",Vector2{-20,-100});
	NPC npc6 = NPC("../assets/Spritesheets/NPCS/tripulante6.png",Vector2{0,-100});
	NPC npc7 = NPC("../assets/Spritesheets/NPCS/tripulante7.png",Vector2{20,-100});

	Mapa mapa;

	// Carrega o que vai ser renderizado
	// Carrega o que vai ser usado para detectar colisão
	Texture2D mapaTextura1 = LoadTexture("../assets/mapas/mapasNormais/mapa montado sem portas.png.png");
	Texture2D mapaTextura2 = LoadTexture("../assets/mapas/mapas normais escuros/mapa c meteoro sem portas escuro.png");
	Texture2D mapaTextura3 = LoadTexture("../assets/mapas/mapas c sangue/mapa montado c sangue.png");
	Texture2D mapaTextura4 = LoadTexture("../assets/mapas/mapas c sangue/mapa sem portas c sangue meteoro.png");

	mapa.carregarImagensDeColisao({
		LoadImage("../assets/mapas/mapasNormais/mapaMontadoSemPortasCol.png"),
		LoadImage("../assets/mapas/mapasNormais/mapaMontadoSemPortasCol.png"),
		LoadImage("../assets/mapas/mapasNormais/mapaMontadoSemPortasCol.png"),
		LoadImage("../assets/mapas/mapasNormais/mapaMontadoSemPortasCol.png"),
		LoadImage("../assets/mapas/mapasNormais/mapaMontadoSemPortasCol.png"),
		LoadImage("../assets/mapas/mapasNormais/mapaMontadoSemPortasCol.png")
	});
	mapa.carregarMapas({
		mapaTextura1,
		mapaTextura2,
		mapaTextura3,
		mapaTextura4,
	});

	mapa.setMapa(3);

    Espaco espaco;

    Atos gerenciadorDeHistoria(&mapa, &violeta, &trilha);
    gerenciadorDeHistoria.iniciarAto(HistoryState::ACT_0);

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
		if (transicaoFade.IsAtiva()) {
        // A transição assume o controle e altera o estadoAtual quando escurecer tudo
        transicaoFade.Update(estadoAtual);
        } else {

    		if(estadoAtual == GameState::GAMEPLAY){
    			if (IsKeyPressed(KEY_ESCAPE)) {
    				estadoAtual = GameState::PAUSE;
    			}
				violeta.Update();
				gerenciadorDeHistoria.Update();
				camera.Update();
				inimigoManager.Update();

				if(!violeta.getOxigenio() || violeta.getInfeccao() >= 100){
				    transicaoFade.Iniciar(GameState::DEATH);
				}
    		} else if (estadoAtual == GameState::PAUSE) {
                // Se o som de passos estiver ativo, silencia imediatamente para não travar em loop
                PauseSound(violeta.passos);

                // Se pressionar ESC novamente enquanto pausado, retorna ao gameplay
                if (IsKeyPressed(KEY_ESCAPE)) {
                	estadoAtual = GameState::GAMEPLAY;
                }
            } else if (estadoAtual == GameState::DEATH) {
				// Garante que o som de passos não continue tocando no além
				PauseSound(violeta.passos);
			}
        }

		// Desenha
		BeginDrawing();
			ClearBackground(BLACK);
			if(estadoAtual == GameState::GAME_MENU){

                atualiza_estrelas(espaco.getEstrelas(), WINDOW_WIDTH, WINDOW_HEIGHT);

                GameState acaoMenu = menuPrincipal.desenhar(WINDOW_WIDTH, WINDOW_HEIGHT);

                // Engatilha a transição se o jogador clicou em algum botão
                if (acaoMenu != estadoAtual && !transicaoFade.IsAtiva()) {
                    transicaoFade.Iniciar(acaoMenu);
                }


			} else if(estadoAtual == GameState::GAMEPLAY|| estadoAtual == GameState::PAUSE|| estadoAtual == GameState::DEATH) {
          		// Desenhando
          		BeginTextureMode(canva);
                    ClearBackground(BLACK);
                    atualiza_estrelas(espaco.getEstrelas(), VIRTUAL_WIDTH, VIRTUAL_HEIGHT);

         			BeginMode2D(camera.GetCamera());
						mapa.Draw();

						Globais::UpdateListaRenderizacao();
						for(Entidade * i : Globais::ListaDeRenderização){
							i->Draw();
						}

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


				if (estadoAtual == GameState::GAMEPLAY) {
					violeta.DrawHUD();
					if (IsDialogueActive && IsKeyPressed(KEY_C)) {IsDialogueActive = false;}
					Dialogue("aperteC");
                } else if (estadoAtual == GameState::PAUSE) {
                    GameState acaoPause = menuPause.desenhar(WINDOW_WIDTH, WINDOW_HEIGHT);
                    if (acaoPause != estadoAtual && !transicaoFade.IsAtiva()) {
                        transicaoFade.Iniciar(acaoPause);
                    }
                } else if (estadoAtual == GameState::DEATH){
                    GameState acaoMorte = telaMorte.desenhar(WINDOW_WIDTH, WINDOW_HEIGHT);
                    if (acaoMorte != estadoAtual && !transicaoFade.IsAtiva()) {
                        if(acaoMorte == GameState::GAMEPLAY) {
                            violeta.setInfeccao(0);
                            violeta.setIntegridade(100);
                            violeta.setOxigenio(100);
                            violeta.setInfeccao(0);
                            violeta.setPosicao(Vector2{15, 1075});

                            // Aqui, a gente reseta a posição dos inimigos
                        }
                        transicaoFade.Iniciar(acaoMorte);
                    }
                }
			}
			transicaoFade.Draw(WINDOW_WIDTH, WINDOW_HEIGHT);
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
