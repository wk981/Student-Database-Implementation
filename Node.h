#ifndef Nodes_H
#define Nodes_H

//BST nodes flexible class
template<typename t>
class BSTNodes
{
public:
    BSTNodes(t d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
    virtual ~BSTNodes()//RAII, set nodes to 0 when exiting main application
    {
        data = 0;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
    
    BSTNodes<t>* left;
    BSTNodes<t>* right;
    t data;
    int height;

};
#endif