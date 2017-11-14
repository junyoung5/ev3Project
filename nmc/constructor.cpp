#include <iostream>

//formal parameter의 이름을 달리한 경우
class Student
{
private:
    int age;
    char* name;
public:
    Student();
    Student(int Age, char * Name)   //formal parameter의 이름을 달리한 경우
    {
        age = Age;
        name = Name;
    }
    
    
}


 //formal parameter의 이름과 Attribute이름 같게 하나 This 함수 사용. 
class Student
{
private:
    int age;
    char* name;
public:
    Student();
    Student(int age, char * name)  
    {
        this -> age = age;
        this -> name = name;
    }
    
    
}

