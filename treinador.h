#ifndef TREINADOR_H
#define TREINADOR_H

#include <vector>
#include "atleta.h"

class Treinador {
private:
    std::vector<Atleta> atletas;

public:
    Treinador();
    
    void adicionarAtleta(Atleta atleta);
    void exibirEvolucaoMedia();
    void exibirMelhoriaDesempenho();
    void ordenarAtletasPorMedia();
    void ordenarAtletasPorMelhorTempo();
    void preverProximoTempo();
};

#endif