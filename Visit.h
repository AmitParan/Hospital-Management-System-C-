#pragma warning (disable: 4996)
#ifndef __VISIT_H
#define __VISIT_H

#include <iostream>
#include <cstring>
#include "Doctor.h"
#include "Department.h"
using namespace std;

class Doctor;
class Department;
//class Nurse;


class Visit
{
protected:
	string arrivalDate;
	string reasonForVisit;
	static int dateGenerator;

	Doctor& responsibleStaffMember;
	Department& visitDepartment;


public:
	// Constructor
	Visit(const string& arrivalDate, const string& reasonForVisit, Department& visitDepartment, Doctor& responsibleStaffMember);
	// Copy Constructor
	Visit(const Visit& other);
	// Destructor
	~Visit();

	///////////set///////
	void setArrivalDate(const string& arrivalDate);
    bool setReasonForVisit(const string& reasonForVisit);
    //bool setVisitDepartment(const char* visitDepartment);

	///////////get///////
	const string& getReasonForVisit() const {return reasonForVisit;}

	///////////print///////
	const void print() const;

};

#endif

