/*
Menu
1. Add student. (Cin Name,Total CU, Major, Studentid, Gpa, Advisorid(Will create a new advisorid if it doesnt exist))
2. Add Faculty (Cin Name, Security Clearance, Dept, ID,No. of student, Studentid(will add more))
3. Print all of Students (Sorted by student id)
4. Print all of Students (Sorted by Faculty id)
5. Find & Display Student info (Using their studentid)
6. Find & Display Faculty member info (Using their Facultyid)
7. Given a student's id, print the name and info of their faculty advisor
8. Given a faculty id, print all the names and info of his/her advisees
9. Remove Student
10. Remove Faculty member
11. Change Student's Advisor
12. Remove Student from Facuty member
13. Exit
*/

// Please view StudentImplementation.h for functions
// Student class which will be a data type for bst to process
#ifndef StudentH
#define StudentH

#include <iostream>
#include <string>
class Student
{
public:
    Student();//Constructor
    Student(int id);//If only provide id, the rest of the info is empty
    Student(int id, std::string name, int cu, std::string major, double gpa, int advisor); //Standard info

    virtual ~Student(){}

    //Getter,important for bst   fetch
    int GetstudentID();
    std::string GetstudentName();
    int GetstudentCU();
    std::string GetstudentMajor();
    double Getgpa();
    int GetfacAdv();

    //Function for menu/main.cpp
    void changeFaculty(int facnewID);
    void print();
    void loadToFile(std::ostream& out);
    void loadSubToFile(std::ofstream& out);

    //Overloaded operators
    inline bool operator==(const Student& anotherstudent);// Return true when curr student == another student
    inline bool operator<(const Student& anotherstudent);// Return true when curr student < another student
    inline bool operator>(const Student& anotherstudent);// Return true when curr student > another student
    inline bool operator!=(const Student& anotherstudent);// Return true when curr student != another student

//1. Name, Studentid, TotalCU, Major, GPA, Facultyid
private:
    int studentID;
    std::string studentName;
    int studentCU;
    std::string studentMajor;
    double studentGPA;
    int facID;

};
// Load student info into file
void Student::loadToFile(std::ostream& out)
{
    out << studentName << "\n" << studentID << "\n" << studentCU << "\n" << studentMajor 
			<< "\n" << studentGPA << "\n" << facID << std::endl;
}

//does nothing, used for pairity with print to file function in bst so I did not have to 
//implement another function to print to file just for students
void Student:: loadSubToFile(std::ofstream& output)
{
}
#include "StudentImplementation.h"
#endif