#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <sstream>


using namespace std;

template <typename T>
string toString(const T& t,const int w=0)
{
    stringstream ss; 
    string str;
    ss<<setw(w)<<setfill('0')<<t;
    ss>>str;
    return str;
}

int main()
{
    int uid = 10089;
    char query_sql[1024];
    memset(query_sql, 0x00, sizeof(query_sql));
    sprintf( query_sql, " SELECT * FROM `some_table` WHERE `User_Id` = %d  " , uid );
        
    printf("%s\n", query_sql);


    string sql;
    sql = " SELECT * FROM `some_table` WHERE `User_Id` = " + toString(uid) ;

    cout << sql << endl;


    return 0;
}
