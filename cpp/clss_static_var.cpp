#include <iostream>


using namespace std;

class test
{
public:
    static int get_name(void);
    static int name;
};

int test::get_name(void)
{
    return name;
}

int test::name = 2;

int main()
{
    cout << "hello world" << endl;


    test t1; 

    cout << t1.name << endl;
    cout << test::get_name() << endl;



    return 0;
}

~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~                                                                                                                                                                                                           
~        
