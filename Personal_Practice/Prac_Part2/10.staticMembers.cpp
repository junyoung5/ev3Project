#include <iostream>
#include <string.h>
using namespace std;

class student{
public:
    int id;
    student(int i =0);
    static void printCount();
private:
    static int count;
};

int student::count = 0;
//static data member must be initialized outisde the class

student::student(int i){
    id = i;
    count++; //access to static member
}

void student::printCount(){
    cout <<"count="<<count<<endl;
    
}

int main(){
    student myID = 21300455;
    myID.printCount();
    
    student yourID;
    yourID.printCount();
    
    student hisID, herID;
    student::printCount();
    
}