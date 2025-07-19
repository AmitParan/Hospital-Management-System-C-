#pragma warning (disable: 4996)
#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patiant.h"
#include "Visit.h"
#include "Researcher.h"
#include "ResearchInstitute.h"
#include <vector>

class Hospital
{
private:
    string hospitalName;
    ResearchInstitute* researchInstitute;



    vector<Department> allDepartments;
    vector<Patient> allPatiants;
    vector<Researcher> allResearchers;
    vector<Visit> allVisits;
    vector<Employee*> allEmployees;

public:
    // Constructor & Destructor
    Hospital(const string& name);
    Hospital(const Hospital& other) = delete;
    ~Hospital();
    void printHospital() const;
    const string& getHospitalName() const { return hospitalName; }

    //////// Department Class ////////
    bool departmentExist(const Department& department) const;
    bool addDepartment(const Department& newDepartment);
    Department* getDepartmentByName(const string& name);
    void printDepartment() const;


    //////// Doctor Class ////////
    bool doctorExist(const Doctor& d) const;
    bool addDoctor(const Doctor& newDoctor);
    Doctor* getDoctorById(int id);
    Doctor* getDoctorByName(const string& name);
    void printDoctors() const;


    //////// Nurse Class ////////
    bool nurseExist(const Nurse& n) const;
    bool addNurse(const Nurse& newNurse);
    Nurse* getNurseById(int id);
    Nurse* getNurseByName(const string& name);
    void printNurses() const;


    //////// Patiant Class ////////
    bool patiantExist(const Patient& p) const;
    bool addPatiant(const Patient& newPatiant);
    Patient* getPatiantByName(const string& name);
    void printPatiants() const;


    //////// Researcher Class ////////
    bool researcherExist(const Researcher& r) const;
    bool addResearcher(const Researcher& newResearcher);
    Researcher* getResearcherByName(const string& name);
    void printResearchers() const;


    //////// Research Institute Class ////////
    bool researchInstituteExist() const;
    void setResearchInstitute(const string& researchInstituteName);
    ResearchInstitute* getResearchInstitute();
    void printResearchInstitute() const;


    //////// Visit Class ////////
    void addVisit(const Visit& newVisit);


    //////// Employee Class ////////
    bool addEmployee(const Employee& newEmployee);
    void printEmployees() const;

    ////////operator////////
    friend void operator+=(Hospital& h, Department& d) { h.addDepartment(d); }
    friend void operator+=(Hospital& h, Doctor& d) { h.addDoctor(d); }
    friend void operator+=(Hospital& h, Nurse& n) { h.addNurse(n); }
    friend void operator+=(Hospital& h, Patient& p) { h.addPatiant(p); }

};
#endif

