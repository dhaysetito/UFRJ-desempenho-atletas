#include <numeric>
#include <iostream>
#include <algorithm>

#include "atleta.h"

Atleta::Atleta(std::string nome, std::vector<double> tempos) : nome(nome), tempos(tempos) {}

std::string Atleta::getNome() {
    return nome;
}

std::vector<double> Atleta::getTempos() {
    return tempos;
}

double Atleta::calcularMediaMovel(int N) {
    if (tempos.size() < static_cast<size_t>(N)) return -1;
    return std::accumulate(tempos.end() - N, tempos.end(), 0.0) / N;
}

double Atleta::calcularMediaMovelAnterior(int N) {
    if (tempos.size() < static_cast<size_t>(N + 1)) return -1;
    return std::accumulate(tempos.end() - N - 1, tempos.end() - 1, 0.0) / N;
}

double Atleta::calcularMelhorTempo() {
    return *std::min_element(tempos.begin(), tempos.end());
}

double Atleta::preverProximoTempo() {
    int n = tempos.size();
    double xSum = 0, ySum = 0, xySum = 0, xxSum = 0;

    for (int i = 0; i < n; ++i) {
        xSum += i + 1;
        ySum += tempos[i];
        xySum += (i + 1) * tempos[i];
        xxSum += (i + 1) * (i + 1);
    }

    double b = (n * xySum - xSum * ySum) / (n * xxSum - xSum * xSum);
    double a = (ySum - b * xSum) / n;

    return a + b * (n + 1); // Previsão para o próximo treino
}