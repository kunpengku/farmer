#include <iostream>

using namespace std;

class A{
    public:
    virtual int foo()
    {   
        cout << "A.foo " << endl;
    }   
};

class B : public A
{
    public:
        virtual int foo()
        {   
            cout << "B.foo" << endl;
        }   
};

int main()
{
    A a;
    a.foo();

    B b;
    b.foo();

    A *pa = new A();
    pa->foo();

    A *pb = new B();
    pb->foo();
}
