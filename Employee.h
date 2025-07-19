#pragma warning(disable : 4996)
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Person.h"

class Employee : virtual public Person
{
protected:
    static int idGenerator;
    int employeeId;

public:
    // Constructor
    Employee(const string& name);
    // Copy Constructor
    Employee(const Employee& other);
    // Destructor
    virtual ~Employee() = default;

    Employee& operator=(const Employee& other);

    int getId() const { return employeeId; };
    static int getTotalEmployees() { return idGenerator; }

    void setId(int newId) = delete;

    virtual void print() const = 0;
    virtual Employee* clone() const = 0;

};
#endif
