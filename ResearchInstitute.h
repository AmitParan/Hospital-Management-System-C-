#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#include "Researcher.h"

#ifndef __RESEARCHINSTITUTE_H
#define __RESEARCHINSTITUTE_H

class Researcher;

class ResearchInstitute 
{
private:
	string researchInstituteName;
    vector<Researcher*> allResearchers;
    //int currentResearchers, maxResearchers;

public:
	
	ResearchInstitute(const string& researchInstituteName);
	~ResearchInstitute();	

	bool setResearchInstituteName(const string& researchInstituteName);
	const string& getResearchInstituteName() const {return researchInstituteName;}
	void print() const;
	bool researcherExist(const Researcher& r) const;
	bool addResearcher(Researcher& newResearcher);
	void printResearchers() const;
};

#endif