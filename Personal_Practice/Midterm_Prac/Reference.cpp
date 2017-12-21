#include <iostream>

main()
{
    int i = 1;
    int& r = i;  // i는 r이라는 이름도 갖게됨. 
    int x = r;  //x = 1
    r = 22;  //i = 22;
    
    int* ptr;
    ptr = &r // ptr points i. 
}

//call-by-reference
