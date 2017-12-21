/*
a function name can be overloaded
same function name, different parameter and return type

Min(a, b, c)
Min(a, b)
Min(14.2, 3, 1)

compiler try to find most appropriate funciton
- first look for function definition where parameters exatly match
-if not exact match, the compiler will attemp to cast the actual parameters to ones used by an appropriate fucntion(HOW DO YOU TRUST THIS?)


***
function delcared in different scope do not overload, it will find close funciton


ex:

int square(int num);

float square(float num);
int square(int x, int y, int len, int wid);
*/


/*

char *s = new char[strlen(p) +1];
delete[] s;

