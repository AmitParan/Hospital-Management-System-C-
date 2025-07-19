#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#include "Employee.h"
#include "Doctor.h"

class Doctor;

class Department
{
private:
    string departmentName;
    vector<Doctor*> allDoctors;

public:
    Department(const  string& name);

    const string& getName() const { return departmentName; }
    bool addDoctor(const Doctor& doctor);
    bool doctorExists(const Doctor& doctor) const;
    void print() const;
    void printDoctors() const;

};

#endif
