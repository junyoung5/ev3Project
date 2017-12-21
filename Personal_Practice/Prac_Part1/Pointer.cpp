#include <iostream>
/*
• An object whose value represents the location(address) of another object
• More specifically:
– A variable that holds anaddress
• Usually don’t care what the actual numeric address value is – Except in systems programming (Embedded Programming)
*/
/*
main()
{
    int i, *iptr = NULL;
    std::cout << "address of i: " << &i << std::endl;
    std::cout << "address of *iptr: " << iptr << std::endl;
    std::cout << "Print *iptr" << *iptr <<std::endl; // segmentaiton fault. 
}
*/

main(){
    char **pp, *p, ch;    // **pp =>  char의 주소를 저장하기 위한 공간(*p)의 주소를 저장하는 공간. 
    ch = 'A';
    p = &ch;
    std::cout<< *p << std::endl;
    pp = &p;
    std::cout<< **pp << std::endl;
    **pp = 'B';  // ch의 value가 A에서 B로 바뀜. 
    std::cout<< ch <<std::endl;
    std::cout<< **pp <<std::endl;
    std::cout<< *p <<std::endl;  
    
    *p = 'f';
    
    std::cout<< **pp << ch << std::endl;
}