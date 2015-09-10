#include <iostream>

using namespace std;

class A{
    public:
        A(int age);
        void print_age();
    private:
        int age;
};

A::A(int age): age(age)
{
}

void A::print_age()
{
    cout <<"my name is " << age << endl;
    //cout <<"my name is - " << this->age << endl;
}
int main()
{

    A a(18);

    a.print_age();

    return 0;
     
}
