/*
 * PMPEC.cpp
 *
 *  Created on: May 27, 2014
 *      Author: luis
 */

#include "PMPEC.h"


// =============== PMPEC ======================================================
PMPEC::PMPEC(const unsigned int id, const string name)
: PMPredefined(id, name) {

}

PMPEC::~PMPEC() {

}

bool
PMPEC::isPEC() const {
	return true;
}

void
PMPEC::printInfo() const {
	cout << "--- PMPEC info ---" << endl;
	PMPredefined::printInfo();
	cout << "Perfect Electric Conductor" << endl;
}

Condition::Type PMPEC::getConditionType() const {
   return Condition::pec;
}
