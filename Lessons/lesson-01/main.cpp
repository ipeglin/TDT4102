
#include "std_lib_facilities.h"

using namespace std; // Use std lib globally. This eliminates the need for std::cout

int main()
{
	int my_number{15}; // Integer
	char my_char{'A'}; // Single character
	double my_double{43.7}; // Decimal point number
	bool is_finished{true}; // Boolean
	string my_str{"Welcome!"}; // String

	// Using the variables
	cout << my_str << "You have chosen the following:" << endl;
	cout << "Number: " << my_number << " Double: " << my_double << endl;
	cout << "Character: " << my_char << " Is this script finished? " << is_finished << endl;

	return 0;
}
