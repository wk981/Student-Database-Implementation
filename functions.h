#ifndef functionH
#define functionH

#include <iostream>
#include <string>
#include <stdlib.h>
#include "BSTree.h"
#include "Student.h"
#include "Faculty.h"
//Display Menu
void Menu()
{
    std::cout << std::endl;
    std::cout<< "Hi there Maidenless, this is a student & advisor database implemented with BST" << std::endl;
    std::cout << std::endl;

    std::cout << "1. Add student. (Cin Name,Total CU, Major, Studentid, Gpa, Advisorid(Will create a new advisorid if it doesnt exist))" << std::endl;
    std::cout << "2. Add Faculty (Cin Name, Security Clearance, Dept, ID,No. of student, Studentid(will add more))" << std::endl;
    std::cout << "3. Print all of Students (Sorted by student id)" << std::endl;
    std::cout << "4. Print all of Facultys (Sorted by Faculty id)" << std::endl;
    std::cout << "5. Find & Display Student info (Using their studentid)" << std::endl;
    std::cout << "6. Find & Display Faculty member info (Using their Facultyid)" << std::endl;
    std::cout << "7. Given a student's id, print the name and info of their faculty advisor" << std::endl;
    std::cout << "8. Given a faculty id, print all the names and info of his/her advisees" << std::endl;
    std::cout << "9. Remove Student from Database" << std::endl;
    std::cout << "10. Remove Faculty member from DataBase" <<std::endl;
    std::cout << "11. Change Student's Advisor" << std::endl;
    std::cout << "12. Remove Student in Facuty member" << std::endl;
    std::cout << "13. Exit" <<std::endl;

    std::cout << std::endl;
}

//Create a new Student object
Student InputStudent()
{
    int id;
    std::string name;
    int culvl;
    std::string major;
    double gpa;
    int AdvisID;

    std::cin.ignore();
    
    std::cout << "Enter Student Name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter Student's Major: " << std::endl;
    std::getline(std::cin, major);

    std::cout << "Enter Student Total Credit Unit (Between 5 to 25): " << std::endl;
    std::cin >> culvl;
    while(culvl<5||culvl>25)
    {
        if(culvl<5)
        {
            std::cout<< "[Invalid] Total Credit unit too small" << std::endl;
        }
        else
        {
            std::cout << "[Invalid] Total Credit unit too big" << std::endl;
        }
        std::cout << "[Invalid] Please enter Student's Total Credit Unit again (Between 5 to 25) " << std::endl;
        std::cin >> culvl;
    }

    std::cout << "Enter Student's 5 digits ID (Example: 10001): ";
    std::cin >> id;
    while(id >= 99999)
    {
        std::cout << "[Invalid] Invalid ID" << std::endl;
        std::cout << "[Invalid] Please enter Student's ID again (Example: 10001) " << std::endl;
        std::cin >> id;
    }

    std::cout << "Enter Student's GPA (0.0 to 4.0): ";
    std::cin >> gpa;
    while(gpa < 0.0 || gpa > 4.0)
    {
        std::cout << "[Invalid] Invalid GPA" << std::endl;
        std::cout << "[Invalid] Please enter Student's GPA again (0.0 to 4.0) " << std::endl;
        std::cin >> gpa;  
    }

    std::cout << "Enter Advisor's 6 digits ID (Example 100006): ";
    std::cin >> AdvisID;
    while(AdvisID >= 999999)
    {
        std::cout << "[Invalid] Invalid AdvisorID" << std::endl;
        std::cout << "[Invalid] Please enter AdvisorID again (Example 100006) " << std::endl;
        std::cin >> AdvisID;
    }

    Student newStudent(id,name,culvl,major,gpa,AdvisID);
    return newStudent;
}

//Create a new Faculty object
Faculty InputFaculty()
{
    int id;
    std::string name;
    int securlvl;
    std::string dept;


    std::cin.ignore();
    
    std::cout << "Enter Faculty Name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter Faculty's Departmant(Example: BIO,CHEM): " << std::endl;
    std::getline(std::cin, dept);

    std::cout << "Enter Faculty Clearance Level(0 to 5): " << std::endl;
    std::cin >> securlvl;
    while(securlvl<0 || securlvl>5)
    {
        std::cout << "[Invalid] Faculty Clearance Level " << std::endl;
        std::cout << "Please enter your Faculty Clearance Level again " << std::endl;
        std::cin >> securlvl;
    }

    std::cout << "Enter Advisor's 6 digits ID (Example 100006): ";
    std::cin >> id;
    while(id >= 999999)
    {
        std::cout << "[Invalid] Invalid AdvisorID" << std::endl;
        std::cout << "[Invalid] Please enter AdvisorID again (Example 100006) " << std::endl;
        std::cin >> id;
    }

    Faculty newFaculty(id,name,securlvl,dept);
    return newFaculty;
}
#endif