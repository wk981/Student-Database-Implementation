#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "BSTree.h"
#include "Student.h"
#include "Faculty.h"
#include "functions.h"

//Please check functions.h if you want to edit them
void menu(); //Echo menu
Student InputStudent(); //User key in input for student class
Faculty InputFaculty();//User key in input for Faculty class

//Please refer the headers indicated above to checkout their functions
int main(){
    //First, we have to open the database file
    //Create a bst for student and faculty
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;

    std::string line;// This will be used for reading from file

    std::ifstream readF ("facultytable.txt"); // Input stream for reading data from facultyTable
    std::ifstream readS ("studenttable.txt"); // Input stream for reading data from studentTable

    //Open and read table and construct a Facility bst
    if(readF.is_open())
    {
        while(!readF.eof())
        {
            // The format of data in file will be. Name, Facultyid, Facultylevel, Dept, No. of student, Studentid(Will append)

            // Get name
            std::string Fname;
            std::getline(readF,Fname);

            // Get id
            std::getline(readF, line);
            int id = atoi(line.c_str());// Convert string into int

            // Get Security Level
            std::getline(readF, line);
            int Flvl = atoi(line.c_str());

            // Get dept
            std::string Fdept;
            std::getline(readF, Fdept);

            // Construct faculty class based on file
            Faculty newfac(id,Fname,Flvl,Fdept);
            masterFaculty.Add(newfac);

            // Get the number of students
            getline(readF, line);
            int numStudents = atoi(line.c_str());

            // Loop thru the numStudents and get the studentids
            for(int i =0;i<numStudents;++i)
            {
                getline(readF, line);
                int student = atoi(line.c_str());
                masterFaculty.fetch(newfac)->data.addStudent(student);
            }

            line = ""; //Used for debugging for error,
        }
        //Delete incorrect member
        Faculty deleteFac(0);
        masterFaculty.deleteNode(deleteFac);
        readF.close();
    }

    //Open and read table and construct a student bst
    if(readS.is_open())
    {
        while(!readS.eof())
        {
            // Data formate. Name, Studentid, CU, Major, GPA, Facultyid

            //get name
            std::string Sname;
            std::getline(readS,Sname);

            //get id
            std::getline(readS, line);
            int sid = atoi(line.c_str());

            //get cu
            std::getline(readS, line);
            int Scu = atof(line.c_str());

            //get Major
            std::string Smaj;
            std::getline(readS,Smaj);

            //get Gpa
            std::getline(readS, line);
            double sgpa = atof(line.c_str());

            //get facultyid
            std::getline(readS, line);
            int sadv = atoi(line.c_str());

            Student newStudent(sid,Sname,Scu,Smaj,sgpa,sadv);
            masterStudent.Add(newStudent);

            line = "";
        }
        Student deleteStudent(0);
        masterStudent.deleteNode(deleteStudent);
        readS.close();
    }

    int ans;
    Menu();

    std::cout << "Please Enter your choice : " << std::endl;
    std::cin >> ans;

    while(ans!=13)
    {
        switch(ans)
        {
            case 1: // Add student. (Cin Name,Total CU, Major, Studentid, Gpa, Advisorid(Will create a new advisorid if it doesnt exist))
            {
                Student newStudent(InputStudent());

                //Check if the tree contains the student
                if(!masterStudent.contains(newStudent))//Not in tree, prompt create a new advisor object
                {
                    Faculty tempFaculty1(newStudent.GetfacAdv());

                    // CHeck if tempFaculty1 exists in tree
                    if(masterFaculty.contains(tempFaculty1)) // Faculty Exists!
                    {
                        //Get id from masterFaculty(tree.fetch(temp)->data) and add the student class into master tree
                        masterFaculty.fetch(tempFaculty1)->data.addStudent(newStudent.GetstudentID());
                        masterStudent.Add(newStudent);
                    }
                    else // If advisor not in tree
                    {
                        std::cout << "Advisor not in DB" << std::endl;
                        Faculty Realfac(InputFaculty());

                        // Check entered facultyid is same as student facultyid
                        if(Realfac.getFacID() == newStudent.GetfacAdv())
                        {
                            masterFaculty.Add(Realfac);
                            masterFaculty.fetch(Realfac)->data.addStudent(newStudent.GetstudentID());
                            masterStudent.Add(newStudent);
                        }
                        else
                        {
                            std::cout << "Faculty ids do not match. Please try again " << std::endl;
                        }

                    }
                }
            }
            break;

            case 2: // Add faculty
            {
                Faculty newFaculty(InputFaculty());

                // if new faculty not in tree
                if(!masterFaculty.contains(newFaculty)) 
                {
                    masterFaculty.Add(newFaculty);
                }
                else
                {
                    std::cout << "Faculty is already in Database. Please try again " << std::endl;
                }
            }
            break;

            case 3: //Print all of Students (Sorted by student id)
            {
                if(masterStudent.isEmpty())
                {
                    std::cout << "Student's Database is empty ! " << std::endl;
                    std::cout << "Please add a Student ! " << std::endl;
                }
                else
                {
                    masterStudent.printDisplay();
                }
            }
            break;

            case 4: // Print all of Facualty (Sorted by Faculty id)
            {
                if(masterFaculty.isEmpty())
                {
                    std::cout << "Faculty's Database is empty ! " << std::endl;
                    std::cout << "Please add a Faculty ! " << std::endl;
                }
                else
                {
                    masterFaculty.printDisplay();
                }
            }
            break;

            case 5: //Find & Display Student info (Using their studentid)
            {
                int Studentid;
                std::cout << "Please Enter the Student's 5 digits ID(Example: 10004) : " <<std::endl;
                std::cin >> Studentid;

                Student tempStudent(Studentid);
                if(masterStudent.contains(tempStudent))
                {
                    masterStudent.fetch(tempStudent)->data.print();
                }
                else
                {
                    std::cout << "Student is not inside Database ! " << std::endl;
                    std::cout << "Please try again ! " << std::endl;
                }
            }
            break;

            case 6: // Find & Display Faculty member info (Using their Facultyid)

            {
                int Facultyid;
                std::cout << "Please Enter the Faculty's 6 digits ID(Example: 10004) : " << std::endl;
                std::cin >> Facultyid;

                Faculty tempFaculty(Facultyid);
                if(masterFaculty.contains(tempFaculty))
                {
                    masterFaculty.fetch(tempFaculty)->data.print();
                }
                else
                {
                    std::cout << "Faculty is not inside Database ! " << std::endl;
                    std::cout << "Please try again ! " << std::endl;
                }
            }
            break;

            case 7://Given a student's id, print the name and info of their faculty advisor
            {
                int Studentid;
                std::cout << "Please Enter the Student's 5 digits ID(Example: 10004) : " <<std::endl;
                std::cin >> Studentid;

                Student tempStud(Studentid);
                if(masterStudent.contains(tempStud))
                {
                    Faculty tempFac(masterStudent.fetch(tempStud)->data.GetfacAdv());
                    if(masterFaculty.contains(tempFac))
                    {
                        masterFaculty.fetch(tempFac)->data.print();
                    }
                    else
                    {
                        std::cout << "Faculty is not inside Database ! " << std::endl;
                        std::cout << "Please try again ! " << std::endl;
                    }
                }
                else
                {
                    std::cout << "Student is not inside Database ! " << std::endl;
                    std::cout << "Please try again ! " << std::endl;  
                }

            }
            break;

            case 8://Given a faculty id, print all the names and info of his/her advisees
            {
                int Facultyid;
                std::cout << "Please Enter the Faculty's 6 digits ID(Example: 10004) : " << std::endl;
                std::cin >> Facultyid;

                Faculty tempFaculty(Facultyid);
                if(masterFaculty.contains(tempFaculty))
                {
                    std::vector<int> studentList = masterFaculty.fetch(tempFaculty)->data.printStudentList();
                    for(size_t i=0;i<studentList.size();++i)
                    {
                        masterStudent.fetch(studentList[i])->data.print();
                    }
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Faculty is not inside Database ! " << std::endl;
                    std::cout << "Please try again ! " << std::endl;
                }
            }
            break;

            case 9://Remove Student
            {
                int stuID;
                std::cout << "Please enter the StudentID that you wished to remove" << std::endl;
                std::cin >> stuID;

                Student temp(stuID); //Student obj with only stuid
                if(masterStudent.contains(temp)) // If stuID exists
                {
                    //get FacultyID,if we delete a student, we have to delete the sudent from Faculty's List too
                    Faculty tempFaculty(masterStudent.fetch(temp)->data.GetfacAdv());
                    if(masterFaculty.contains(tempFaculty))
                    {
                        if(masterFaculty.fetch(tempFaculty)->data.hasStudent(stuID))
                        {
                            masterFaculty.fetch(tempFaculty)->data.removeStudent(stuID);
                            masterStudent.deleteNode(temp);
                        }
                        else
                        {
                            std::cout << "There is no Facultess" << std::endl;
                        }
                        
                    }
                    else
                    {
                        std::cout << "Facultee does not exist in database" << std::endl;
                    }
                    
                }
                else
                {
                    std::cout << "Student does not exist in database" << std::endl;
                }
            }
            break;

            case 10: //Remove Faculty member
                    // Remove facid from student
            {
                int FacID;
                std::cout << "Please enter the FacultyID that you wished to remove" << std::endl;
                std::cin >> FacID;

                Faculty tempFac(FacID);
                if(masterFaculty.contains(tempFac))
                {
                    std::vector<int> studentList = masterFaculty.fetch(tempFac)->data.printStudentList(); // List of advisee
                    if(!studentList.empty()) 
                    {
                        for(size_t i=0;i<studentList.size();++i)
                        {
                            Student tempStud(studentList[i]);
                            if(masterStudent.contains(tempStud))
                            {
                                masterStudent.fetch(studentList[i])->data.changeFaculty(0);
                            }
                            else
                            {
                                std::cout << "Student does not exist" << std::endl;
                            }
                        }
                        masterFaculty.deleteNode(FacID);
                    }
                    else//If there is no element in vector
                    {
                        std::cout << "No students" << std::endl;
                    }
                    
                }
                else
                {
                    std::cout << "Faculty does not exist in Database " << std::endl;
                }
                
            }
            case 11://Change Student's Advisor
            {
                int FacID,Stuid;
                std::cout << "Please enter the revelant StudentID " << std::endl;
                std::cin >> Stuid;   
                std::cout << "Please enter the FacultyID that you wished to change to" << std::endl;
                std::cin >> FacID;

                Student tempStud(Stuid);
                Faculty tempFac(FacID);
                if(masterStudent.contains(tempStud))
                {
                    if(masterFaculty.contains(tempFac)) 
                    {
                        Faculty OGfac(masterStudent.fetch(tempStud)->data.GetfacAdv());//Get original fac
                        if(masterFaculty.fetch(OGfac)->data.hasStudent(Stuid))
                        {
                            masterFaculty.fetch(OGfac)->data.removeStudent(Stuid); // OG fac remove student
                            masterFaculty.fetch(tempFac)->data.addStudent(Stuid); // New fac add student
                            masterStudent.fetch(tempStud)->data.changeFaculty(FacID);// Changed the student's facid to new facid
                        }
                        else
                        {
                            std::cout << "Student not advisee of previous faculty member." << std::endl;
                        }
                        
                    }
                    else
                    {
                        std::cout << "Faculty does not exist in this Database, please try again " << std::endl;
                    }
                }
                else
                {
                    std::cout << "Student does not exist in this Database" << std::endl;
                }
            }
            break;
            case 12:// Remove a Student in Facuty member
            {
                int FacID,Stuid;
                std::cout << "Please enter the revelant StudentID " << std::endl;
                std::cin >> Stuid;   
                std::cout << "Please enter the FacultyID that you wished to change to" << std::endl;
                std::cin >> FacID;

                Student tempStud(Stuid);
                Faculty tempFac(FacID);
                if(masterFaculty.contains(tempFac))
                {
                    if(masterFaculty.fetch(tempFac)->data.hasStudent(Stuid))
                    {
                        masterFaculty.fetch(tempFac)->data.removeStudent(Stuid);
                        masterStudent.deleteNode(tempStud);
                    }
                }
                else
                {
                    std::cout << "Faculty does not exist in this Database" << std::endl;
                }
            }

            case 13:
            {
                std::cout << "Goodbye Tarnished " << std::endl;
            }
            break;
        }
        std::cout << std::endl;
        std::cout <<"Please press Enter to continue" << std::endl;

        std::cin.ignore();
        std::cin.ignore();

        system("cls"); // Clear CMD screen

        Menu();
        std::cout << "Please Enter your choice : " << std::endl;
        std::cin >> ans;

    }//End of while loop

    //Write trees into respective files
	//writes trees to respective files
	std::ofstream WriteF ("facultyTable.txt");
	std::ofstream WriteS ("studentTable.txt");
	masterStudent.loadToFile(WriteS);
	masterFaculty.loadToFile(WriteF);
	
	//close output stream
	WriteF.close();
	WriteS.close();

    std::cout << "Program has ended succesfully !" << std::endl;
    return 0;
} 