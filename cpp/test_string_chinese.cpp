#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "你好世界";


    cout << s.size() <<endl;
        
    for(int i=0; i< s.size(); i+=3)
    {   
        string t = s.substr(i,3);
        cout << t << endl;
    }   


    return 0;
}
