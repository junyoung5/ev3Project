#include <iostream>
#define MAX 30
main()
{   
    //STRUCT
    struct student{
        unsigned int studentID;
        char name[MAX];
        unsigned int score;
        char grade; 
    };
    
    struct student student1 = {21300455, "Junyoung", 90, 'A'};
    
    std::cout << student1.studentID << std::endl;
    
    
    //UNION
    union number{
        int id;
        double gpa;
    };
    
    union number std1;
    std1.id = 21300455;
    std::cout << std1.id << std::endl;
    std1.gpa = 4.45;
    std::cout << std1.id << std::endl; //쓰레기값. 유니언은 한번에 한 맴버변수만 사용가능하다. 가장큰 메모리, 여기선  한번에 double(8byte)만 사용가능하다. 
    std::cout << std1.gpa << std::endl;
    
    //ENUMERATION
    //enum class Traffic_light{red, yellow, green};
    enum class Warning{green, yellow, orange, red}; 
    
    //Wanrning a1 = 7; //error, no int -> warning conversion
    //int a2 = green;  //error, green not in scope
    //int a3 = Warning::green;  //error, no warning -> int conversion
    Warning a4 = Warning::green; //OK< warning int -> warning conversion 
    std::cout<< Warning::green << std::endl;
}



void f(Warning key)
{
    switch(key){
        case Warning::green:
            // do something
            break;
        case Warning::yellow:
            // do something
            break;
        case Wanrning::orange:
            // do something
            break;
        case Wanrning::red:
            //do something
            break;
    }
}