
#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:
    // Constructeur
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    // Méthode d'affichage
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

int main() {

    // Création dynamique d'un objet
    Personne* p = new Personne("Ahmed", 22);

    // Affichage des informations
    cout << "Informations de la personne :" << endl;
    p->afficher();

    // Libération de la mémoire
    delete p;
    p = nullptr;

    return 0;
}
