
#include <iostream>
#include "Intervalle.h"

int main()
{
    Intervalle i1(1, 7);
    Intervalle* i2 = new Intervalle(3,9);
    i1.AfficherMax();
    i1.AfficherMin();

    cout << i1[0];
    cout << endl;
    // affichage d'intrevalle : 
    cout << "\n Affichage des intervalles : " << endl;
    i2->afficherIntervalle();
    i1.afficherIntervalle();
    // use of operator ()
    cout << "\n Apres l'utilisation de l'operateur () " << endl;
    i1(33);
    i1.afficherIntervalle();
    (*i2)(33);
    i2->afficherIntervalle();
    // use of operator | UNION:
    cout << " \n L'union de deux intervalles : " << endl;
    Intervalle iUnion = i1|(*i2);
    iUnion.afficherIntervalle();
    // use of operator & INTERSECTION:
    cout << " \n L'intersection de deux intervalles : " << endl;
    Intervalle iInters = i1 & (*i2);
    iInters.afficherIntervalle();
    system("pause>0");
}

