#include <iostream>
class pos
{
public:
    pos(int xparam,int yparam)
    {
        x = xparam;
        y = yparam;
    }

    void print()
    {
        std::cout << "X: " << x << ",Y: " << y << std::endl;
    }
protected:
    int x;
    int y;

};

pos testFunc()
{
    int x,y;
    std::cout << "Please Enter X's value " << std::endl;
    std::cin >> x;
    while(x<0||x>5)
    {
        if(x<0)
        {
            std::cout << " X too small" << std::endl;
        }
        if(x>5)
        {
            std::cout <<" X too big" << std::endl;
        }
        std::cout << " Please Enter X's value again" << std::endl;
        std::cin >> x;
    }
    std::cout << "Please Enter Y's value " << std::endl;
    std::cin >> y;
    while(y<0||y>5)
    {
        if(y<0)
        {
            std::cout << "Y too small" << std::endl;
        }
        if(y>5)
        {
            std::cout <<"Y too big" << std::endl;
        }
        std::cout << "Please Enter Y's value again" << std::endl;
        std::cin >> y;
    }

    pos test(x,y);
    return test;
}

int main(){
    pos postest = testFunc();
    postest.print();
    std::cout << "Program has ended succesfully !" << std::endl;
    return 0;
}