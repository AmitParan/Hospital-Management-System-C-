#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#include "Hospital.h"

Hospital::Hospital(const string& name)
    :hospitalName(name)
{
    // Initialize hospital
    cout << "Creating hospital\n" << endl;

    researchInstitute = nullptr;
}

Hospital::~Hospital()
{
    for (Employee* emp : allEmployees)
    {
        delete emp; 
    }
    allEmployees.clear();


    delete researchInstitute;
}

////////////////Exist//////////////////

bool Hospital::departmentExist(const Department& d) const {
    for (const Department& dept : allDepartments) 
    {
        if (dept.getName() == d.getName()) 
        {
            return true;
        }
    }
    return false;
}

bool Hospital::nurseExist(const Nurse& n) const
{
    for (const Employee* emp : allEmployees)
    {
        const Nurse* nurse = dynamic_cast<const Nurse*>(emp);
        if (nurse && nurse->getId() == n.getId())
        {
            return true;
        }
    }
    return false;
}


bool Hospital::doctorExist(const Doctor& d) const
{
    for (const Employee* emp : allEmployees)
    {
        const Doctor* doctor = dynamic_cast<const Doctor*>(emp);
        if (doctor && doctor->getId() == d.getId()) 
        {
            return true;
        }
    }
    return false;
}


bool Hospital::patiantExist(const Patient& p) const
{
    for (const Patient& patiant : allPatiants)
    {
        if (patiant.getName() == p.getName())
        {
            return true;
        }
    }
    return false;
}

bool Hospital::researcherExist(const Researcher& r) const
{
    for (const Researcher& researcher : allResearchers)
    {
        if (researcher.getName() == r.getName())
        {
            return true;
        }
    }
    return false;
}

bool Hospital::researchInstituteExist() const {
    return researchInstitute != nullptr;
}


////////////////adder//////////////////
bool Hospital::addEmployee(const Employee& newEmployee)
{
    allEmployees.push_back(newEmployee.clone());
    return true;
}

bool Hospital::addDepartment(const Department& newDepartment)
{
    if (departmentExist(newDepartment)) 
    {
        cout << "Department already exists in this hospital." << endl;
        return false;
    }

    allDepartments.push_back(newDepartment);  
    return true;
}

bool Hospital::addDoctor(const Doctor& newDoctor)
{
    if (doctorExist(newDoctor))
    {
        cout << "Doctor already exists in this hospital." << endl;
        return false;
    }
    Doctor* doctorPtr = new Doctor(newDoctor);
    allEmployees.push_back(new Doctor(newDoctor));
    return true;
}

bool Hospital::addNurse(const Nurse& newNurse)
{
    if (nurseExist(newNurse))
    {
        cout << "Nurse already exists in this hospital." << endl;
        return false;
    }
    Nurse* nursePtr = new Nurse(newNurse);
    allEmployees.push_back(new Nurse(newNurse));  
    return true;
}

bool Hospital::addPatiant(const Patient& newPatiant)
{
    if (patiantExist(newPatiant))
    {
        cout << "Patiant already exists in this hospital." << endl;
        return false;
    }

    allPatiants.push_back(newPatiant);  
    return true;
}

bool Hospital::addResearcher(const Researcher& newResearcher)
{
    if (researcherExist(newResearcher))
    {
        cout << "Researcher already exists in this hospital." << endl;
        return false;
    }

    allResearchers.push_back(newResearcher);  
    return true;
}

void Hospital::addVisit(const Visit& newVisit)
{
    allVisits.push_back(newVisit);  
}

void Hospital::setResearchInstitute(const string& researchInstituteName) {
    if (researchInstitute)
    {
        cout << "Research Institute already exists. Updating name..." << endl;
        researchInstitute->setResearchInstituteName(researchInstituteName);
    }
    else
    {
        researchInstitute = new ResearchInstitute(researchInstituteName);
        cout << "Research Institute '" << researchInstituteName << "' created." << endl;
    }
}



