#include<iostream>
int main() 
{
    int num1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int num2[2][3] = { 1, 2, 3, 4, 5, 6 };
    for (int y = 0; y< 2; y++) { 
        for (int x = 0; x < 3; x++)
            printf("[%1d][%1d] %1d ", y, x, num1[y][x]); 
            std::cout << std::endl;
    }
    printf("---\n");
    for (int y = 0; y< 2; y++) {
        for (int x = 0; x < 3; x++)
            printf("[%1d][%1d] %1d ", y, x, num2[y][x]);
                std::cout << std::endl; 
    
    }
}
