#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include "../inimigos.hpp"

class Tripulante : public Inimigo{

    public:
        Tripulante(double max, double regen, double infec, double dano);

        void Morrer() override;
        void Update() override;
        void SeguirPlayer(Protagonista *player);
        void Ataque() override;
        void Draw() override;

};

#endif