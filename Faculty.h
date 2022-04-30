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

#ifndef FacultyH
#define FacultyH

#include "BSTree.h"
// Please view FacultyImplementation.h for functions

class Faculty
{
public:
    //Constructor
    Faculty();
    Faculty(int id);
    Faculty(int id, std::string name, int lvl, std::string dept);

    //Destructor
    virtual ~Faculty(){}

    //Getter
    int getFacID();
    std::string getFacName();
    int getFaclvl();
    std::string getFacDept();

    //Functions to implement in menu
    void addStudent(int student); // Add student class into bst
    void removeStudent(int student); // Remove student from bst
    int getStudentRoot(); // Get the root of student tree
    bool isStudentListEmpty(); // Check whether tree is empty
    int getStudentListSize(); // Return the size of BST
    bool hasStudent(int student); // Check whether student exists in bst

    void print(); // Print Contents of Faculty
    std::vector<int> printStudentList(); // Print lists of student's data/id that is in the tree
    void loadToFile(std::ostream& out);//prints faculty member to file
    void loadSubToFile(std::ofstream& out);//prints list of students to file

    //Overloaded Operators
    inline bool operator==(const Faculty& anotherFac);
    inline bool operator<(const Faculty& anotherFac);
    inline bool operator>(const Faculty& anotherFac);
    inline bool operator!=(const Faculty& anotherFac);


//Name, Facultyid, Facultylevel, Dept, No. of student, Studentid(Will append)
private:
    int facID;
    std::string facName;
    int facLvl;
    std::string facDept;

    BST<int> studentTree;

};
//prints faculty member to file
void Faculty::loadToFile(std::ostream& out)
{
    out << facName << "\n" << facID << "\n" << facLvl
				<< "\n" << facDept << "\n" << getStudentListSize() << std::endl;
}


#include "FacultyImplementation.h"
#endif