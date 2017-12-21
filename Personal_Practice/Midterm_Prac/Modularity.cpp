#include <iostream>

double sqrt(double);//the square root function takes a double and returns a double 

class Vector{
    public:
    Vector(int s);
    double& operator[](int i);
    int size() const;
    // "const" suffix means "can be applied to const objects"
    private:
    double* elem;
}

double sqrt(double d)
{
    //
}

Vector::Vector(int s)  //definition of constructor 
    :elem{ new double[s]}, sz{s} //initialize members
{
    
}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}