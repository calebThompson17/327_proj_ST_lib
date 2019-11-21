//
/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */
#include <iostream>
#include <memory>
#include <vector>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

using namespace std;

//create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
//objects using unique pointers.  Since we are using c++11 returning this vector by value is fine since the 
//compiler will move the vector on return rather than recreate it (this means there is no copy penalty)
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	
	//create a vector to hold SmallTalk unique pointers
	vector<unique_ptr<Smalltalk>> people;

		//add brits to vector
	for (int i = 1; i <= numBrit; ++i) {
		people.push_back(unique_ptr<Smalltalk>(new Smalltalk_Brit(i)));
	}

		//add americans  to vector
	for (int i = 1; i <= numAmerican; ++i) {
		people.push_back(unique_ptr<Smalltalk>(new Smalltalk_American(i)));
	}

		//add american donut enthusiest  to vector
	for (int i = 1; i <= numbAmericanDonutEnthusiest; ++i) {
		people.push_back(unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(i)));
	}

		//create some watches (as long as number watches <= numb people)
		//then give the watches away to first NUM_WATCHES people in the vector
		// when you are finished using the vector you return
		//from this function(see Smalltalk header for hints)
	if (numWatches > 0) {
		int currentWatch = 0;
		int lastWatch = 0;
		unique_ptr<Watch> && newWatch = unique_ptr<Watch>(new Watch());
		if (numWatches > people.size())
			numWatches = people.size();
		bool firstLoop = true;
		for (auto &person : people) {
			if (currentWatch == numWatches)
				break;
			if (currentWatch > lastWatch) {
				newWatch = unique_ptr<Watch>(new Watch());
				++lastWatch;
			}
			if (person->giveWatch((newWatch)))
				++currentWatch;
		}
	}

		//return your vector
	return people;
}
