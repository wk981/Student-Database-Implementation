## Disclaimer
I have took references from two Github projects and I have created this project to learn about BST DSA.

## Student Management Project
A Student management which has 2 levels, student and faculty(Teachers/Lecturers). The database is implementated using BST and will be written in modern cpp with reference to a project found in github.

## Why implement BST?
Because I want to practice implementing BST, and also achieving lookup time O(logN),Worst time O(N). Will be implementing self balancing algo into bst to achieve a constant time O(logN)

## Bank Management Interface
Students and Faculities

### Menu
1. Add student. (Cin Name,Total CU, Major, Studentid, Gpa, Advisorid(Will create a new advisorid if it doesnt exist))
2. Add Faculty (Cin Name, Security Clearance, Dept, ID,No. of student, Studentid(will add more))
3. Print all of Students (Sorted by student id)
4. Print all of Students (Sorted by Faculty id)
5. Find & Display Student info (Using their studentid)
6. Find & Display Faculty member info (Using their Facultyid)
7.  Given a student's id, print the name and info of their faculty advisor
8.  Given a faculty id, print all the names and info of his/her advisees
9. Remove Student
10. Remove Faculty member
11. Change Student's Advisor
12. Remove Student from Facuty member
13. Exit

## DSA Used
BST

## Lesson Learnt
1. Implementation of multiple data in a node.(BST_Node's std::string name_param,int account_param, std::string pass_param, int bal_param).From bank management project
2. Implementation of BST as Database. BSTNodes->data will contains class object(students/faculty) info(student id, gpa, etc..)
3. Destructor of BST(Calling remove function in destructor), Post Order traversal deletion
4. Constructing bst using external file
5. Writting and extracting BST into external file
6. Writting and Extracting file into Unordered Map
7. std::ifstream read; and std::ofstream write;
8. The process of ifstream and ofstream. TDLR: Read first then Write when we exit the menu
9. Making a type with BST. Example Student(type) BST,Construct an class(student/facility) bst by using template.
10. Importance of Fetch function in BST. Fetch will return BSTNodes and BSTNodes->data contains the class object based on the id .Example, BSTNodes->data of id 1000 will contains the object of studID 1000 and we can use the class function such as print() or getStuid
11. Learnt about a bst<faculty> tree's data(faculty object) contains another tree to sort out the faculty's student list.

### Making a type with BST. Example Student(type) BST
1. Using template on BST which results in flexible data type for BST
2. By constructing a class student and combination of template, we can use the student data type with BST

### Improvement plan
1. Optimize Case 8 to print student info (Done. Vector was implemented to both functions BST.GetStudentList() and faculty printStudentList())
2. Implement AVL to BST (Done)
3. Optimize main.cpp to look cleaner(Done. Transfer functions from main.cpp to function.h)
4. Set limit for inputs (Done. Implemented multiple while loop across the functions.h to check for upper and lower limit of input parameteres)

## Goals
[Goal]("")

## References
1. wkhaliddev's Bank Management - https://github.com/wkhaliddev/Bank-Management/blob/master/DSAproject/main.cpp
2. meeshaan's BST - https://github.com/meeshaan/BST
