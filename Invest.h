#ifndef _INVEST_H_
#define _INVEST_H_
#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Investment {
private:
    int amount;
	int duration; //in months
	int risk;     //1-10 scale
public:
    Investment(int amount, int duration, int risk);
	~Investment();
	int getAmount();
	int getDuration();
	int getRisk();
};

#endif