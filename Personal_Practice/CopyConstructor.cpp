#include <iostream>

//member wise copy의 문제는 주소값이 복사 되었다면 주소값을 복사한다
//또 둘중 한 공간이 사라지면 값을 잃게 된다. 또, 쓸모없어진 공간은 사라지지 않고 남아있어 안좋음. 
//
//그러나 Copy Constructor는 주소값 복사시 한 공간 사라진다. 



class Table
{
public:
    Table(const Table&);
    Table &operator = Table(const Table&);
};


void h()
{
    Table t1;
    Table t2 = t1;
    t3 = t2;
}