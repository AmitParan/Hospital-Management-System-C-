#include "ResearchInstitute.h"

ResearchInstitute::ResearchInstitute(const string& researchInstituteName)
	:researchInstituteName(researchInstituteName){ }


ResearchInstitute::~ResearchInstitute(){}

bool ResearchInstitute::setResearchInstituteName(const string& researchInstituteName)
{
	this->researchInstituteName = researchInstituteName;
	return true;
}

bool ResearchInstitute::researcherExist(const Researcher& r) const
{
	for (const auto& researcher : allResearchers)
	{
		if (researcher->getName() == r.getName())
			return true;
	}
	return false;
}

bool ResearchInstitute::addResearcher(Researcher& newResearcher)
{
	if (researcherExist(newResearcher))
	{
		cout << "Researcher already exists" << endl;
		return false;
	}

	allResearchers.push_back(&newResearcher);
	return true;
}


void ResearchInstitute::printResearchers() const
{
	for (const auto& researcher : allResearchers)
		researcher->print();
}

void ResearchInstitute::print() const
{
	cout << "Research institute name:" << researchInstituteName <<"\nResearchers:"<< endl;
	printResearchers();
}
