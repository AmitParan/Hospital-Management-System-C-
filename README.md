# Hospital Management System – C++

A modular, object-oriented Hospital Management System developed in C++.  
The system simulates real-world hospital operations, including patient management, staff administration, and research institute handling.

## 📌 Project Overview

This project implements a console-based management system for a hospital.  
Core functionalities include:
- Managing **Departments**, **Doctors**, **Nurses**, **Patients**, and **Visits**.
- Integration of a **Research Institute**, with **Researchers** and **Articles**.
- A modular design using Object-Oriented Programming (OOP) principles.

The program is fully menu-driven and enables user interaction via console.

---

## 🚀 Features

### Hospital Management:
- Add/search/manage:
  - Departments
  - Doctors (with specialty and seniority)
  - Nurses
  - Patients
  - Visits
- Search by name or ID.
- Display hospital structure and staff.

### Research Institute Module:
- Add and manage:
  - Researchers
  - Research Articles
  - Research Institutes

- Compare researchers and manage research entities linked to the hospital.

### Additional Functionalities:
- Input validation and error handling.
- Menu-driven system via `Controller.h`.

---

## 📂 Project Structure

| File                  | Description                           |
|-----------------------|---------------------------------------|
| `main.cpp`            | Main entry point (launches menu).     |
| `Controller.h`        | Menu functions and user interactions. |
| `hospital.h`          | Hospital class managing all entities. |
| `Department.h`        | Department class.                     |
| `Doctor.h / Nurse.h`  | Staff member classes.                 |
| `Patiant.h`           | Patient class.                        |
| `Visit.h`             | Visit tracking.                       |
| `Researcher.h`        | Researcher entity.                    |
| `ResearchInstitute.h` | Research Institute management.        |
| `Article.h`           | Research articles.                    |

---

## 🛠️ Technologies Used

- **C++ (Object-Oriented Programming)**
- **Console-based User Interface**

---

## ⚙️ How to Compile and Run

```bash
g++ main.cpp -o hospital
./hospital
