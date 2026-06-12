#include "atos.hpp"
#include "estados.hpp"
#include "../cenario/mapa.hpp"
#include "../entidades/NPC/NPC.hpp"
#include "../sistemas/trilhaSonora.hpp"
#include "../sistemas/globais.hpp"
#include "raylib.h"
#include "../entidades/inimigos/Tripulante/Tripulante.hpp"
#include "../entidades/inimigos/Smilinguido/Smilinguido.hpp"
#include "../entidades/inimigos/Tentaculo/Tentaculo.hpp"
#include "../entidades/inimigos/Amalgama/Amalgama.hpp"
#include "../entidades/itens/itens.hpp"

Atos::Atos(Mapa* mapa, Protagonista* violeta, std::vector<Music>* trilha) {
    this->mapa = mapa;
    this->violeta = violeta;
    this->trilha = trilha;
    this->atoAtual = HistoryState::ACT_0;
}

void Atos::iniciarAto(HistoryState novoAto) {

    this->atoAtual = novoAto;

    for(auto& musica: *trilha){
        StopMusicStream(musica);
    }

     static vector<NPC*> npcs;
     static vector<Inimigo*> inimigos;

    if(novoAto == HistoryState::ACT_0){
        this->mapa->setMapa(0);
        PlayMusicStream((*trilha)[0]);

        violeta->setInfeccao(50);
        npcs = {
            new NPC("../../../assets/Spritesheets/NPCS/tripulante1.png",Vector2{35,900}),
            new NPC("../../../assets/Spritesheets/NPCS/tripulante2.png",Vector2{800,700}),
            new NPC("../../../assets/Spritesheets/NPCS/tripulante3.png",Vector2{1000,150}),
            new NPC("../../../assets/Spritesheets/NPCS/tripulante4.png",Vector2{1080,660}),
            new NPC("../../../assets/Spritesheets/NPCS/tripulante5.png",Vector2{500,450}),
            new NPC("../../../assets/Spritesheets/NPCS/tripulante6.png",Vector2{920,900}),
            new NPC("../../../assets/Spritesheets/NPCS/tripulante7.png",Vector2{800,150})
        };

        new Item ("Consumível", 100, "Integridade", "../../../assets/Spritesheets/Itens/Capacete.png", { 180,1150 });
        new Item ("Consumivel", 0, "Chave", "../../../assets/Spritesheets/Itens/CaixaDeFerramentas.png", Vector2{200,1150});

        // - Dar spawn nos NPCs iniciais
    } else if(novoAto == HistoryState::ACT_1){
        this->mapa->setMapa(2);
        PlayMusicStream((*trilha)[1]);

        for(NPC *npc : npcs){
            Globais::removerListaRenderizacao(npc);
        }

       	new Item ("Consumível", 50, "Infecção", "../../../assets/Spritesheets/Itens/Xarope.png", { 600,750 });
       	new Item ("Consumível", 50, "Infecção", "../../../assets/Spritesheets/Itens/Xarope.png", { 540,1080 });
        new Item ("Consumível", 100, "Oxigênio", "../../../assets/Spritesheets/Itens/TanqueO2.png", { 1000, 430 });
        new Item ("Consumível", 100, "Oxigênio", "../../../assets/Spritesheets/Itens/TanqueO2.png", { 260, 560 });
        new Item ("Consumível", 100, "Oxigênio", "../../../assets/Spritesheets/Itens/TanqueO2.png", { 1410, 1025 });
        new Item ("Consumível", 30, "Integridade", "../../../assets/Spritesheets/Itens/SilverTape.png", {725,650});
        new Item ("Arma", 20, "Martelo", "../../../assets/Spritesheets/Itens/Martelo.png", { 100, 750 });
        new Item ("Arma", 50, "Taser", "../../../assets/Spritesheets/Itens/Taser.png", { 1460,1110 });
        new Item ("Chave", 0, "KeyCard", "../../../assets/Spritesheets/Itens/KeyCard.png", { 1030,840 });

        Inimigo *inimigo1 = new Tripulante(100,10,10,10);
        inimigo1->setPosicao(Vector2{20,540});
        inimigos.push_back(inimigo1);

        Inimigo *inimigo2 = new Smilinguido(100,10,10,30);
        inimigo2->setPosicao(Vector2{920,910});
        inimigos.push_back(inimigo2);

        Inimigo *inimigo3 = new Tripulante(100,10,10,10);
        inimigo3->setPosicao(Vector2{1160,260});
        inimigos.push_back(inimigo3);

        Inimigo *inimigo4 = new Smilinguido(100,10,10,30);
        inimigo4->setPosicao(Vector2{1475,450});
        inimigos.push_back(inimigo4);

        Inimigo *inimigo5 = new Tentaculo(100,10,30,20);
        inimigo5->setPosicao(Vector2{725,650});
        inimigos.push_back(inimigo5);

        Inimigo *inimigo6 = new Tripulante(100,10,10,10);
        inimigo6->setPosicao(Vector2{1180,660});
        inimigos.push_back(inimigo6);

        Inimigo *inimigo7 = new Amalgama(100,10,0,0);
        inimigo7->setPosicao(Vector2{700,240});
        inimigos.push_back(inimigo7);

        Inimigo *inimigo8 = new Tentaculo(100,10,30,20);
        inimigo8->setPosicao(Vector2{1800,910});
        inimigos.push_back(inimigo8);






        // - Dar spawn nos inimigos novos
        // - Remover NPCs antigos
    } else if(novoAto == HistoryState::ACT_2){
        this->mapa->setMapa(3);
        PlayMusicStream((*trilha)[2]);
    }
}

