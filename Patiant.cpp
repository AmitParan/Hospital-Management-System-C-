#include "Patiant.h"

// Constructor
Patient::Patient(const char* name, int id, int birthYear, eGender gender)
	:Person(name), id(0), birthYear(birthYear), gender(gender)
{
	setId(id);
	setBirthYear(birthYear);
	setGender(gender);

}
// Copy Constructor
Patient::Patient(const Patient& other)
	:Person(other), id(0), birthYear(0), gender(gender)
{
	setId(other.id);
	setBirthYear(other.birthYear);
}

Patient::~Patient()
{}

void Patient::setId(int Id)
{
	this->id = Id;
}

bool Patient::setBirthYear(int birthYear)
{
	if (birthYear < 1900 || birthYear > 2025)
	{
		return false;
	}
	else
	{
		this->birthYear = birthYear;
		return true;
	}
}

void Patient::addVisit(Visit& visit) 
{
	Visit* newVisit = new Visit(visit);
	allVisits.push_back(newVisit); 

	cout << "Visit added successfully! Total visits: " << allVisits.size() << endl;
}

void Patient::setGender(eGender gender)
{
	this->gender = gender;
}

void Patient::print() const
{
	cout << "Name: " << getName() 
		<< "\nID:" << id << "\nBirthYear: " << getBirthYear()
		<< " ,Gender: " << (gender == eGender::Male ? "Male" : "Female") << endl;
	printVisits();
}

void Patient::printVisits() const
{
	cout << "Total visits: " << allVisits.size() << endl;

	for (const Visit* visit : allVisits) {
		visit->print();
	}

}

ostream& operator<<(ostream& os, const Patient& p)
{
	os << (Person&)p 
		<< ", \nID: " << p.getId() << ", Birth Year: " << p.getBirthYear()
		<< ", Gender: " << (p.getGender() == Patient::eGender::Male ? "Male" : "Female");
	return os;
}
