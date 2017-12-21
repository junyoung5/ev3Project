#include <iostream>
#include <stdlib.h>
#define MAX 100

main()
{
    struct student{
        unsigned int studentID;
        char name[100];
        unsigned int score;
        char grade;
    };
    
 
    
    struct student mystudent = {21300566, "KIM", 100, 'A'};
    
    
   
    
    std::cout<< mystudent.name <<std::endl;
}