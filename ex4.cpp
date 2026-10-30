
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    // Constructeur
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    // Retourner le nom
    string getNom() {
        return nom;
    }

    // Afficher les informations
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

// Ajouter un contact
void ajouterContact(Contact** carnet, int& n) {
    string nom, telephone, email;

    cout << "Donner le nom : ";
    getline(cin >> ws, nom);

    cout << "Donner le telephone : ";
    getline(cin, telephone);

    cout << "Donner l'email : ";
    getline(cin, email);

    carnet[n] = new Contact(nom, telephone, email);

    n++;

    cout << "Contact ajoute avec succes !" << endl;
}

// Afficher tous les contacts
void afficherContacts(Contact** carnet, int n) {
    if (n == 0) {
        cout << "Le carnet est vide !" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nContact numero " << i + 1 << endl;
        carnet[i]->afficher();
    }
}

// Supprimer un contact par son nom
void supprimerContact(Contact** carnet, int& n, string nom) {
    int position = -1;

    for (int i = 0; i < n; i++) {
        if (carnet[i]->getNom() == nom) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "Contact introuvable !" << endl;
        return;
    }

    // Liberer la memoire du contact
    delete carnet[position];

    // Decaler les pointeurs
    for (int i = position; i < n - 1; i++) {
        carnet[i] = carnet[i + 1];
    }

    n--;

    carnet[n] = nullptr;

    cout << "Contact supprime avec succes !" << endl;
}

int main() {
    int capacite = 100;
    int n = 0;
    int choix;
    string nom;

    // Allocation dynamique du tableau de pointeurs
    Contact** carnet = new Contact*[capacite];

    do {
        cout << "\n===== CARNET D'ADRESSES =====" << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "4. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                if (n < capacite) {
                    ajouterContact(carnet, n);
                } else {
                    cout << "Carnet plein !" << endl;
                }
                break;

            case 2:
                afficherContacts(carnet, n);
                break;

            case 3:
                cout << "Donner le nom du contact a supprimer : ";
                getline(cin >> ws, nom);
                supprimerContact(carnet, n, nom);
                break;

            case 4:
                cout << "Fermeture du programme..." << endl;
                break;

            default:
                cout << "Choix invalide !" << endl;
        }

    } while (choix != 4);

    // Liberer tous les contacts restants
    for (int i = 0; i < n; i++) {
        delete carnet[i];
    }

    // Liberer le tableau de pointeurs
    delete[] carnet;
    carnet = nullptr;

    cout << "Memoire liberee avec succes !" << endl;

    return 0;
}
