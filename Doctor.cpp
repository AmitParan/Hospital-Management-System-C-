#include "Doctor.h"

// Constructor
Doctor::Doctor(const string& name, const string& specialty, const string& department)
    : Person(name), Employee(name), specialty(specialty), theDepartment(department) {}


// Copy Constructor
Doctor::Doctor(const Doctor& other)
    : Person(other), Employee(other), specialty(other.specialty), theDepartment(other.theDepartment) {}


// Destructor
Doctor::~Doctor() {}

void Doctor::setSpecialty(const string& s)
{
    specialty = s;
}

void Doctor::setDepartment(const string& department)
{
    theDepartment = department;
}

ostream& operator<<(ostream& os, const Doctor& d)
{
    os << (Person&)d  << ", Specialty: " << d.getSpecialty() << ", Department: " << d.getDepartment();
    return os;
}

void Doctor::print() const
{
    cout << "Name: " << getName() << "\nID: " << employeeId << 
        ", Specialty: " << specialty <<
        ", Department:"<< theDepartment << "\n"<< endl;
}


