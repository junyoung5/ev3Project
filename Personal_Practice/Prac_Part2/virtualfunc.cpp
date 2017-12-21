#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class AA
{
public:
   virtual void test1()
   {
      cout << "test1" << endl;
   }
   void test2()
   {
      cout << "test2" << endl;
   }
   void test3()
   {
      cout << "test3" << endl;
   }
};
class BB :public AA
{
   void test1()
   {
      cout << "test11" << endl;
   }
   void test2()
   {
      cout << "test33" << endl;
   }
   void test3()
   {
      cout << "test44" << endl;
   }
};


class CC: public BB
{
    void test1()
    {
        cout << "test111" << endl;
    }
    
    void test2()
    {
        cout << "test222" << endl;
    }
    
    void test3()
    {
        cout << "test333" << endl;
    }
};

int main()
//Virtual을 선언해주어야 포인트 변수로 다른거 접근이 가능한거임
//그래서 AA *ob = new BB; 이여도 virtual이 아니면 BB객체에 접근이 불가능.
//근데 Virtual이 있으면 이제 값에 주소값이 들어가면서 접근이 가능한거임.
{
   AA *ob = new CC; //이게 뭐냐면 자식은 부모가 누군지 아는데 부모는 자신의 자식이 누군지 모름
   //그래서 이렇게 선언함과 동시에 AA와 BB가 서로 파생, base 관계를 가지고 있다는걸 알 수 있다.
   ob->test1();
   ob->test2();
   ob->test3();
   //ob->test4();
   delete ob;
   return 0;
}
