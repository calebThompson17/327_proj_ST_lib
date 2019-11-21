/*
 * ST_American_DonutEnthusiest.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Caleb Thompson
 */

#include "includes/ST_American_DonutEnthusiest.h"
#include "includes/constants.h"

ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int i) {
	Smalltalk_American(AMERICAN_DE, i);
	populatePhrases();
}

ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void) {}

//base class populatePhrases() will be called first as part of its construction
//before this class calls populate phrases as part of its construction
//the end result is mySmallTalk will contain first the base class phrases and
//then this classes phrases
void ST_American_DonutEnthusiest::populatePhrases(){
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}
