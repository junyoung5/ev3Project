#include <iostream>
#include <string.h>
using namespace std;

class record{
public:
    char* name;
    char* tel;
    record(const char*,const char* );
    record(const record &);
    ~record();
    void modifyTel(const char* _tel);
    void print(void);
};

record::record(const char* _n, const char* _tel)
{
    name = new char[strlen(_n)+1];
    strcpy(name, _n);
    tel = new char[strlen(_tel)+1];
    strcpy(tel, _tel);
}


//DEEP COPY
//멤버와이즈 카피시 변수들 중 포인터 변수가 있다면 두 오브젝트는 동일한 하나의 변수를 가리키게 된다
//즉 한 오브젝트 지울 시 다른 살아있는 오브젝트가 가리키는 타겟은 사라진다. 
//이 클래스의 경우 char* name 과 char* tel이라는 포인터형 변수가 존재
//즉 딥 카피해야한다. 
record::record(const record &_record)
{
    name = new char[strlen(_record.name)+1];
    strcpy(name, _record.name);
    tel = new char[strlen(_record.tel)+1];
    strcpy(tel, _record.tel);
    
}

record::~record()
{
    delete[] name, tel;
}

void record::modifyTel(const char* _tel){
    delete tel;
    tel = new char[strlen(_tel)+1];
    strcpy(tel, _tel);
}

void record::print(void){
    cout << name;
    cout <<" : " << tel <<endl;
    
}

int main(){
    record myRecord("KIM", "6556");
    record hisRecord(myRecord); //call DEEP COPY CONSTRUCTOR
    myRecord.modifyTel("5454");
    myRecord.print();
    hisRecord.print();
    return 0; //as soon as go out of scope, it calls the destructor

}