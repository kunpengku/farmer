#include <iostream>

using namespace std;

int index_bf(string s, string b)
{
	int lens = s.size();
	int lenb = b.size();
	int index;
	cout << "lens=" << lens <<", lenb="<< lenb << endl;
	for(int i=0;i<= lens-lenb;i++){
		int j;
		int k=i;
		for(j=0;j<lenb;j++){
			
			if(s[k] == b[j])
			{
				k++;
			}else{
				break;
			}
			
		}
		cout << "j=" << j << "lenb=" << lenb << " i=" << i<< endl;
		if(j == lenb){
			cout << "find it" << endl;
			return i;
		}
			 
	}
	return -1;
}

int main(int argc, char *argv[]) {
	string s ="nihaofupeng";
	string b = "fupeng";
	int index = index_bf(s,b);

	cout << "index= " << index << endl;
}
