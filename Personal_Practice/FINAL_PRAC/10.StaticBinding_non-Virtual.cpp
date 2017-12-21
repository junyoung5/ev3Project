#include <iostream>
#include <string.h>
using namespace std;

class Parent{
public:
    void print(){
        cout <<"I am your FATEHR"<<endl;
    }
    
    void print(int i){
        for(int j = 0; j<i; j++){
            cout <<"I am your FATHER"<<endl;
        }
    }

};

class Child: public Parent{
public:
    void print(){
        cout <<"I am your SON"<<endl;
    }
};

int main()
{
    Child* child = new Child();
    child->print();
    
    Parent* father = child;
    father->print(); //static biding
    
    delete child;
    return 0; 
}