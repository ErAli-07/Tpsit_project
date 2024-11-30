#include <iostream>
#include "Invest.h"

using namespace std;

Investment::Investment(int amount, int duration, int risk){   // Constructor - give a value to the members of the Investment
	this->amount=amount;
	this->duration=duration;
	this->risk=risk;
}

Investment::~Investment() {
	//Destructor - removes an investment
}

int Investment::getDuration(){
     return duration;
}

int Investment::getRisk(){
	return risk;
}

int Investment::getAmount(){
	return amount;
}
