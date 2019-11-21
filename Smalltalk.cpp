/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Caleb Thompson
 */

#include <string>
#include <ctype.h>
#include <vector>
#include <string>
#include <memory>

#include "includes/Smalltalk.h"
#include "includes/constants.h"
#include "includes/Watch.h"

using namespace std;

//derived class will set Nationality, iPerson.
//iPerson is just a counter used to distinguish between objects of the same type
Smalltalk::Smalltalk(string myNationality, int iPerson /*=1*/) : //use an initializer list here
		nationality(myNationality),
		iPerson(iPerson),
		mySmallTalk{},
		current_phrase{0},
		pWatch(nullptr)
{}

Smalltalk::~Smalltalk(void){}

//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
//with the last and then it starts over
//takes the form Nationality iPerson: phrase
//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
//AMERICAN 10:Why yes, I would like to supersize that
string Smalltalk::saySomething(){
	string returnString = nationality + " " + to_string(iPerson) + ":" + mySmallTalk[current_phrase];
	++current_phrase;
	if (current_phrase >= mySmallTalk.size())
		current_phrase = 0;
	return returnString;
}

//returns the time (if pWatch contains a watch ) in the form of THE_CURRENT_TIME_IS: (from the actual watch object itself) and then the time
//or I_DO_NOT_HAVE_A_WATCH string (if pWatch does not contain a watch)
string Smalltalk::getTime(){
	if (pWatch == 0) {
		return I_DO_NOT_HAVE_A_WATCH;
	}
	string returnString = THE_CURRENT_TIME_IS + pWatch->getTime();
	return returnString;

}

//if this object has a watch it is taken away, otherwise an empty unique_ptr is returned
// This transaction simulates giving away a watch
unique_ptr<Watch> Smalltalk::takeWatch(){
	unique_ptr<Watch> newWatch;
	if (pWatch == 0) {
		newWatch = 0;
	} else {
		newWatch = move(pWatch);
	}
	return newWatch;

}

//if already have a watch then return false and dont change pWatch pointer
//otherwise accept watch (return true) and set this->pWatch=pWatch (use std::move)
bool Smalltalk::giveWatch(unique_ptr<Watch> &pWatch){
	if (this->pWatch != 0) {
		return false;
	}
	this->pWatch = move(pWatch);
	return true;
}



