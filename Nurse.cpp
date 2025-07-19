#include "Nurse.h"

// Constructor
Nurse::Nurse(const string& name, int seniority)
	: Person(name), Employee(name), seniority(seniority) 
{
}

//copy Constructor
Nurse::Nurse(const Nurse& other)
	:Employee(other), seniority(0)
{
	setSeniority(other.seniority);
}

// Destructor
Nurse::~Nurse()
{
	seniority = 0;
}

void Nurse::setSeniority(int seniority)
{
	this->seniority = seniority;
}

void Nurse::print() const
{
	cout << "Name:" << getName() << "\nID:" << getId() << " ,Years of experience:" << getSeniority() << endl;
}

ostream& operator<<(ostream& os, const Nurse& n)
{
	os << (Person&)n << ", Years of Experience: " << n.getSeniority();
	return os;
}


