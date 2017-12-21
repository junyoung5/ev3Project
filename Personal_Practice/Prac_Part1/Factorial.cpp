#include <iostream>

int factorial(int a);

main()
{
    int a, result;
    
    printf("input: ");
    scanf("%d", &a);
    
    if (a > = 0)
    {
        result = factorial(a);
        printf("%d!=%d\n", a, result);
    }else{
        printf("ERROR: negative integer\n");
    }
}

int factorial(int a){
    int i;
    int result = 1;
    
    for(i=1: i<=a; i++)
        result = result * i;
        
    return result;
}