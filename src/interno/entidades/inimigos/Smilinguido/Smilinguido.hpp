#ifndef SMILINGUIDO_H
#define SMILINGUIDO_H

#include "../inimigos.hpp"
#include "../../protagonista/protagonista.hpp"

class Smilinguido : public Inimigo{

    private:
        Vector2 dir;

    public:
        Smilinguido(double max, double regen, double infec, double dano);

    void SetDir(Vector2 newDir){dir = newDir;}
    Vector2 GetDir(){return dir;}

    void Ataque() override;
    void Update() override;
    void Draw() override;

};

#endif