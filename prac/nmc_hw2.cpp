#include<iostream>
#include<cstring>

using namespace std;

class Person { 
private:
	char name[50];
	int age;
public:
	//함수 오버로드. 인자전달 안받았을 때 이시온 25로 초기화된
	Person() { 
		strcpy(name, "이시온");
		age = 25;
	}
	//인자 전달 받을 시 이 함수로 초기화 됨. 
	Person(char * myname, int myage) : age(myage) {
		strcpy(name, myname);
	}
	
	
	void Walk() {
		cout << "걷는중입니다." << endl;
	}

	//오버라이딩. 가상함수를 설정함으로써 이 클래스를 상속받은 Student 객체는 Student객체의 Study를 실행
    virtual void Study() {
		cout<<"공부안하는 중입니다"<<endl;
	}
	
	void Info() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	
	virtual ~Person();  //main에서 Person type으로 Student를 객체화하기 때문에. virtual로 해야 student 소멸시 person도 없애준다. 
};


class Student : public Person {
private:	
	int grade;
	int hour;
public:
	//함수 오버로드. 
	Student() : Person() {
		hour = 10;
		grade = 3;
	}
	Student(char * myname, int myage, int mygrade, int myhour) : Person(myname, myage), grade(mygrade), hour(myhour) {}

	//오버라이딩. 
	void Study() {
		cout << hour << "시간 째 공부하는 중입니다." << endl;
	}

	~Student();

};
//소멸시 소멸자 실행. 
Student::~Student() {
	cout << "학생 객체 소멸" << endl;
}
//소멸시 소멸자 실행. 
Person::~Person(){
    cout << "사람 객체 소멸" << endl;
}

int main()
{
	
	char name[] = "Junyoung";
	int age = 25;
	int grd = 100;
	int hour = 4;
	
	Person * ptr1 = new Person;   
	Student * ptr2 = new Student; //인자전달시 두번째 초기화함수 실행 됨.
	
	
	ptr1->Info();
	ptr1->Study();
	//만약 부모클래스의 오버라이딩된 함수가 가상함수가 아니라면, 여기서 부모클래스의 Study 메소드 호출됨. 
	//그러나 가상함수가 되어있으므로 현재 포인터가 가리키고 있는 클래스의 Study 함수 불러옴.
	ptr2->Study(); 
	
	delete ptr1;
	delete ptr2;
	// int age = 17;
	// char name[] = "Junyoung";
	// char sName[] = "Jihyun";
	// int grd = 100;
	// int hr = 5;
	
	// Person jun = Person(name, age);
	// jun.Info();
	// jun.Study();
	
	// Student std = Student(sName, age, grd, hr);
	// std.Study();
}
