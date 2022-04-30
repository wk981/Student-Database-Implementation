#ifndef BSTreeHead
#define BSTreeHead

#include <iostream>
#include "Node.h"
#include <vector>
//Please head over to BSTreeImplementation.h to see the functions details

template<typename t>
class BST //Constructing a bst example BST<student> studentbst
{
public:
    BST() // Constructor
    {
        size = 0; // New tree so root will be nullptr and size will be 0
        root = nullptr;
    }
    ~BST()// RAII, delete existing nodes in tree when exiting main application
    {
        utilD(this->root);
        root = nullptr;
        size = 0;
        //std::cout << "BST is deleted" << std::endl; // Indication
    }

    void EmptyTree();//Empty bst tree using destructorUtil
    bool contains(t d); // Check whether the data is inside the tree
    int getSize(){return size;} // Return size of tree
    bool isEmpty(){return (size==0);}// Check whether tree is empty
    void Add(t d);// Add node into tree
    void deleteNode(t d);// Remvoe Node
    BSTNodes<t>* getSuccesor(BSTNodes<t>* curr);

	void print();
    void preOrder();
	std::vector<int> GetStudentList();
	void printDisplay();
	void loadToFile(std::ofstream& output);
	void loadSubToFile(std::ofstream& output);

    t Getroot();
    BSTNodes<t>* fetch(t d); // Return the point to the d node

private:
    int size;
    BSTNodes<t>* root; //Head student/facility type node of the tree

    int max(int a,int b);

    BSTNodes<t>* removeUtil(BSTNodes<t>* r, t d); // Remove node utility
    void utilD(BSTNodes<t>* r);// Destructor utility
    BSTNodes<t>* addUtil(t d, BSTNodes<t>* r); // Add Ulti
	void printHelper(BSTNodes<t>* n);
	void printSubUtil(BSTNodes<t>* n, std::vector<t>& arr);
	void printDisplayHelper(BSTNodes<t>* n);
	void printToFileUtil(BSTNodes<t>* n, std::ofstream& output);
    void preOrderUtil(BSTNodes<t>* r);
	void loadSubToFileUtil(BSTNodes<t>* n, std::ofstream& output);
    void loadfUtil(BSTNodes<t>* r,std::ostream& output);// load util, using inoder traversal
    int getHeight(BSTNodes<t>* r);//Get height of the node
    int getBalance(BSTNodes<t> *r);//Get the balance between left node and right node
    BSTNodes<t>* leftRotate(BSTNodes<t> *r);
    BSTNodes<t>* rightRotate(BSTNodes<t> *r);
};
//writes content of tree to file, uses print to file helper
template <typename T>
void BST<T>:: loadToFile(std::ofstream& output)
{
	printToFileUtil(root, output);
}

//helper function for print to file, uses recursion to print bst to file
template <typename t>
void BST<t>:: printToFileUtil(BSTNodes<t>* n, std::ofstream& output)
{
	//null check
	if (n != 0)
	{
		printToFileUtil(n -> left, output);
		n -> data.loadToFile(output);
		n -> data.loadSubToFile(output);
		printToFileUtil(n -> right, output);
	}
}
#include "BSTreeImplementation.h"
#endif