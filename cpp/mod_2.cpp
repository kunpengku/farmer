#include <iostream>
#include <vector>

using namespace std;

void mod2(int a)
{
    vector<int> stack;

    while(a){
        stack.push_back(a%2);
        a /= 2;

    }   

    while(!stack.empty())
    {   
        int tmp = stack.back();
        cout << tmp ;
        stack.pop_back();
    }   
}
int main()
{
    int a=11;

    mod2(a);

    return 0;
}
