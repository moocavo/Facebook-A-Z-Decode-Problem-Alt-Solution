#include <iostream>
#include <string>
#include <stdlib.h>

bool lessThanSix(const char number);

int main() {

	std::string message;

	std::cout << "Enter valid encoded message: " << std::endl;
	std::cout << "\t >> ";

	std::cin >> message;
	
	int counter = 1;
	for (unsigned int i = 0; i < message.length()-1; ++i) {
		if (message.at(i) == '1' && message.at(i+1) != '0') { // if the current number is 1 and the next number is not 0, increment
			++counter;	
		}
		else if (message.at(i) == '2' && lessThanSix(message.at(i+1))) {
			// if current number is 2 and the next number is <= 6, then increment
			++counter;
		}
	}

	std::cout << "\nPossible encodings: " << counter << std::endl;
	return 0;

}

bool lessThanSix(const char number) {	

	// dumb c string
	char buf[2];
	buf[0] = number;
	buf[1] = '\0';
	// 
	
	if (atoi(buf) <= 6) return true;
	return false;
}
