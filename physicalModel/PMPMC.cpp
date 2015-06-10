/*
 * PMPMC.cpp
 *
 *  Created on: May 27, 2014
 *      Author: luis
 */

#include "PMPMC.h"

PMPMC::~PMPMC() {

}

PMPMC::PMPMC(const MatId id, const string name)
: PMPredefined(id, name){
}

void
PMPMC::printInfo() const {
	cout << "--- PMPMC info ---" << endl;
	PMPredefined::printInfo();
	cout << "Perfect Magnetic Conductor" << endl;
}
