#include "Faculty.h"

/*
    int facID;
    std::string facName;
    std::string facLvl;
    std::string facDept;
*/

//Constructor
Faculty::Faculty()
{
    facID = 0;
    facName = "";
    facLvl = 0;
    facDept = "";
}
Faculty::Faculty(int id)
{
    facID = id;
    facName = "";
    facLvl = 0;
    facDept = "";
}
Faculty::Faculty(int id, std::string name, int lvl, std::string dept)
{
    facID = id;
    facName = name;
    facLvl = lvl;
    facDept = dept;
}

//Getter
// Get faculty ID
int Faculty::getFacID()
{
    return facID;
}

// Get faculty Name
std::string Faculty::getFacName()
{
    return facName;
}

// Get faculty security clearance
int Faculty::getFaclvl()
{
    return facLvl;
}

// Get faculty department
std::string Faculty::getFacDept()
{
    return facDept;
}

// Add student class into bst
void Faculty::addStudent(int student)
{
    studentTree.Add(student);
}

// Remove student from bst
void Faculty::removeStudent(int student)
{
    studentTree.deleteNode(student);
}

// Get the root of student tree
int Faculty::getStudentRoot()
{
    return studentTree.Getroot();
}

// Check whether tree is empty    
bool Faculty::isStudentListEmpty()
{
    return studentTree.isEmpty();
}

// Return the size of BST
int Faculty::getStudentListSize()
{
    return studentTree.getSize();
}

// Check whether student exists in bst
bool Faculty::hasStudent(int student) 
{
    return studentTree.contains(student);
}

/* facID = 0;
    facName = "";
    facLvl = "";
    facDept = "";
*/
// Print Faculty's info
void Faculty::print()
{
    std::cout << "Name: " << facName << " | ID: " << facID << " | Security Level: " << facLvl
				<< " | Department: " << facDept << " | Advisees: " ;
	std::vector<int> studentList = studentTree.GetStudentList();
    size_t i = 0;
    while(i<studentList.size())
    {
        if(i == studentList.size()-1)
        {
            std::cout << studentList[i];
            break;
        }
        std::cout << studentList[i] << ", ";

        ++i;
    }
    std::cout << std::endl;
	std::cout << std::endl;
}

// Print lists of student's data/id that is in the tree
std::vector<int> Faculty::printStudentList()
{
    std::vector<int> studentList = studentTree.GetStudentList();// Call from BST header file
    return studentList;
}


//prints list of students to file
void Faculty::loadSubToFile(std::ofstream& out)
{
    studentTree.loadSubToFile(out);
}

//Overloaded Operators
inline bool Faculty::operator==(const Faculty& anotherFac)
{
    return (this->facID == anotherFac.facID);
}
inline bool Faculty::operator<(const Faculty& anotherFac)
{
    return (this->facID < anotherFac.facID);
}
inline bool Faculty::operator>(const Faculty& anotherFac)
{
    return (this->facID > anotherFac.facID);
}
inline bool Faculty::operator!=(const Faculty& anotherFac)
{
    return (this->facID != anotherFac.facID);
}