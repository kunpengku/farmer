#include <iostream>
#include <stdexcept>


using namespace std;

int main()
{
    int t2; 
    try{
        while(cin >> t2) 
        {   
            if(t2 == 0){ 
                //throw exception();
                throw runtime_error("t2 is 0");
            }   
            int ret = t2 / 3;
            cout << t2 << " / " << "3" ;
            cout << " = " << ret << endl;

    
        }   
    }catch(runtime_error e){ 
        cout << e.what() << endl;
        cout << "bye runtime_error" << endl;
    }catch(exception e){ 
        cout << e.what() << endl;
        cout << "bye exception" << endl;
    }   

    return 0;
}
