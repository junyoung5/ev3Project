#include <iostream>

main()
{
    
    char p[] = "Plato";
    //p[4] = 'e'; //*p를 이용했다면 const라 바꿀 수 없다. 배열을 이용해야 한다. 
    
    std::cout << p << std::endl;
    
    std::cout<< sizeof(p) <<std::endl;
   
}