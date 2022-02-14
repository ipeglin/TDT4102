
#include "std_lib_facilities.h"


int tilfeldig(){
	return 0 + (rand() % (51 + 1));
}

int main()
{
	cout << "Hello, World!\n";
	vector<int> number;
	for (int i = 0; i < 52; i++) {
		number.push_back(i);
	}

	cout << number[tilfeldig()] << endl;

	cout << "Lengde vektor:" << number.size() << endl;
	cout << 
	// cout << number.size() << endl;

	
}


