#include "Employee.h"

int Employee::idGenerator = 0;

// Constructor
Employee::Employee(const string& name) : Person(name), employeeId(++idGenerator)
{
    setName(name);  // ? Ensure name is set
}

// ? Copy Constructor (Copies ID and Name Correctly)
Employee::Employee(const Employee& other)
    : Person(other.name), employeeId(other.employeeId) {
}



Employee& Employee::operator=(const Employee& other) 
{
    if (this != &other)
    {
        Person::operator=(other);
        employeeId = other.employeeId;
    }
    return *this;
}




