#pragma warning (disable: 4996)
#ifndef __PATIANT_H
#define __PATIANT_H

#include "Person.h"
#include "Visit.h"
#include <vector>

class Visit;


class Patient : public Person
{
public:
	enum class eGender { Male, Female };

private:
	int id;
	int birthYear;
	eGender gender;
	vector<Visit*> allVisits;

public:
	Patient(const char* name, int id, int birthYear, eGender gender);
	Patient(const Patient& other);
	~Patient();

	void setId(int Id);
	bool setBirthYear(int birthYear);
	void setGender(eGender gender);

	void addVisit(Visit& visit);

	int getId() const {return id;}
	int getBirthYear() const {return birthYear;}
	eGender getGender() const {return gender;}
	void printVisits() const;

	void print() const;
	
};


#endif



