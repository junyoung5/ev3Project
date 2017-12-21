#include<iostream> 
void func( );
int global;

main( ) 
{
    int local = 1, local_in_main;
    std::cout << “global in main:” << global << std::endl; 
    std::cout << “local in main:” << local << std::endl;
    func( );
}
func( ) 
{
    int global = 99, local = 2;
    std::cout << “global in func: ” << global <<std::endl;
    std::cout << “local in func: ”<< local <<std::endl;
    //std::cout << “local_in_main in func: ”<< local_in_main <<std::endl;
}




/*
#include <iostream>

void func1();
int gl;

main(){
    int lo = 1 ;
    func1();
    std::cout<<"initial value of global:" << gl<<std::endl;
    std::cout<<"initial value of local: " << lo << std::endl;
    
}

void func1()
{
    int lo = 1;
}

*/