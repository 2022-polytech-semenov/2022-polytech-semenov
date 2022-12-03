#include "String.h"
#include <iostream>


using namespace std;


int main() {
	String frst = "clock";
	String scnd = " wise:";
	String thrd = frst + scnd; 
	cout << thrd << '\t' << thrd.get_length() << endl;
	return 0;
}