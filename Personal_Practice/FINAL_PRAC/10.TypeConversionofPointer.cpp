#include <iostream>
using namespace std;

class Person{
public:
    void Sleep(){cout<<"Sleep"<<endl;}
};

class Student:public Person{
    public:
    void Study(){cout<<"Study"<<endl;}
    void Sleep(){cout <<"Sleep from Student"<<endl;}
};

class Undergraduate:public Student{
    public:
    void Research(){cout << "Research" <<endl;}
    void Sleep(){cout <<"Sleep from Undergraduate"<<endl;}
};

int main(){
    Person *p1 = new Person;
    Student *p2 = new Student;
    Undergraduate *p3 = new Undergraduate;
    //왼쪽 타입이 다르니, virtual를 쓰지 않아도
    //잘 나옴. 
    
    p1->Sleep();
    p2->Sleep();
    p3->Sleep();
}