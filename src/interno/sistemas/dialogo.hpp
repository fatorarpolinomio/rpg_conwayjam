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

// Função de inicialização para carregar e redimensionar a imagem
inline void InicializarDialogoAssets()
{
    CxDialogoImage = LoadImage("../../../assets/Spritesheets/UI/CaixaDeDialogo.png");
    ImageResizeNN(&CxDialogoImage, 1280, 720);
    CxDialogoTexture = LoadTextureFromImage(CxDialogoImage);
    UnloadImage(CxDialogoImage);
};

void DesenharTexto(const char* speaker, const char* message) {
    DrawTextureRec(CxDialogoTexture, Rectangle{ 0, 0, (float)CxDialogoTexture.width, (float)CxDialogoTexture.height }, Vector2{ 0, 0 }, WHITE);
    DrawText(speaker, 300, 520, 25, WHITE);
    DrawText(message, 400, 570, 24, WHITE);
};

void Dialogue(const std::string& id) {
        if (id == "interfone") {
            DesenharTexto("INTERFONE", "Violeta, seu serviço de reparo é requisitado");
        }
        // Adicione outros casos conforme necessário
};

#endif