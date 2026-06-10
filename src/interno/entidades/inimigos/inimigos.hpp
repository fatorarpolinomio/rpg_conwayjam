#ifndef INIMIGOS_H
#define INIMIGOS_H

#include "../entidade.hpp"
#include <vector>
#include "../protagonista/protagonista.hpp"

using namespace std;

class Inimigo : public Entidade{
    protected:

        Sound grunir = LoadSound("../../../../assets/audio/sfx/somInimigo1.wav");
        Sound grunir2 = LoadSound("../../../../assets/audio/sfx/somInimigo2.wav");
        Sound grunir3 = LoadSound("../../../../assets/audio/sfx/somInimigo3.wav");
        Sound gritar = LoadSound("../../../../assets/audio/sfx/gritoInimigo1.wav");
        Sound gritar2 = LoadSound("../../../../assets/audio/sfx/gritoInimigo2.wav");
        Sound gritar3 = LoadSound("../../../../assets/audio/sfx/gritoInimigo3.wav");
        Sound scare = LoadSound("../../../../assets/audio/sfx/scare.wav");

    
    private:

        double MaxVida;
        double Vida;
        double TaxaRegen;
        double TaxaInfec;
        double Dano;
        double MaxVelocidade = .005f;
        double Velocidade = 2;
    public:
    
        Inimigo(double max, double regen, double infec, double dano);
        Inimigo() = default;
        virtual ~Inimigo() = default;

        double GetVida(){return Vida;}
        double GetRegen(){return TaxaRegen;}
        double GetInfec(){return TaxaInfec;}
        double GetDano(){return Dano;}
        double GetMax(){return MaxVelocidade;}
        double GetVelocidade(){return Velocidade;}
        double GetMaxVelocidade(){return MaxVelocidade;}
        
        void SetVelocidade(double newVel){ Velocidade = newVel;}
        void SetMaxVelocidade(double newVel){ MaxVelocidade = newVel;}

        void TomarDano(double dano){ Vida -= dano; }

        virtual void Morrer();
        virtual void Seguir(Vector2 pos);
        virtual void Ataque();
        virtual void Ataque2();

        void TocarAudio(Sound som);

        void Update() override;
        void Draw() override;

};

#endif
