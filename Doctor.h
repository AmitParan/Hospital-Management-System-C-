#pragma warning (disable: 4996)
#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "Employee.h"
#include "Department.h"

class Department;

class Doctor :  public Employee
{
private:
    string specialty;
    string theDepartment;

public:
    // Constructor
    Doctor(const string& name, const string& specialty, const string& department);

    // Copy Constructor
    Doctor(const Doctor& other);
    // Destructor
    ~Doctor();

    void setSpecialty(const string& s);
    void setDepartment(const string& department);

    const string& getSpecialty() const { return specialty; }
    const string& getDepartment() const { return theDepartment; }
    friend ostream& operator<<(ostream& os, const Doctor& d);

    void print() const override;
    virtual Employee* clone() const override { return new Doctor(*this); }
};

#endif
