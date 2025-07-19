#pragma warning (disable: 4996)
using namespace std;
#include "Controller.h"

void addMenu(Hospital& h)
{
    int addChoice;
    do {
        cout << "\n--- Add Menu ---\n";
        cout << "1. Add Department (using oparator)\n";
        cout << "2. Add Doctor (using oparator)\n";
        cout << "3. Add Nurse (using oparator)\n";
        cout << "4. Add Patient (using oparator)\n";
        cout << "5. Add Researcher\n";
        cout << "6. Add Research Institute\n";
        cout << "7. Add Visit\n";
        cout << "8. Add Article to Researcher\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> addChoice;

        switch (addChoice) {
        case 1: // Add Department
        {
            Department* newDepartment = readDepartment();
            h += *newDepartment;
            delete newDepartment;
            break;
        }
        case 2: // Add Doctor
        {
            Doctor* newDoctor = readDoctor();
            h += *newDoctor;//using oparator
            delete newDoctor;
            break;
        }
        case 3: // Add Nurse
        {
            Nurse* newNurse = readNurse();
            h += *newNurse;//using oparator
            delete newNurse;
            break;
        }
        case 4: // Add Patient
        {
            Patient* newPatiant = readPatiant();
            h.addPatiant(*newPatiant);
            delete newPatiant;
            break;
        }
        case 5: // Add Researcher
        {
            Researcher* newResearcher = readResearcher();
            h.addResearcher(*newResearcher);
            delete newResearcher;
            break;
        }
        case 6: // Add Research Institute
        {
            initResearchInstitute(h);
            break;
        }
        case 7: // Add Visit
        {
           /* Visit* newVisit = readVisit(h);
            delete newVisit;*/
            break;
        }
        case 8: // Add Article to Researcher
        {
            readArticle(h);
            break;
        }
        case 0:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (addChoice != 0);
}

void printMenu(Hospital& h)
{
    int printChoice;
    do {
        cout << "\n--- Print Options ---\n";
        cout << "1. Print Employees\n";
        cout << "2. Print Nurses\n";
        cout << "3. Print Doctors\n";
        cout << "4. Print Departments\n";
        cout << "5. Print Patients\n";
        cout << "6. Print Researchers\n";
        cout << "7. Print Full Hospital Details\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> printChoice;

        switch (printChoice) {
        case 1:
            h.printEmployees();
            break;
        case 2:
            h.printNurses();
            break;
        case 3:
            h.printDoctors();
            break;
        case 4:
            h.printDepartment();
            break;
        case 5:
            h.printPatiants();
            break;
        case 6:
            h.printResearchers();
            break;
        case 7:
            h.printHospital();
            break;
        case 0:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (printChoice != 0);
}

void searchMenu(Hospital& h)
{
    int searchChoice;
    do {
        cout << "\n--- Search Options ---\n";
        cout << "1. Search Doctor\n";
        cout << "2. Search Nurse\n";
        cout << "3. Search Patient\n";
        cout << "4. Search Researcher\n";
        cout << "5. Search Department\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> searchChoice;

        char name[50];

        switch (searchChoice) {
        case 1:
            cout << "Enter Doctor's Name: ";
            cin.ignore();
            cin.getline(name, 50);
            if (Doctor* doctor = h.getDoctorByName(name))
                doctor->print();
            else
                cout << "Doctor not found.\n";
            break;

        case 2:
            cout << "Enter Nurse's Name: ";
            cin.ignore();
            cin.getline(name, 50);
            if (Nurse* nurse = h.getNurseByName(name))
                nurse->print();
            else
                cout << "Nurse not found.\n";
            break;

        case 3:
            cout << "Enter Patient's Name: ";
            cin.ignore();
            cin.getline(name, 50);
            if (Patient* patiant = h.getPatiantByName(name))
                patiant->print();
            else
                cout << "Patient not found.\n";
            break;

        case 4:
            cout << "Enter Researcher's Name: ";
            cin.ignore();
            cin.getline(name, 50);
            if (Researcher* researcher = h.getResearcherByName(name))
                researcher->print();
            else
                cout << "Researcher not found.\n";
            break;

        case 5:
            cout << "Enter Department's Name: ";
            cin.ignore();
            cin.getline(name, 50);
            if (Department* department = h.getDepartmentByName(name))
                department->print();
            else
                cout << "Department not found.\n";
            break;

        case 0:
            cout << "Returning to main menu...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (searchChoice != 0);
}

int menu()
{
    char name[100];
    cout << "Enter the name of the hospital:";
    cin >> name;
    Hospital h(name);
    creatingDataForTesting(h);
    cout << "\n--- Welcome ---\n";
    int choice;
    do {
        cout << "\n--- Hospital Management Menu ---\n";
        cout << "1. View Hospital Details\n";
        cout << "2. Add menu\n";
        cout << "3. Print menu\n";
        cout << "4. Search menu\n"; 
        cout << "5. Add Data For Testing\n";
        cout << "6. Compare Researchers (using oparator)\n";
        cout << "0. Exit\n";
        cout << "________________________________\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            h.printHospital();
            break;

        case 2:
            addMenu(h);
            break;

        case 3:
            printMenu(h);
            break;

        case 4:
            searchMenu(h);
            break;

        case 5:
            creatingDataForTesting(h);
            cout << "\nTest data has been successfully added! Returning to main menu...\n";
            break;
        case 6:
            compareResearchers(h);
            break;

        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0); 

    return 0;
}

ResearchInstitute* readResearchInstitute()
{
    char name[20];
    cout << "Enter name: ";
    cin >> name;

    ResearchInstitute* newResearchInstitute = new ResearchInstitute(name);

    cout << "The Researcher: " << endl;
    newResearchInstitute->print();
    cout << "added." << endl;

    return newResearchInstitute;
}

void initResearchInstitute(Hospital& h) 
{
    string instituteName;
    cout << "Enter Research Institute name: ";
    cin >> instituteName;

    h.setResearchInstitute(instituteName);
    cout << "Research Institute '" << instituteName << "' created successfully." << endl;
}

Visit* readVisit(Hospital& h)
{
    int answer;
    Patient* p = nullptr;

    cout << "First visit of the patient? \n 1.Yes  2.No : ";
    cin >> answer;

    if (answer == 1)
    {
        p = readPatiant();

        if (!h.addPatiant(*p))

            p = h.getPatiantByName(p->getName());
    }
    else
    {
        char patientName[100];
        cout << "Enter the patient name: ";
        cin >> patientName;

        p = h.getPatiantByName(patientName);
        if (!p)
        {
            cout << "Error: Patient not found!" << endl;
            return nullptr;
        }
        cout << "Patient found: " << p->getName() << endl;
        p->print();
    }

    char doctorInCharge[100], departmentName[100],
        reasonForVisit[100], date[11];

    cout << "Doctor In Charge: ";
    cin >> doctorInCharge;

    Doctor* theDoctor = h.getDoctorByName(doctorInCharge);
    if (!theDoctor) {
        cout << "Error: Doctor not found!" << endl;
        return nullptr;
    }

    cout << "Department: ";
    cin >> departmentName;

    Department* theDepartment = h.getDepartmentByName(departmentName);
    if (!theDepartment) {
        cout << "Error: Department not found!" << endl;
        return nullptr;
    }

    cout << "Date: ";
    cin >> date;

    cout << "Reason for visit: ";
    cin >> reasonForVisit;

    Visit* newVisit = new Visit(date, reasonForVisit, *theDepartment, *theDoctor);
    p->addVisit(*newVisit);

    cout << "The Visit: " << endl;
    newVisit->print();
    cout << "Visit added successfully." << endl;

    return newVisit;
}

Researcher* readResearcher() {
    string name;
    cout << "Enter name: ";
    cin >> name;

    Researcher* newResearcher = new Researcher(name);
    cout << "The Researcher: " << endl;
    newResearcher->print();
    cout << "added." << endl;
    return newResearcher;
}

void readArticle(Hospital& h) {
    string researcherName;
    cout << "Enter Researcher name: ";
    cin >> researcherName;

    Researcher* r = h.getResearcherByName(researcherName);
    if (!r) {
        cout << "Error: Researcher '" << researcherName << "' not found!" << endl;
        return;
    }

    string articleTitle, publicationDate;
    cout << "Enter Article Title: ";
    cin >> articleTitle;
    cout << "Enter Publication Date: ";
    cin >> publicationDate;

    Article* newArticle = new Article(publicationDate, articleTitle);
    r->addArticle(*newArticle);

    cout << "Article '" << articleTitle << "' added to Researcher '" << r->getName() << "'." << endl;
}


Department* readDepartment()
{
    char departmentName[50];
    cout << "Enter name of the depatment: ";
    cin >> departmentName;

    Department* newDepartment = new Department(departmentName);

    cout << "The department: " << endl;
    newDepartment->print();
    cout << "added." << endl;

    return newDepartment;
}

Nurse* readNurse()
{
    char name[20];
    int seniority;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter number of years of seniority: ";
    cin >> seniority;

    Nurse* newNurse = new Nurse(name, seniority);

    cout << "The nurse: " << endl;
    newNurse->print();
    cout << "added." << endl;

    return newNurse;
}

Patient* readPatiant()
{
    char name[20];
    int id;
    int birthYear;
    int genderInput;

    cout << "Enter patiant name: ";
    cin >> name;

    cout << "Enter ID of the Patiant: ";
    cin >> id;

    cout << "Enter birthYear of the Patiant: ";
    cin >> birthYear;

    cout << "Enter Patiant's gender:\n 1. Male\n 2. Female\n ";
    cin >> genderInput;

    // Convert input to eGender
    Patient::eGender gender = (genderInput == 1) ? Patient::eGender::Male : Patient::eGender::Female;

    Patient* newPatiant = new Patient(name, id, birthYear, gender);

    cout << "The patiant: " << endl;
    newPatiant->print();
    cout << "added." << endl;

    return newPatiant;
}

Doctor* readDoctor()
{

    char name[20];
    char specialty[20];
    char department[20];

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter specialty: ";
    cin >> specialty;
    cout << "Enter department: ";
    cin >> department;

    Doctor* newDoctor = new Doctor(name, specialty, department);

    cout << "The doctor: " << endl;
    newDoctor->print();
    cout << "added" << endl;

    return newDoctor;
}

void creatingDataForTesting(Hospital& h)
{
    ///////////////////// Creating Departments ///////////////////////////
    cout << "\n__________ Creating Departments __________" << endl;
    Department cardiology("Cardiology");
    h.addDepartment(cardiology);
    Department neurology("Neurology");
    h += neurology; // Using operator overloading

    ///////////////////// Creating Doctors ///////////////////////////
    cout << "\n__________ Creating Doctors __________" << endl;
    Doctor doctor1("Dr. John Smith", "Cardiologist", "Cardiology");
    h.addDoctor(doctor1);
    Doctor doctor2("Dr. Emily Carter", "Neurologist", "Neurology");
    h += doctor2;

    ///////////////////// Creating Nurses ///////////////////////////
    cout << "\n__________ Creating Nurses __________" << endl;
    Nurse nurse1("Sarah Johnson", 12);
    h.addNurse(nurse1);
    Nurse nurse2("Michael Brown", 8);
    h += nurse2;

    ///////////////////// Creating Patients ///////////////////////////
    cout << "\n__________ Creating Patients __________" << endl;
    Patient patient1("James Anderson", 1000, 1980, Patient::eGender::Male);
    Visit visit1("2024-02-15", "Routine heart check-up", cardiology, doctor1);
    patient1.addVisit(visit1);
    h.addPatiant(patient1);

    Patient patient2("Sophia Martinez", 1001, 1995, Patient::eGender::Female);
    Visit visit2("2024-02-10", "Migraine consultation", neurology, doctor2);
    patient2.addVisit(visit2);
    h += patient2;

    ///////////////////// Creating Researchers ///////////////////////////
    cout << "\n__________ Creating Researchers __________" << endl;
    Researcher researcher1("Dr. Robert Williams");
    Researcher researcher2("Dr. Anna Thompson");

    // Adding articles to researchers
    Article article1("2024-01-05", "AI in Medicine");
    Article article2("2023-11-20", "Brainwave Research");
    Article article3("2023-11-12", "Neuroscience Today");

    researcher1.addArticle(article1);
    researcher2.addArticle(article2);
    researcher2.addArticle(article3);

    h.addResearcher(researcher1);
    h.addResearcher(researcher2);

    ///////////////////// Creating Research Institute ///////////////////////////
   cout << "\n__________ Creating Research Institute __________" << endl;
    ResearchInstitute institute("National Health Research Center");
    institute.addResearcher(researcher1);
    institute.addResearcher(researcher2);
    return;
}

void compareResearchers(Hospital& h) 
{
    Researcher* researcher1 = h.getResearcherByName("Dr. Robert Williams");
    Researcher* researcher2 = h.getResearcherByName("Dr. Anna Thompson");

    if (!researcher1 || !researcher2) {
        cout << "Error: One or both researchers not found in the hospital database.\n";
        return;
    }

    *researcher1 < *researcher2;
}

