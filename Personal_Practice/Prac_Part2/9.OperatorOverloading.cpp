#include <iostream>
#include <string.h>
using namespace std;

class numbox
{
private:
    int num1, num2;
public:
    numbox(int _num1, int _num2):
    num1(_num1), num2(_num2)
    {
        
    }
    
    void print()
    {
        cout <<"num1: " << num1 << ", num2: " << num2 << endl;
    }
    
    numbox operator+(numbox &ref)   //Operator Overloading
    {
        return numbox(num1+ref.num1, num2+ref.num2);
    }
};

int main()
{
    numbox n1(10, 10);
    numbox n2(20, 20);
    numbox result = n1+n2;
    
    result.print();
}s