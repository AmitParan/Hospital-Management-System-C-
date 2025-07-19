#pragma warning (disable: 4996)
#ifndef __NURSE_H
#define __NURSE_H

#include "Employee.h"

class Nurse : public Employee
{
private:
	int seniority;

public:
	// Constructor
	Nurse(const string& name, int seniority);
	// Copy Constructor
	Nurse(const Nurse& other);
	// Destructor
	~Nurse();


	void setSeniority(int seniority);
	const int getSeniority() const { return seniority; } 
	void print() const;
	friend ostream& operator<<(ostream& os, const Nurse& n);
	virtual Employee* clone() const override { return new Nurse(*this); }

};
#endif
