#ifndef DIALOGO_H
#define DIALOGO_H

#include "raylib.h"
#include <string>
#include <vector>
#include <locale.h>

// Variáveis globais apenas declaradas
Image CxDialogoImage;
Texture2D CxDialogoTexture;
Font font;
bool IsDialogueActive = true;

// Função de inicialização para carregar e redimensionar a imagem
inline void InicializarDialogoAssets()
{
    CxDialogoImage = LoadImage("../../../assets/Spritesheets/UI/CaixaDeDialogo.png");
    ImageResizeNN(&CxDialogoImage, 1280, 720);
    CxDialogoTexture = LoadTextureFromImage(CxDialogoImage);
    UnloadImage(CxDialogoImage);
};

void DesenharTexto(const char* speaker, const char* message, const char* message2) {
        DrawTextureRec(CxDialogoTexture, Rectangle{ 0, 0, (float)CxDialogoTexture.width, (float)CxDialogoTexture.height }, Vector2{ 0, 0 }, WHITE);
        DrawText(speaker, 300, 520, 25, WHITE);
        DrawText(message, 400, 570, 24, WHITE);
        DrawText(message2, 400, 600, 24, WHITE);
};

void Dialogue(const std::string& id) {
	if (!IsDialogueActive) return;
       if (id == "interfone") {
            DesenharTexto("INTERCOM", "Violeta, your repair services are required", "We've been hit by a non-identified body on C++ aisle");
       }
       if (id == "npc1_a") {
           DesenharTexto("CREW MEMBER", "Hey, Violeta, you're the only one who locks", "your bedroom door every night, why is that?");
       }
       if (id == "npc1_b") {
           DesenharTexto("VIOLETA", "My mother always scolded me when I didn't", "turn the key twice.");
       }
       if (id == "npc2") {
           DesenharTexto("CREW MEMBER", "I want to put my helmet.", "It will surely hide my hairline.");
       }
       if (id == "npc3") {
           DesenharTexto("CREW MEMBER", "Shh, don't tell him the helmet is transparent.", "");
       }
       if (id == "acesso") {
           DesenharTexto("VIOLETA", "ok... I think I can acess it now.", "I hope it isn't too late.");
       }
       if (id == "alaNRG_a") {
           DesenharTexto("VIOLETA", "Is everyone like this? What do I do? Think... Think...", "The Control Room! Surely I can acess the cameras!");
       }
       if (id == "alaNRG_b") {
           DesenharTexto("VIOLETA", "Darn it! No power! I need to activate the emergency reserve.", "If I'm not mistaken, the circuit breakers are on the NRG aisle.");
       }
       if (id == "cadeTodoMundo") {
           DesenharTexto("VIOLETA", "Where is everyone? Are those slackers sleeping? I can't", "judge them, it's hard to tell time without the sunlight or the birds");
       }
       if (id == "cafe1") {
           DesenharTexto("VIOLETA", "How quiet... It's weird,", "usually they're always asking me to fix things.");
       }
       if (id == "cafe2") {
           DesenharTexto("VIOLETA", "Maybe they let me sleep more since I fixed that problem yesterday.", "Anyways... Let me make some coffee 'cause nobody's made of steel.");
       }
       if (id == "chave") {
           DesenharTexto("VIOLETA", "YES! I knew it was here!", "I'm almost there... Just gotta gather my forces and go for the pods.");
       }
       if (id == "combustivel") {
           DesenharTexto("VIOLETA", "Urgh! Are you kidding me?", "I just came from the fuel tanks!");
       }
       if (id == "final") {
           DesenharTexto("VIOLETA", "What is this thing!? It keeps getting bigger!", "I need to report this to home base. I'm glad I escaped.");
       }
       if (id == "mimir") {
           DesenharTexto("VIOLETA", "ZZZ...", "");
       }
       if (id == "naoSobrouNada_a") {
           DesenharTexto("VIOLETA", "I can't believe it! There's nothing left! What do I do?", "I need to get on an escape pod and get out of here!");
       }
       if (id == "naoSobrouNada_b") {
           DesenharTexto("VIOLETA", "They're located on the section Return 0, but I'm not with the key", "It must be on my commander's room. Please be there...");
       }
       if (id == "oxiB") {
           DesenharTexto("VIOLETA", "Holy JB!", "What is this thing?");
       }
       if (id == "tripulantes") {
           DesenharTexto("VIOLETA", "Guys... You're scaring me.", "Back off!!");
       }
       if (id == "aperteC") {
           DesenharTexto("NOME", "Aperte C para fechar o diálogo", "");
       }
       if (id == "idd") {
           DesenharTexto("VIOLETA", "", "");
       }
        // Adicione outros casos conforme necessário
};

#endif
