#include <iostream>
#include <cstring>
using namespace std;

#include "Department.h"

// Constructor
Department::Department(const string& name) : departmentName(name) {}


bool Department::doctorExists(const Doctor& d) const
{
    for (Doctor* doctor : allDoctors)  
    {
        if (doctor->getId() == d.getId())
            return true;
    }
    return false;
}

bool Department::addDoctor(const Doctor& doctor)
{

    if (this->doctorExists(doctor))
    {
        cout << "Doctor already exists in this department." << endl;
        return false;
    }

    allDoctors.push_back((Doctor*)&doctor);

    return true;
}

void Department::print() const
{
    cout << "Department: " << departmentName <<endl;
    printDoctors();

}

void Department::printDoctors() const
{
    cout << "Total doctors in department: " << allDoctors.size() << endl;

    cout << "The Department doctors:\n" << endl;
    for (const auto& doctor : allDoctors){
        doctor->print();
    }
}
