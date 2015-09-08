#include <iostream>
#include <vector>

using namespace std;

void test2()
{
    vector<int> a;
    for(int i=0;i<10;i++){
        a.push_back(i);
    }   

    for(int i=0;i<10;i++){
        cout << a[i] << endl;
    }   
}

int main()
{
    int a[10];

    for(int i=0;i<10;i++)
    {   
        a[i] = i;
    }   

    for(int i=0;i<10;i++)
    {   
        cout << a[i] << endl ;
    }   

    test2();
    return 0;
}
