#include "BSTree.h"
#ifndef BSTreeImplementation_H
#define BSTreeImplementation_H

template <typename t>
int BST<t>::max(int a,int b)
{
    return (a > b) ? a : b;
}


//Implementation of BSTree functions here
//Empty bst tree using destructorUtil
template <typename t>
void BST<t>:: EmptyTree()
{
    utilD(root);
    root = nullptr;
    size = 0;
    //std::cout << "BST is deleted" << std::endl; // Indication
}

//Private Function Declaration
//Delete Utility
template <typename t>
void BST<t>:: utilD(BSTNodes<t>* r)
{
    if(r!=nullptr) // Post Traversal deletion
    {
        utilD(r->left);
        utilD(r->right);
        //std::cout << "BST Node is deleted" << std::endl;
        delete r;
    }
}

//Add node
template <typename t>
void BST<t>:: Add(t d)
{
    root = addUtil(d, root);
    ++size;
    //std::cout << "Added" << std::endl;
}

// Add Util
template <typename t>
BSTNodes<t>* BST<t>:: addUtil(t d, BSTNodes<t>* r)
{
    if(r==nullptr)
    {
        BSTNodes<t>* newnode = new BSTNodes<t>(d);
        return newnode;
    }

    if(d < r->data)
    {
        r->left = addUtil(d, r->left);
    } 
    else if(d > r->data)
    {
        r->right = addUtil(d, r->right);
    }
    else
    {
        return r;
    }

    r->height = 1 + max(getHeight(r->left),getHeight(r->right));

    int balance = getBalance(r);

    if (balance > 1 && d < r->left->data) // LL imbalance, perform right rotation
    //To check whether it is left left case or not, compare the newly inserted key with the key in left subtree root. 
    {
        return rightRotate(r);
    }

    if (balance < -1 && d > r->right->data) // RR imbalance, perform left rotate
    {
        return leftRotate(r);
    }

    if (balance > 1 && d > r->left->data) // LR imbalance
    {
        r->left = leftRotate(r->left);// rotate the left subtree to left first then rotate the root to right
        return rightRotate(r);
    }
    
    if (balance < -1 && d < r->right->data) //RL Imbalance
    {
        r->right = rightRotate(r->right); // rotate the right subtree to right first then rotate the root to left
        return leftRotate(r);
    }

    return r;
}

//writes a tree to file, specifically implemented for assignment 4 for faculty
template <typename t>
void BST<t>:: loadSubToFile(std::ofstream& output)
{
	loadSubToFileUtil(root, output);
}

//helper function for print sub to file
template <typename t>
void BST<t>:: loadSubToFileUtil(BSTNodes<t>* n, std::ofstream& output)
{
	//null check
	if (n != 0)
	{
		loadSubToFileUtil(n -> left, output);
		output << n -> data << std::endl;
		loadSubToFileUtil(n -> right, output);
	}
}

template <typename t>
void BST<t>::preOrder()
{
    preOrderUtil(root);
}

//Preorder
template <typename t>
void BST<t>::preOrderUtil(BSTNodes<t>* r)
{
    if(r!=nullptr)
    {
        std::cout << r->data << std::endl;
        preOrderUtil(r->left);
        preOrderUtil(r->right);
    }
}


//prints content of the tree
template <typename t>
void BST<t>:: print()
{
	printHelper(root);
}

//helper function for printing the tree
template <typename t>
void BST<t>:: printHelper(BSTNodes<t>* n)
{
	//null check
	if (n != 0)
	{
		printHelper(n -> left);
		std::cout << n -> data << std::endl;
		printHelper(n -> right);
	}
}

//prints content of the tree
template <typename t>
std::vector<int> BST<t>::GetStudentList()
{
    std::vector<int> studentList; // Empty Array
	printSubUtil(root,studentList);
    return studentList;
}

//helper function for printing the tree, prints data with space b/n them, used for Faculty 
template <typename t>
void BST<t>::printSubUtil(BSTNodes<t>* n, std::vector<t>& arr)
{
	//null check
	if (n != 0)
	{
		printSubUtil(n -> left, arr);
		//std::cout << n -> data << " ";
        arr.push_back(n->data);
		printSubUtil(n -> right, arr);
	}
}

//prints content of tree to screen, used in assignment 4 for faculty and student
template <typename T>
void BST<T>:: printDisplay()
{
	printDisplayHelper(root);
}

//helper function for print display
template <typename t>
void BST<t>:: printDisplayHelper(BSTNodes<t>* n)
{
	//null check
	if (n != 0)
	{
		printDisplayHelper(n -> left);
		n -> data.print();
		printDisplayHelper(n -> right);
	}
}
template <typename t>
t BST<t>:: Getroot()
{
    return root->data;
}


