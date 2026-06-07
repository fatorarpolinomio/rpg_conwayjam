#ifndef INIMIGOS_H
#define INIMIGOS_H

#include "../entidade.hpp"
#include <vector>

using namespace std;

class Inimigo : public Entidade{
    private:

        double MaxVida;
        double Vida;
        double TaxaRegen;
        double TaxaInfec;
        double Dano;
        double MaxVelocidade = 2;
        double Velocidade = 2;

    public:

        static vector<Inimigo*> Inimigos;

        Inimigo(double max, double regen, double infec, double dano);
        Inimigo() = default;
        virtual ~Inimigo() = default;

        double GetVida(){return Vida;}
        double GetRegen(){return TaxaRegen;}
        double GetInfec(){return TaxaInfec;}
        double GetDano(){return Dano;}
        double GetMax(){return MaxVelocidade;}
        double GetVelocidade(){return Velocidade;}
        
        void SetVelocidade(double newVel){ Velocidade = newVel;}

        void TomarDano(double dano){ Vida -= dano; }

        virtual void Morrer();
        virtual void Ataque();
        virtual void Ataque2();

        void Update() override;
        void Draw() override;

};

#endif
