#pragma warning (disable: 4996)
#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <cstring>
using namespace std;


class Person
{
protected:
	string name;

public:
	Person(const string& name);

	// Copy Constructor
	Person(const Person& other);
	
	//Default Constructor
	Person(): name("") {}
	
	// Destructor
	virtual ~Person();

	
	// Set
	void setName(const string& name);

	//Get
	inline const string& getName() const;

	friend ostream& operator<<(ostream& os, const Person& p);

};

const string& Person::getName() const
{
	return name;
}
#endif
