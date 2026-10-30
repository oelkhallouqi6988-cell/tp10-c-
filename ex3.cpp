
#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    float prix;

public:
    // Constructeur
    Livre() {
        titre = "";
        prix = 0;
    }

    // Saisie des informations
    void saisir() {
        cout << "Donner le titre du livre : ";
        getline(cin >> ws, titre);

        cout << "Donner le prix du livre : ";
        cin >> prix;
    }

    // Affichage des informations
    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;

    // Demander le nombre de livres
    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;

    // Allocation dynamique du tableau
    Livre* T = new Livre[n];

    // Saisie des livres
    for (int i = 0; i < n; i++) {
        cout << "\nLivre numero " << i + 1 << endl;
        T[i].saisir();
    }

    // Affichage des livres
    cout << "\n===== Liste des livres =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nLivre numero " << i + 1 << endl;
        T[i].afficher();
    }

    // Libération de la mémoire
    delete[] T;
    T = nullptr;

    return 0;
}
