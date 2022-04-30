#include "Student.h"
#ifndef StudentImpleH

/*  
    int studentID;
    std::string studentName;
    std::string studentCU;
    std::string studentMajor;
    double studentGPA;
    int facID;
*/

//Constructor
Student::Student()
{
    studentID = 0;
    studentName = "";
    studentCU = 0;
    studentMajor = "";
    studentGPA = 0.0;
    facID = 0;
}

//If only provide id, the rest of the info is empty
Student::Student(int id)
{
    studentID = id;
    studentName = "";
    studentCU = 0;
    studentMajor = "";
    studentGPA = 0.0;
    facID = 0;  
}

//Standard info
Student::Student(int id, std::string name, int cu, std::string major, double gpa, int advisor)
{
    studentID = id;
    studentName = name;
    studentCU = cu;
    studentMajor = major;
    studentGPA = gpa;
    facID = advisor;  
}

//Getters

int Student::GetstudentID()
{
    return studentID;
}
std::string Student::GetstudentName()
{
    return studentName;
}
int Student::GetstudentCU()
{
    return studentCU;
}
std::string Student::GetstudentMajor()
{
    return studentMajor;
}
double Student::Getgpa()
{
    return studentGPA;
}
int Student::GetfacAdv()
{
    return facID;
}

//Function for menu/main.cpp

// Change thi student facID to the required facID
void Student::changeFaculty(int facnewID)
{
    facID = facnewID;
}

// Print out student's info
void Student::print()
{
    std::cout << "Name: " << studentName << " |ID: " << studentID
    << " | Total Credit Unit: " << studentCU << " | Major: "
    << studentMajor << " | GPA: " << studentGPA << " | Advisor:"
    << facID << std::endl;
}

//Overloaded operators

// Return true when curr student id == another student id
inline bool Student::operator==(const Student& anotherstudent)
{
    return(this->studentID == anotherstudent.studentID);
}

// Return true when curr student < another student
inline bool Student::operator<(const Student& anotherstudent)
{
    return(this->studentID < anotherstudent.studentID);
}

// Return true when curr student > another student
inline bool Student::operator>(const Student& anotherstudent)
{
    return(this->studentID > anotherstudent.studentID);
}

// Return true when curr student != another student
inline bool Student::operator!=(const Student& anotherstudent)
{
    return(this->studentID != anotherstudent.studentID);
}


#endif