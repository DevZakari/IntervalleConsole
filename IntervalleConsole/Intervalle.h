#pragma once
#include <iostream>
#include <string>

using namespace std;

class Intervalle
{
private:
    double intervalle[2];
public:
    Intervalle(double inf, double sup);
        
    void AfficherMin()const;
    void AfficherMax()const;
    // operator : [] ; 
    bool operator [] (const double number);

    Intervalle& operator|(Intervalle& interV);
    Intervalle& operator& (Intervalle& Inte);
    Intervalle& operator ()(double w);
    void afficherIntervalle()const;
};

