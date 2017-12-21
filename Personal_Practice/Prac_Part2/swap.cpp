#include <iostream>
#include <stdlib.h>

void swap(int *a, int *b);
void swap2(int *a, int *b);
void swap3(int &a, int &b);
main()
{
    int ix, iy, rx, ry;
    int cx, cy;
    
    ix = 1; iy = 2;
    cx = 1; cy = 2;
    rx = 1; ry = 2;
   
    
    std::cout<<ix<<" "<<iy<<std::endl;
    swap(&ix, &iy);
    std::cout<<ix<<" "<<iy<<std::endl;
    
    std::cout<<cx<<" "<<cy<<std::endl;
    swap(&cx, &cy);
    std::cout<<cx<<" "<<cy<<std::endl;
    
    std::cout<<rx<<" "<<ry<<std::endl;
    swap(&rx, &ry);
    std::cout<<rx<<" "<<ry<<std::endl;
    
    
    return 0;
}
 void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
    
    void swap2(int *a, int *b)
    {
        int* temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    void swap3(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