void Atos::Update(){
    if (atoAtual == HistoryState::ACT_0) {
        UpdateMusicStream((*trilha)[0]);
    } else if (atoAtual == HistoryState::ACT_1) {
        UpdateMusicStream((*trilha)[1]);
    } else if (atoAtual == HistoryState::ACT_2) {
        UpdateMusicStream((*trilha)[2]);
    }

    Vector2 posVioleta = violeta->getPosicao();

    // GATILHOS DE MUDANÇA DE ESTADO
    if (atoAtual == HistoryState::ACT_0) {

            if (!ativouDialogoInicial) {
                idDialogoAtual = "interfone"; // Violeta recebe o chamado
                IsDialogueActive = true;
                ativouDialogoInicial = true;
            }

            if (!consertouMeteoro) {
                // Se ela chegar perto do meteoro
                if (violeta->getPosicao().x > 1800) {
                    consertouMeteoro = true; // Liberada para voltar a dormir
                    this->mapa->setMapa(1);
                }
            }

            else if (!foiDormir) {
                Vector2 posCama = { 15.0f, 1075.0f };

                // Se ela voltou pra cama e fechou qualquer diálogo anterior
                if (Vector2Distance(posVioleta, posCama) < 60.0f && !IsDialogueActive) {
                    idDialogoAtual = "mimir";
                    IsDialogueActive = true;
                    foiDormir = true;

                    iniciarAto(HistoryState::ACT_1);
                    violeta->setPosicao(posCama);
                }
            }
    }
    else if (atoAtual == HistoryState::ACT_1) {

            if (!ativouCafe && !IsDialogueActive && foiDormir) {
                idDialogoAtual = "cafe";
                IsDialogueActive = true;
                ativouCafe = true;
            }

            if (ativouCafe && !ativouCadeTodoMundo && posVioleta.y < 1000.0f && !IsDialogueActive) {
                idDialogoAtual = "cadeTodoMundo";
                IsDialogueActive = true;
                ativouCadeTodoMundo = true;
            }

            if (ativouCadeTodoMundo && !ativouQuedaEnergia && posVioleta.x > 300.0f && !IsDialogueActive) {
                idDialogoAtual = "oxiB";
                IsDialogueActive = true;
                ativouQuedaEnergia = true;

            }

            if (ativouQuedaEnergia && !ativouPerseguicao && !IsDialogueActive) {
                idDialogoAtual = "tripulantes";
                IsDialogueActive = true;
                ativouPerseguicao = true;

            }

            Vector2 posAlaNRG = { 675.0f, 730.0f };
            if (ativouPerseguicao && !ativouEnergiaVoltou && Vector2Distance(posVioleta, posAlaNRG) < 60.0f && !IsDialogueActive) {
                idDialogoAtual = "acesso";
                IsDialogueActive = true;
                ativouEnergiaVoltou = true;
            }

            Vector2 posSalaComando = { 940.0f, 260.0f };
            if (ativouEnergiaVoltou && !ativouSalaControle && Vector2Distance(posVioleta, posSalaComando) < 60.0f && !IsDialogueActive) {
                idDialogoAtual = "naoSobrouNada_a";
                IsDialogueActive = true;
                ativouSalaControle = true;
                iniciarAto(HistoryState::ACT_2);
            }
        }
    else if (atoAtual == HistoryState::ACT_2) {

            Vector2 posQuartoComandante = { 1280.0f, 850.0f };

            if (!pegouChave && Vector2Distance(posVioleta, posQuartoComandante) < 60.0f && !IsDialogueActive) {
                idDialogoAtual = "chave";
                IsDialogueActive = true;
                pegouChave = true;
            }

            Vector2 posCapsula = { 1260.0f, 1111.0f };

            if (pegouChave && !tentouFugirSemGasosa && Vector2Distance(posVioleta, posCapsula) < 60.0f && !IsDialogueActive) {
                idDialogoAtual = "combustivel";
                IsDialogueActive = true;
                tentouFugirSemGasosa = true;
            }

            Vector2 posSalaCombustivel = { 670.0f, 730.0f };

            if (tentouFugirSemGasosa && !pegouCombustivel && Vector2Distance(posVioleta, posSalaCombustivel) < 60.0f && !IsDialogueActive) {
                pegouCombustivel = true;
            }

            if (pegouCombustivel && !fugiu && Vector2Distance(posVioleta, posCapsula) < 60.0f && !IsDialogueActive) {
                idDialogoAtual = "final";
                IsDialogueActive = true;
                fugiu = true;
            }


            if (fugiu && !IsDialogueActive) {
                // Finalizar o jogo
            }
        }
}

void Atos::Missoes(){

    if (!consertouMeteoro) {
        DrawText("Fix the meteor", 1000, 0, 25, WHITE);
    }
    if (!foiDormir) {
        DrawText("Go to bed", 1000, 100, 25, WHITE);
    }

}