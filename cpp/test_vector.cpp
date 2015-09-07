#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
	vector<string> ivec;
	string s;
	while( cin >> s ){
		if(s == "z")
			break;
		ivec.push_back(s);
	}
	
	string ret;
	for(int i=0;i< ivec.size();i++)
	{
		string s =ivec[i];
		cout << s << endl;
		
		for(int j=0;j<s.size();j++){
			s[j] = toupper(s[j]);
		} 
		ret = ret + s;
	}
	
	cout << ret << endl;
}
