#pragma once

#include <raylib.h>
#include <vector>

using namespace std;

class Mapa{

    private:
        
        static int mapaAtual;
        static vector<Texture2D> mapasTextures;
        static vector<Image> mapasImage;


    public: 
        Mapa();

        void carregarMapas(vector<Texture2D> mapas);
        void carregarImagensDeColisao(vector<Image> imagens);
        static void setMapa(int index) {mapaAtual = index;}

        void Draw();

        static bool estaCollidindo(Vector2 Offset, Rectangle colisao);

};  