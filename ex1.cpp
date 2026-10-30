
#include <iostream>
using namespace std;

int main() {
    int n;

    // Demander la taille du tableau
    cout << "Donner la taille du tableau : ";
    cin >> n;

    // Allocation dynamique
    int* T = new int[n];

    // Saisie des éléments
    cout << "Saisir les elements du tableau :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "T[" << i << "] = ";
        cin >> T[i];
    }

    // Affichage des éléments
    cout << "\nLes elements du tableau sont :" << endl;
    for (int i = 0; i < n; i++) {
        cout << T[i] << " ";
    }

    // Libération de la mémoire
    delete[] T;

    return 0;
}
