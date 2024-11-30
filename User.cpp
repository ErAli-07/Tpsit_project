#include <iostream>
#include "User.h"
#include "Invest.h"

using namespace std;

int User::active_users = 0;                             // Number of user created

User::User(string name, double bank, double wallet){    // Constructor - give a value to the members of the User
    this->name = name;
	this->bank_account = bank;
	this->wallet = wallet;
	this->debt = 0;

	++active_users;
};

User::~User() {                                        // Destructor - eliminate the User 
	--active_users;
}

void User::depositMoney(double depositedMoney) {       // method that deposit money
	if ((wallet-depositedMoney)<=0) {
		cout << "il deposito di denaro viene annullato\n";
		cout << "Non si ha abbastanza soldi nel portafoglio\n";
		return;
	}
	wallet -= depositedMoney;
	bank_account += depositedMoney;
    cout << "Nella banca viene depositato una somma di " << depositedMoney << " euro\n";
}

void User::withdrawMoney(double takenMoney) {         // method that withdraw money
	if ((bank_account - takenMoney) <= 0) {
		cout << "il prelievo di denaro viene annullato\n";
		cout << "Non si puo prelevare da un conto in banca in debito o a zero\n";
		return;
	}
	wallet += takenMoney;
	bank_account -= takenMoney;
    cout << "Nella banca viene prelevato una somma di " << takenMoney << " euro\n";
}

void User::bankState() {                               // method that shows you your bank state
	cout << "La somma del capitale che si trova in banca corrisponde a " << bank_account << " euro\n";
}

void User::walletState() {                             // method that shows you your wallet state
	cout << "La somma dei soldi in contatti che si trovano nel portafoglio corrisponde a " << wallet << " euro\n";
}


void User::getInvestment(Investment new_invest) {      // method that creates you an investment
	srand(time(NULL));
	double earning{ 0 };
    char level_risk {' '};
	if (bank_account < new_invest.getAmount()) {
			cout << "Non si ha abbastanza soldi\n";
			return;
	}
	bank_account -= new_invest.getAmount();
	cout << "Viene prelevato dalla banca " << new_invest.getAmount() << " euro per fare l'investimento\n";

	if (new_invest.getRisk() <= 3)
		level_risk = '-'; // Low risk with little revenue
	else if (new_invest.getRisk() > 3 && new_invest.getRisk() <= 7)
		level_risk = '='; // Medium risk with medium revenue
	else if (new_invest.getRisk() > 7)
		level_risk = '+'; // High risk with big revenue

	
	for (int i{ 0 };i < new_invest.getDuration(); i++){
		if (debt > 0) {
			if (i==0) {
				if (bank_account >= debt) {
					bank_account -= debt;
					debt = 0;
				}
				else {
					debt -= bank_account;
					bank_account = 0;
				}
			}
			else {
				if (earning >= debt) {
					earning -= debt;
					debt = 0;
				}
				else {
					debt -= earning;
					earning = 0;
				}
			}
		}
		else {
		if (level_risk == '-') {
			earning += static_cast<double>(rand() % 9900 + 100);
			debt += static_cast<double>(rand() % 2000 + 50);
		}
		else if (level_risk == '=') {
			earning += static_cast<double>(rand() % 99000 + 500);
			debt += static_cast<double>(rand() % 20000 + 225);
		}
		else if (level_risk == '+') {
			earning += static_cast<double>(rand() % 999000 + 1000);
			debt += static_cast<double>(rand() % 750000 + 25000);
		}
	}
		increaseMonths(new_invest.getDuration());
	}
	earning -= debt;
	debt = 0;
	bank_account += earning;
	new_invest.~Investment();
}

void User::increaseMonths(int months) {               // method that make pass time
	for (int i{ 0 }; i < months; i++) {
		wallet += 100;
	}
}