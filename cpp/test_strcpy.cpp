#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char t1[] = "nihao";
    char t2[] = " fupeng";

    char ret[40]={0};

    strcpy(ret,t1);
    strcat(ret,t2);

    for(int i=0;i<40;i++)
        cout << ret[i] ;
}
