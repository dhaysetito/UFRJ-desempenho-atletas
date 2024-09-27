#include <iostream>
#include <algorithm>
#include <iomanip>

#include "treinador.h"

Treinador::Treinador() {}

void Treinador::adicionarAtleta(Atleta atleta) {
    atletas.push_back(atleta);
}

// Exibe a média de tempos de cada atleta até o tempo N que ele possui
void Treinador::exibirEvolucaoMedia() {
    for (auto& atleta : atletas) {
        std::cout << "Atleta: " << atleta.getNome() << "\n";
        
        // Obtém o número de tempos que o atleta possui
        int numeroDeTempos = atleta.getTempos().size();
        
        for (int N = 3; N <= numeroDeTempos; ++N) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Média móvel (N=" << N << "): " << atleta.calcularMediaMovel(N) << "\n";
            //if (N == 7) break;
        }
        std::cout << "\n";
    }
}

void Treinador::exibirMelhoriaDesempenho() {
    double limiar = 0.10;  // Limiar 10%
    int N;
    

    std::cout << "Digite quantos treinos devem ser considerados para cálculo da média (3 a 7): ";
    std::cin >> N;

    if (N < 3 || N > 7) {
        std::cout << "Valor inválido! Usando o valor padrão de N = 3.\n";
        N = 3; 
    }

    for (auto& atleta : atletas) {
        std::cout << "Atleta: " << atleta.getNome() << "\n";

        int numeroDeTempos = atleta.getTempos().size();

        double mediaAtual = atleta.calcularMediaMovel(N);
        double mediaAnterior = atleta.calcularMediaMovelAnterior(N-1);

        if (mediaAtual < 0 || mediaAnterior < 0 ||  N >= numeroDeTempos) {
            std::cout << "Dados insuficientes para calcular médias.\n";
            continue;
        }

        // Diferença percentual
        double diferenca = (mediaAnterior - mediaAtual) / mediaAnterior;

        // Imprime desempenho
        if (diferenca >= limiar) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "Melhoria de desempenho (" << diferenca * 100 << "% de redução no tempo).\n";
        } else if (diferenca <= -limiar) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "Piora de desempenho (" << -diferenca * 100 << "% de aumento no tempo).\n";
        } else {
            std::cout << "Desempenho estável.\n";
        }
    }
}

void Treinador::ordenarAtletasPorMedia() {
    std::sort(atletas.begin(), atletas.end(), [](Atleta& a, Atleta& b) {
        int N = a.getTempos().size(); // Obtém o número de tempos do atleta

        // Calcula a média móvel usando N
        double mediaA = a.calcularMediaMovel(N); 
        double mediaB = b.calcularMediaMovel(N);
        return mediaA < mediaB;
    });

    for (auto& atleta : atletas) {
        int N = atleta.getTempos().size(); // Obtém o número de tempos do 
        std::cout << std::fixed << std::setprecision(2);
        std::cout << atleta.getNome() << " - Média: " << atleta.calcularMediaMovel(N) << "\n";
    }
}

void Treinador::ordenarAtletasPorMelhorTempo() {
    std::sort(atletas.begin(), atletas.end(), [](Atleta& a, Atleta& b) {
        return a.calcularMelhorTempo() < b.calcularMelhorTempo();
    });

    for (auto& atleta : atletas) {
        std::cout << atleta.getNome() << " - Melhor Tempo: " << atleta.calcularMelhorTempo() << "\n";
    }
}

void Treinador::preverProximoTempo() {
    for (auto& atleta : atletas) {
        std::cout << "Atleta: " << atleta.getNome() << " - Previsão próximo tempo: " << atleta.preverProximoTempo() << "\n";
    }
}