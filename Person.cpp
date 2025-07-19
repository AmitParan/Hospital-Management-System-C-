#include "Person.h"

// Constructor
Person::Person(const string& name)
	: name(name)  
{
}

// Copy Constructor
Person::Person(const Person& other)
	:name(other.name){}

// Destructor
Person::~Person() 
{
}

//set
void Person::setName(const string& n)
{
	name = n;
}

ostream& operator<<(ostream& os, const Person& p)
{
	os << "Name: " << p.name ;

	return os;
}



