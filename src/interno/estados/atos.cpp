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

        npcs = {
            new NPC("../assets/Spritesheets/NPCS/tripulante1.png",Vector2{35,900}),
            new NPC("../assets/Spritesheets/NPCS/tripulante2.png",Vector2{800,700}),
            new NPC("../assets/Spritesheets/NPCS/tripulante3.png",Vector2{1000,150}),
            new NPC("../assets/Spritesheets/NPCS/tripulante4.png",Vector2{1080,660}),
            new NPC("../assets/Spritesheets/NPCS/tripulante5.png",Vector2{500,450}),
            new NPC("../assets/Spritesheets/NPCS/tripulante6.png",Vector2{920,900}),
            new NPC("../assets/Spritesheets/NPCS/tripulante7.png",Vector2{800,150})
        };

       	new Item ("Consumível", 50, "Infecção", "../assets/Spritesheets/Itens/Xarope.png", { 600,750 });
        new Item ("Consumível", 100, "Oxigênio", "../assets/Spritesheets/Itens/TanqueO2.png", { 1000, 1000 });
        new Item ("Consumível", 30, "Integridade", "../assets/Spritesheets/Itens/SilverTape.png", { 1000,1000 });
        new Item ("Consumível", 100, "Integridade", "../assets/Spritesheets/Itens/Capacete.png", { 1000,1000 });
        new Item ("Arma", 20, "", "../assets/Spritesheets/Itens/Martelo.png", { 1000,1000 });
        new Item ("Arma", 50, "", "../assets/Spritesheets/Itens/Taser.png", { 1000,1000 });
        new Item ("Chave", 0, "", "../assets/Spritesheets/Itens/KeyCard.png", { 1000,1000 });
        new Item ("Chave", 0, "", "../assets/Spritesheets/Itens/CaixaDeFerramentas.png", { 1000,1000 });

        new Item ("Consumivel", 0, "Chave", "../assets/Spritesheets/Itens/CaixaDeFerramentas.png", Vector2{200,1150});

        // - Dar spawn nos NPCs iniciais
    } else if(novoAto == HistoryState::ACT_1){
        this->mapa->setMapa(1);
        PlayMusicStream((*trilha)[1]);

        for(NPC *npc : npcs){
            Globais::removerListaRenderizacao(npc);
        } 

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
        this->mapa->setMapa(2);
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

    // GATILHOS DE MUDANÇA DE ESTADO
    if (atoAtual == HistoryState::ACT_0) {
        // Exemplo: Se a Violeta andar até a porta (ex: X for maior que 2000), vai pro Ato 1
        if (violeta->getPosicao().x > 1800) {
            iniciarAto(HistoryState::ACT_1);
        }
    } else if (atoAtual == HistoryState::ACT_1) {
        // Exemplo: Se a infecção chegar a 50, muda pro Ato 2
        // if (violeta->getInfeccao() > 50) { IniciarAto(HistoryState::ACT_2); }
    } else if (atoAtual == HistoryState::ACT_2) {

    }
}
