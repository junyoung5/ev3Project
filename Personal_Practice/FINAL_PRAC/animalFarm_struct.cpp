#include <iostream>
#include <string.h>
using namespace std;


void Dog_cry(){
    cout<<"MUNG"<<endl;
    };

void Cat_cry(){
    cout<<"YAONG"<<endl;
    };
    

int main()
{
    struct animal{
        void (*Cry)();
    }animal_farm[10];

  
    animal_farm[0].Cry = Dog_cry;
    animal_farm[1].Cry = Cat_cry;
    
    for(int i=0; i < 10; i++)
    {
        animal_farm[i].Cry();
    }
    
}