// Check whether the data is inside the tree. Function will return true if the data is in tree
template <typename t>
bool BST<t>::contains(t d)
{
    bool status = false;
    BSTNodes<t>* curr = root;
    while(curr!=nullptr)
    {
        if(d > curr->data)
        {
            curr = curr->right;
        }
        else if(d < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            status = true;
            break;
        }
    }
    return status;
}

template <typename t>
BSTNodes<t>* BST<t>::getSuccesor(BSTNodes<t>* d)
{
    BSTNodes<t>* curr = d;

    while(d->left!= nullptr)
    {
        curr = curr->left;
    }
    return curr;
}

// Remove Node
template <typename t>
void BST<t>::deleteNode(t d)
{
    root = removeUtil(root, d);
    --size;
}

// Remove node utility
template <typename t>
BSTNodes<t>* BST<t>::removeUtil(BSTNodes<t>* r, t d)
{
    if(r==nullptr)
    {
        return r;
    }

    if(d < r->data) // when the input d is less than the root, go left
    {
        root->left = removeUtil(r->left, d);
    }

    else if(d>r->data) // when the input d is more than the root, go right
    {
        root->right = removeUtil(r->right, d);
    }

    else if(d == r->data)
    {
        if(r->left == nullptr)
        {
            BSTNodes<t>* temp = r->right;
            r = nullptr;
            return temp;
        }
        else if(r->right == nullptr)
        {
            BSTNodes<t>* temp = r->left;
            r = nullptr;
            return temp;
        }

        else
        {
            BSTNodes<t>* successor = getSuccesor(r->right); //Get the successor from right subtree
            r->data = successor->data;
            r->right = removeUtil(r->right,successor->data);
        }

    }
    if(r == nullptr)
    {
        return r;
    }
    r->height = 1 + max(getHeight(r->left),getHeight(r->right));

    int balance = getBalance(r);

    if(balance > 1 && getBalance(r->left) >=0 )// LL case.To check whether it is Left Left case or Left Right case, get the balance factor of left subtree.
                                               // If balance factor of the left subtree is greater than or equal to 0, then it is Left Left case, else Left Right case. 
    {
        return rightRotate(r);
    }
    if(balance >1 && getBalance(r->left) < 0 ) //LR Case
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if(balance < -1 && getBalance(r->right) <=0 ) // RR Case
    {
        return leftRotate(r);
    }
    if(balance < -1 && getBalance(r->left) >0 ) //RL case
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}

// Return the point to the d node
template <typename t>
BSTNodes<t>* BST<t>::fetch(t d)
{
    BSTNodes<t>* curr = root;
    while(curr!=nullptr)
    {
        if(d > curr->data)
        {
            curr = curr->right;
        }
        else if(d < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            break;
        }
    }
    return curr;
}

//Private Function Declaration

//Get height of the node
template <typename t>
int BST<t>:: getHeight(BSTNodes<t>* r)
{
    if(r==nullptr)
    {
        return 0;
    }
    return r->height;
}

//Get the balance between left node and right node
template <typename t>
int BST<t>:: getBalance(BSTNodes<t>* r)
{
    if(r==nullptr) 
    {
        return 0;
    }
    int Balleft,Balright;
    Balleft = getHeight(r->left);
    Balright = getHeight(r->right);
    return Balleft - Balright;
}

// Left rotate
template <typename t>
BSTNodes<t>* BST<t>::leftRotate(BSTNodes<t> *r)
{
/*
            
   y     Left Rotate (y)          x    
  / \      - - - - - - - - ->    /  \     
T1   x                          y    T3          
    / \                        / \
  T2   T3                    T1   T2                         
*/
    BSTNodes<t>* rRight = r->right;
    BSTNodes<t>* rRLeft = rRight->left;

    rRight->left = r;
    r->right = rRLeft;

    //Update the height

    r->height = 1 + max(getHeight(r->left),getHeight(r->right));
    rRight->height = 1 + max(getHeight(rRight->left),getHeight(rRight->right));

    return rRight;

}

//Right Rotate
template <typename t>
BSTNodes<t>* BST<t>::rightRotate(BSTNodes<t> *r)
{
/*
        z                           x
      /   \                        /  \ 
     x    T4  Right Rotate(z)    y      z
    /  \      - - - - - - - ->  / \    / \
   y    T3                    T1  T2 T3  T4
  / \
T1   T2                         
*/

    BSTNodes<t>* rLeft = r->left;
    BSTNodes<t>* rLRight = rLeft->right;

    rLeft->right = r;
    r->left = rLRight;

    //Update height
    r->height = 1 + max(getHeight(r->left),getHeight(r->right));
    rLeft->height = 1 + max(getHeight(rLeft->left),getHeight(rLeft->right));

    return rLeft;


}

#endif