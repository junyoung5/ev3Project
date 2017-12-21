#include <iostream>
#include <stdlib.h>
#include <string.h>
int main()
{
    
    int studentNum, score, total=0;
    int* pStudentPoint;
    
    char* s = new char[10];
    strcpy(s, "helloy");
    std::cout<< s << std::endl;
    delete []s;
    
    
    
    
    
    std::cin>>studentNum;
    
    pStudentPoint = new int(studentNum);
    
    for(int i=0; i < studentNum; i++)
    {
        std::cin>> pStudentPoint[i];
        total += pStudentPoint[i];
    }
    
    
    std::cout << total/studentNum << std::endl;
    delete []pStudentPoint;
    return 0;
    
}