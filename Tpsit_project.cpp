#include <iostream>
#include <string>
#include <vector>
#include "Invest.h"
#include "User.h"

using namespace std;

User createUser();                    // - Prototype of create User
Investment createInvestment();        // - Prototype of create Investment

int main(){              // This is the interface

    cout << "****************************************************************" << endl;
    cout << "Benvenuto nella Banca Vito Volterra ---> " << endl;
    cout << "****************************************************************" << endl;
    cout << endl;

    cout << "Accedi alla nostra piattaforma, o se non hai un account cosa aspetti a registrati!! " << endl;

    User Main = createUser();
    vector <User> list_Accounts;
    list_Accounts.push_back(Main);

    char options {' '};
    bool check{ 0 };
    cout << endl;

    do {

        cout << "Schermata Principale ---> " << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Scegli tra le seguenti opzioni: " << endl;
        cout << "Crea un nuovo Account (opzione a); " << endl;
        cout << "Scollegati dal Account (opzione b); " << endl;
        cout << "Deposita i soldi all'interno della tua banca (opzione c); " << endl;
        cout << "Preleva i soldi dalla tua banca (opzione d); " << endl;
        cout << "Crea un investimento (opzione e); " << endl;
        cout << "Mostra il tuo stato (opzione f); " << endl;
        cout << endl;
        cout << "Immetti l'opzione scelta: ";
        cin >> options;

        switch (options) {

        case 'a': {       // creates a secondary Account

            list_Accounts.push_back(createUser());
            break;
        }
        case 'b': {       // eliminate the account that you choose

            int eliminate{ 0 };
            cout << "Immetti il numero dell'Account in ordine cronologico: ";
            cin >> eliminate;

            for (int i{ 0 }; i < list_Accounts.size(); i++) {
                if ((eliminate-1) == i) {
                    list_Accounts[i].~User();
                    list_Accounts.pop_back();
                }
            }
            break;
        }
        case 'c': {       // deposit money from your wallet to your bank

            int depositedMoney{ 0 };
            int N_User{ 0 };

            cout << "Digita la somma di denaro che vuoi depositare: ";
            cin >> depositedMoney;

            cout << "Immetti il numero dell'Account in ordine cronologico: ";
            cin >> N_User;

            for (int i{ 0 }; i < list_Accounts.size(); i++) {
                if ((N_User-1) == i) {
                    list_Accounts[i].depositMoney(depositedMoney);
                }
            }
            break;
        }
        case 'd': {       // withdraw money from your bank to your wallet

            int withdrawMoney{ 0 };
            int N_User1{ 0 };

            cout << "Digita la somma di denaro che vuoi prelevare: ";
            cin >> withdrawMoney;

            cout << "Immetti il numero dell'Account in ordine cronologico: ";
            cin >> N_User1;

            for (int i{ 0 }; i < list_Accounts.size(); i++) {
                if ((N_User1-1) == i) {
                    list_Accounts[i].withdrawMoney(withdrawMoney);
                }
            }
            break;
        }
        case 'e': {       // creates an investment 

            bool total_investment{ 1 };
            bool InvestmentUser{ 0 };
            vector <Investment> list_investment;

            while (total_investment != 0) {
                Investment my_investment = createInvestment();
                list_investment.push_back(my_investment);
                cout << "Vuoi continuare a creare progetti per dei investimenti? " << endl;
                cout << "(si = 1) o (no = 0) :";
                cin >> total_investment;
            }

            do {

                int N_User3{ 0 };
                cout << "Immetti il numero dell'Account in ordine cronologico: ";
                cin >> N_User3;

                for (int i{ 0 }; i < list_Accounts.size(); i++) {

                    if ((N_User3 - 1) == i) {

                        int N_Investment{ 0 };
                        cout << "Immetti quale investimento vuoi attivare, sempre in ordine cronologico: " << endl;
                        cin >> N_Investment;

                        for (int j{ 0 }; j < list_investment.size(); j++) {

                            if ((N_Investment - 1) == j) {
                                list_Accounts[i].getInvestment(list_investment[j]);
                            }

                        }
                    }
                }
                cout << "Vuoi continuare a applicare i progetti dei investimenti e assegnarli a utenti " << endl;
                cout << "(si = 1) o (no = 0) : ";
                cin >> InvestmentUser;
            } while (InvestmentUser != 0);
            break;
        }

        case 'f': {       // shows you, your bank and your wallet state

            int N_User4{ 0 };
            cout << "Immetti il numero dell'Account in ordine cronologico: ";
            cin >> N_User4;

            for (int i{ 0 }; i < list_Accounts.size(); i++) {
                if ((N_User4-1) == i) {
                    list_Accounts[i].bankState();
                    list_Accounts[i].walletState();
                }
            }
            break;
        }
        default:
            cerr << "Arresto dovuto alla sbagliata opzione.." << endl;
            return 1;
        }
        cout << "Desideri continuare a usare la banca " << endl;
        cout << "Vuoi ritornare alla schermata principale (si = 1) (no = 0) ---> ";
        cin >> check;
    } while (check != 0);
    cout << "Arrivedenci da Banca Vito Volterra !! " << endl;
    return 0;
}

User createUser() {      // This function creates an Account

    string name;
    double wallet{ 0 }, bank_money{ 0 };
    cout << "Scrivi il nome che possiedera l'account: ";
    cin >> name;
    cout << "Digita la somma di denaro dalla quale partira il tuo conto in banca: ";
    cin >> bank_money;
    cout << "Digita la somma di denaro in contatti che hai fisicamente: ";
    cin >> wallet;

    User a1(name, bank_money, wallet);
    return a1;
}

Investment createInvestment() {     // This function creates an Investment

    int amount{ 0 }, duration{ 0 }, risk{ 0 };
    cout << "Digita la somma di denaro che inizia l'investimento: ";
    cin >> amount;
    cout << "Digita il tempo in mesi, necessari all'investimento: ";
    cin >> duration;
    cout << "Digita un numero da 1-10 " << endl;
    cout << "Che determina il livello del rischio che l'investimento prende: ";
    cin >> risk;

    Investment b1(amount, duration, risk);
    return b1;
}