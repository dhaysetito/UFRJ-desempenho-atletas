#ifndef ATLETA_H
#define ATLETA_H

#include <vector>
#include <string>

class Atleta {
    private:
        std::string nome;
        std::vector<double> tempos;

    public:
        Atleta(std::string nome, std::vector<double> tempos);
        
        std::string getNome();
        std::vector<double> getTempos();
        
        double calcularMediaMovel(int N);
        double calcularMediaMovelAnterior(int N);
        double calcularMelhorTempo();
        double preverProximoTempo();
    };

#endif