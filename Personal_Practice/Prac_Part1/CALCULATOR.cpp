//
//  main.cpp
//  cal
//
//  Created by 오준영 on 2017. 9. 21..
//  Copyright © 2017년 Jun. All rights reserved.
//

#include <iostream>

int main()
{
    char inputN[1000];
    int opr1, opr, opr2;
    std::cout<<"input: "<<std::endl;
    std::cin.getline(inputN, 1000);
    
    opr1 = ((inputN[0] - '0') * 1000) + ((inputN[1] - '0') * 100)  + ((inputN[2] - '0') * 10)  + (inputN[3] - '0');
    opr = inputN[4];
    opr2 = ((inputN[5] - '0') * 1000) + ((inputN[6] - '0') * 100)  + ((inputN[7] - '0') * 10)  + (inputN[8] - '0') ;
    
    std::cout<<opr1<<opr2<<std::endl;
    
    switch(opr)
    {
        case '+':
            std::cout<< opr1 << "+" << opr2 << "=" << opr1 + opr2 <<std::endl;
            break;
        case '-':
            std::cout<<opr1 - opr2 <<std::endl;
            break;
        case '*':
            std::cout<<  opr1 * opr2 <<std::endl;
            break;
        case '/':
            std::cout<<opr1 / opr2 << std::endl;
            break;
    }
}

/*
namespace intSapce{
    int data;
    void add(int n)
    {
        data += n;
    }
    void print(){std::cout<< data << std::endl;}
}

namespace DoubleSpace{
    int data;
    void add(int n){data += n;}
    void print(){std::cout<< data<< std::endl;}
    
}

int main(){
    intSapce::data = 2;
    DoubleSpace::data = 3;
    intSapce::add(5);
    DoubleSpace::add(6);
    intSapce::print();
    DoubleSpace::print();
}
*/

/*
int factorial(int a);
int a;

int main(){
    int result;
    std::cout<<"input: "<<std::endl;
    std::cin>>a;
    
    if (a >= 0){
        result = factorial(a);
        std::cout<<a<<"! = "<<result<<std::endl;
    }else{
        std::cout<<"ERROR: negative input"<<std::endl;
    }
    
    a += 5;
    std::cout<< a <<std::endl;
}

int factorial(int a){
    int i;
    int result = 1;
    for(i = 1; i <= a; i ++)
        result = result * i;
    return result;
}

*/