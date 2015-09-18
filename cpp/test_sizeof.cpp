#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
	
	cout << "int" << sizeof(int) << endl;
	cout << "double" << sizeof(double) << endl;
	cout << "float" << sizeof(float) << endl;
	cout << "size_t" << sizeof(size_t) << endl;
	int x[10],  *p = x;
	cout << sizeof(x)/sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	return 0;
}
