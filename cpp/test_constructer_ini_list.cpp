#include <iostream>


using namespace std;

class test
{
public:
    test(){};
    test(int a):age(a){};

    int get_age(){return age;}

private:
    int age;
};

int main()
{
    cout << "hello world" << endl;

    test t1(25);

    cout << t1.get_age() << endl;

    return 0;
}
