#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

class record
{
public:
    char name[MAX];
private:
    int course1, course2;
    double avg;
public:
    record();
    record(const char*, int);
    record(const char*, int, int);
    void print(void);
};

record::record(){
    strcpy(name, "default");
    course1 = course2 = 100;
    avg = 100;
    
}

record::record(const char* str, int score){
    strcpy(name, str);
    course1 = course2 = score;
    avg = score;
}

record::record(const char* str, int score, int score2){
    strcpy(name, str);
    course1 = score;
    course2 = score2;
    avg = ((double)(course1+course2))/2.0;
}
void record::print(void)
{
    cout<<name<<" "<<course1<<" "<<course2<<" "<<avg<<endl;
    
}

int main(){
    //error: member variable is private.
    //record yourRecord = {"HONG", 100, 50};
    //yourRecord.print();
    
    
    //이건 왜 에러나지
    // record testRecord = record::record();
    // testRecord.print();
    
    
    record myRecord;
    
    //이건 왜 에러나지
    record yourRecord("KIM", 80, 100);
    record herRecord("LEE", 70);
    
    
    myRecord.print();
    yourRecord.print();
    herRecord.print();

    return 0;
}