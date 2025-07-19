#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
#include "Person.h"
#include "Employee.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patiant.h"
#include "Visit.h"
#include "Department.h"
#include "hospital.h"
#include "Researcher.h"
#include "Article.h"
#include "ResearchInstitute.h"

#ifndef __CONTROLLER_H
#define __CONTROLLER_H


int menu();
void addMenu(Hospital& h);
void printMenu(Hospital& h);
void searchMenu(Hospital& h);
void creatingDataForTesting(Hospital& h);

Department* readDepartment();
Nurse* readNurse();
Doctor* readDoctor();
Patient* readPatiant();
Visit* readVisit(Hospital& theHospital);

Researcher* readResearcher();
ResearchInstitute* readResearchInstitute();
void initResearchInstitute(Hospital& h);

void readArticle(Hospital& h);
void compareResearchers(Hospital& h);
#endif