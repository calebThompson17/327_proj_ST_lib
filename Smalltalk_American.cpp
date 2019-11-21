/*
 * Smalltalk_American.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Caleb Thompson
 */

#include "includes/constants.h"
#include "includes/Smalltalk_American.h"

//create with appropriate phrases
//use base class call to set Nationality (See constants for Nationality strings)
Smalltalk_American::Smalltalk_American(int iPerson /*=1*/) : Smalltalk_American(AMERICAN, iPerson) {}

Smalltalk_American::Smalltalk_American(std::string myNationality,int iPerson /*=1*/) : Smalltalk(myNationality, iPerson) {
	populatePhrases();
}

Smalltalk_American::~Smalltalk_American(void) {}

void Smalltalk_American::populatePhrases(){
	mySmallTalk.push_back(AMERICAN_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_PHRASE_5);
}


