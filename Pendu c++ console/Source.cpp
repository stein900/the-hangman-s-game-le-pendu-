
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#define espace "\t\t\t\t\t\t"
#define espace2 "\t\t\t\t\t\t     "

using namespace std;

int main() {
    vector<string> words{ "camion", "biologie", "oignon", "noisette", "abricot", "ananas", "chien", "chat", "maison", "voiture", "velo", "livre", "arbre", "table", "ordinateur", "stylo", "feuille", "oiseau", "terre", "ciel", "mer", "lac", "montagne", "route", "pont", "fleur", "fruit", "legume", "pomme", "poire", "banane", "orange", "kiwi", "ananas", "raisin", "abricot", "cerise", "noix", "noisette", "amande", "pistache", "avocat", "aubergine", "tomate", "courgette", "poivron", "oignon", "ail", "sel", "poivre", "sucre", "farine", "beurre", "huile", "vinaigre", "moutarde", "stein", "portable", "sac", "cafe", "the", "chocolat", "pain", "croissant", "jus", "eau", "bière", "vin", "lait", "fromage", "yaourt", "crème", "miel", "confiture", "nutella", "miel", "mouton", "poulet", "bœuf", "porc", "agneau", "veau", "poisson", "crevette", "huître", "moule", "crabe", "langouste", "ecrevisse", "escalope", "pâtes", "riz", "pizza", "hamburger", "frites", "salade", "sandwich", "steak", "saucisse", "jambon", "bacon", "chorizo", "saumon", "thon", "cabillaud", "epinards", "brocoli", "carotte", "concombre", "radis", "celeri", "persil", "basilic", "thym", "origan", "menthe", "citron", "orange", "mandarine", "pamplemousse", "anis", "cannelle", "gingembre", "curcuma", "cumin", "coriandre", "cardamome", "poivre noir", "paprika", "piment", "ail", "oignon", "echalote", "sel", "poivre", "sucre", "farine", "levure", "œuf", "mayonnaise", "ketchup", "tabasco" };

    srand(static_cast<unsigned int>(time(nullptr)));
    char valid = ' ';
    do{

        const string motADeviner = words[rand() % words.size()];
        string motAffiche(motADeviner.length(), '_');
        srand(time(NULL));
        int res1 = rand() % 16;

        int nbErreurs = 0;
        bool motTrouve = false;
        string pendu = "";
        string penduExemple = "...........";
        string historique = "";

        while (!motTrouve && nbErreurs < 11) {
            system("cls");
            cout << endl;
            cout << espace2 << pendu << endl;
            cout << espace2 << penduExemple << endl;
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << espace << "Mot a deviner : " << motAffiche << endl;
            cout << endl;
            cout << espace << historique<<endl << endl;
            char lettre;
            cout << espace << "Proposez une lettre : ";
            cin >> lettre;
            
            bool lettreTrouvee = false;
            for (int i = 0; i < motADeviner.length(); ++i) {
                if (motADeviner[i] == lettre) {
                    motAffiche[i] = lettre;
                    lettreTrouvee = true;
                }
            }
            if (!lettreTrouvee) {
                cout << espace << "La lettre " << lettre << " n'est pas dans le mot a deviner." << endl;
                ++nbErreurs;
                pendu += '|';
                historique += lettre; historique += ' ';
            }
            if (motADeviner == motAffiche) {
                motTrouve = true;
                cout << espace << "Bravo, vous avez trouve le mot !" << endl;
            }
        }
        if (nbErreurs == 11) {
            cout << espace << "Dommage, vous avez perdu. Le mot a deviner etait : " << motADeviner << endl;
        }
        cout << espace << "voulez vous recommencer? (o:n)" << endl;
        cin >> valid;
        nbErreurs = 0;
        motTrouve = false;
        pendu = "";
        penduExemple = "...........";
    } while (valid != 'n');
   
    return 0;
}