///////////////////////////get////////////////////////////
Department* Hospital::getDepartmentByName(const string& name)
{
    for (Department& dept : allDepartments) {
        if (dept.getName() == name) { 
            return &dept;
        }
    }
    return nullptr;
}

Doctor* Hospital::getDoctorById(int id)
{
    for (Employee* emp : allEmployees)
    {
        Doctor* doctor = dynamic_cast<Doctor*>(emp);
        if (doctor && doctor->getId() == id)
        {
            return doctor;
        }
    }
    return nullptr;
}

Nurse* Hospital::getNurseById(int id)
{
    for (Employee* emp : allEmployees)
    {
        Nurse* nurse = dynamic_cast<Nurse*>(emp);
        if (nurse && nurse->getId() == id) 
        {
            return nurse;
        }
    }
    return nullptr;
}

Patient* Hospital::getPatiantByName(const string& name)
{
    for (Patient& patiant : allPatiants)
    {
        if (patiant.getName() == name)
        {
            return &patiant;
        }
    }
    return nullptr;
}

Researcher* Hospital::getResearcherByName(const string& name)
{
    for (Researcher& researcher : allResearchers)
    {
        if (researcher.getName() == name)
        {
            return &researcher;
        }
    }
    return nullptr;
}

ResearchInstitute* Hospital::getResearchInstitute() {
    return researchInstitute;
}

Doctor* Hospital::getDoctorByName(const string& name)
{
    for (Employee* emp : allEmployees)
    {
        Doctor* doctor = dynamic_cast<Doctor*>(emp);
        if (doctor && doctor->getName() == name)
        {
            return doctor;
        }
    }
    return nullptr;
}

Nurse* Hospital::getNurseByName(const string& name)
{
    for (Employee* emp : allEmployees)
    {
        Nurse* nurse = dynamic_cast<Nurse*>(emp);
        if (nurse && nurse->getName() == name)
        {
            return nurse;
        }
    }
    return nullptr;
}

////////////////print//////////////////
void Hospital::printDepartment() const
{
    for (const Department& dept : allDepartments)
    {
        dept.print();
    }
}

void Hospital::printDoctors() const
{
    cout << "Doctors in hospital:\n";
    for (const Employee* emp : allEmployees)
    {
        const Doctor* doctor = dynamic_cast<const Doctor*>(emp);
        if (doctor)
        {
            doctor->print();
        }
    }
}

void Hospital::printNurses() const
{
    cout << "Nurses in hospital:\n";
    for (const Employee* emp : allEmployees)
    {
        const Nurse* nurse = dynamic_cast<const Nurse*>(emp);
        if (nurse)
        {
            nurse->print();
        }
    }
}

void Hospital::printPatiants() const
{
    for (const Patient& patiant : allPatiants)
    {
        patiant.print();
    }
}

void Hospital::printResearchers() const
{
    for (const Researcher& researcher : allResearchers)
    {
        researcher.print();
    }
}

void Hospital::printEmployees() const
{
    for (const Employee* employee : allEmployees)
    {
        employee->print();
    }
}

void Hospital::printResearchInstitute() const
{
    if (!researchInstitute)
    {
        cout << "No research institute exists yet." << endl;
        return;
    }
    researchInstitute->print();
}

void Hospital::printHospital() const
{
    cout << "Hospital: " << hospitalName << endl;

    cout << "\nDepartments:" << endl;
    cout << "------------" << endl;
    printDepartment();

    cout << "\nDoctors:" << endl;
    cout << "--------" << endl;
    printDoctors();

    cout << "\nNurses:" << endl;
    cout << "-------" << endl;
    printNurses();

    cout << "\nPatiants:" << endl;
    cout << "-------" << endl;
    printPatiants();

    cout << "\nResearchers:" << endl;
    cout << "-------" << endl;
    printResearchers();
}







