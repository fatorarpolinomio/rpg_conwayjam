
#include "trilhaSonora.hpp"
#include <raylib.h>
#include <vector>
#include "../estados/estados.hpp"


void update_trilha_sonora(HistoryState estadoAnterior, HistoryState estadoAtual, const std::vector<Music>& trilha) {
    SetMasterVolume(0.7f);

    if (estadoAtual != estadoAnterior){
        StopMusicStream(trilha[0]);
        StopMusicStream(trilha[1]);
        StopMusicStream(trilha[2]);

        if(estadoAtual == HistoryState::ACT_0) PlayMusicStream(trilha[0]);
        if(estadoAtual == HistoryState::ACT_1) PlayMusicStream(trilha[1]);
        if(estadoAtual == HistoryState::ACT_2) PlayMusicStream(trilha[2]);

        estadoAnterior = estadoAtual;
    }

    if(estadoAtual == HistoryState::ACT_0) UpdateMusicStream(trilha[0]);
    if(estadoAtual == HistoryState::ACT_1) UpdateMusicStream(trilha[1]);
    if(estadoAtual == HistoryState::ACT_2) UpdateMusicStream(trilha[2]);
}
