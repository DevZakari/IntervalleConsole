#include "Intervalle.h"
#include "assert.h"

Intervalle::Intervalle(double inf, double sup)
{
    if (inf < sup) {
        this->intervalle[0] = inf;
        this->intervalle[1] = sup;
    }
    else {
        this->intervalle[0] = sup;
        this->intervalle[1] = inf;
    }
}

void Intervalle::AfficherMin() const
{
    cout << "La borne inferieur est : " << this->intervalle[0] << endl;
}

void Intervalle::AfficherMax() const
{
    cout << "La borne superieur est : " << this->intervalle[1] << endl;
}

bool Intervalle::operator[](const double number)
{
    
    return (this->intervalle[0] <= number && number <= this->intervalle[1]);
    
}

Intervalle& Intervalle::operator|(Intervalle& interV)
{
    Intervalle* ResIntervalle = new Intervalle(0,0);
    if (interV.intervalle[0] > this->intervalle[0])
        ResIntervalle->intervalle[0] = this->intervalle[0];
    else
        ResIntervalle->intervalle[0] = interV.intervalle[0];

    if (interV.intervalle[1] > this->intervalle[1])
        ResIntervalle->intervalle[1] = interV.intervalle[1];
    else
        ResIntervalle->intervalle[1] = interV.intervalle[1];

    return *ResIntervalle;
}

Intervalle& Intervalle::operator&(Intervalle& interV)
{
    if (interV[this->intervalle[0]] && interV[this->intervalle[1]])
        return *this;

    if ((*this)[interV.intervalle[0]] && (*this)[interV.intervalle[1]])
        return interV;

    Intervalle* result = new Intervalle(0, 0);
    if (this->intervalle[0] < interV.intervalle[1] && interV.intervalle[0] < this->intervalle[1])
    {
        result->intervalle[0] = (this->intervalle[0] > interV.intervalle[0]) ? this->intervalle[0] : interV.intervalle[0];
        result->intervalle[1] = (this->intervalle[1] < interV.intervalle[1]) ? this->intervalle[1] : interV.intervalle[1];

        return *result;
    }
    if (this->intervalle[1] == interV.intervalle[0]) {
        Intervalle* re = new Intervalle(this->intervalle[1], this->intervalle[1]);
        return *re;
    }
    if (this->intervalle[0] == interV.intervalle[1]) {
        Intervalle* re = new Intervalle(this->intervalle[0], interV.intervalle[1]);
        return *re;
    }


    cout << "\nPas d'intersection\n" << endl;
    return *result;

}

Intervalle& Intervalle::operator()(double w)
{
    this->intervalle[0] += w; this->intervalle[1] += w;
    return *this;
}
void Intervalle::afficherIntervalle() const
{
    cout << endl << "[" << this->intervalle[0] << "," << this->intervalle[1] << "]" << endl;
}
