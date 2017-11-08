#include<iostream>
#include<cstring>

using namespace std;

class Person { 
private:
	char name[50];
	int age;
public:
	Person() {
		strcpy(name, "이시온");
		age = 25;
	}
	Person(char * myname, int myage) : age(myage) {
		strcpy(name, myname);
	}
	
	void Walk() {
		cout << "걷는중입니다." << endl;
	}

	virtual void Study() {
		cout<<"공부안하는 중입니다"<<endl;
	}
	
	void Info() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	
	virtual ~Person();
};

class Student : public Person {
private:	
	int grade;
	int hour;
public:
	Student() : Person() {
		hour = 10;
		grade = 3;
	}
	Student(char * myname, int myage, int mygrade, int myhour) : Person(myname, myage), grade(mygrade), hour(myhour) {}

	void Study() {
		cout << hour << "시간 째 공부하는 중입니다." << endl;
	}

	~Student();

};
Student::~Student() {
	cout << "학생 객체 소멸" << endl;
}
Person::~Person(){
    cout << "사람 객체 소멸" << endl;
}

int main()
{
	Person * ptr1 = new Person;
	Student * ptr2 = new Student;

	ptr1->Info();
	ptr1->Study();
	ptr2->Study();

	delete ptr1;
	delete ptr2;
}