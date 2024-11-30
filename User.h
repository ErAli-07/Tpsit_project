#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include <string>

using namespace std;

class Investment;

class User{
private:
	static int active_users;
    string name;
	double bank_account;
    double wallet;
	double debt;
public:
	User(string name, double bank, double wallet);
	~User();
	void depositMoney(double depositedMoney);
	void withdrawMoney(double withdrawMoney);
    void getInvestment(Investment new_invest);
	void increaseMonths(int months);
    void bankState();
	void walletState();
};
#endif