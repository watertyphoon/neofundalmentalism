#include "/public/read.h" //Provides read() and readline()
#include <fstream>
#include <climits> //Provides INT_MIN and INT_MAX
#include <cctype> //Provides toupper() and isalpha()
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <sstream>
#include <iostream>
//#include <cstdint> //Provides uint64_t
using namespace std;

[[noreturn]] //Noreturn tells the compiler we're never coming back from this
void die() {
	cout << "BAD INPUT!\n";
	exit(EXIT_FAILURE);
}

int read_int(int min = INT_MIN, int max = INT_MAX) {
	if (min > max) die();
	cout << "Please enter an int:\n";
	int temp = 0;
	cin >> temp;
	if (!cin) die();
	if (temp < min) die();
	if (temp > max) die();
	return temp;
}

//Uwu-ify the string
//Replace all vowels with u, except u which gets replaced by w
//Only replace lower case vowels, ignore upper case vowels
//Thou -> Thuw, Because -> Bucawsu
void function1(string &str) {
	//YOU:
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == 'a' || str.at(i) == 'o' || str.at(i) == 'i' || str.at(i) == 'e') {
			str.at(i) = 'u';
		} else if (str.at(i) == 'u') {
			str.at(i) = 'w';
		}
	}
}

//"Function2" (actually function1 2.0)
//Same as function1 but with a const reference parameter so you can't change it but have to return it instead
//Ask yourself if there is a difference in running time between this and the one above?
string function1(const string &immutable_str) {
	string str = immutable_str;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == 'a' || str.at(i) == 'o' || str.at(i) == 'i' || str.at(i) == 'e') {
			str.at(i) = 'u';
		} else if (str.at(i) == 'u') {
			str.at(i) = 'w';
		}
	}
	return str; //Placeholder
}

//Return true if the passed in string is a palindrome, false otherwise
//A palindrome (like TACOCAT) is spelled the same way forwards and backwards
//Special restriction: you cannot use a standard library function or loops in doing this one
//The only thing from std:: you can use are the string member functions like .pop_back()
//YOU: Write my_reverse, do not touch function3()
string my_reverse(string &str, int end = -1, int start = 0) {
	//reverse(str.begin(), str.end());
	if (end == -1) {
		end = str.size() - 1;
	}
	if (end <= start) {
		return str;
	}
	swap(str.at(start), str.at(end));
	return my_reverse(str, start + 1, end - 1); //Placeholder
}

//Returns true or false if str is a palindrome
//This function is fine, you will actually need to write the function above instead
bool function3(const string &str) {
	string copy_str = str;
	return str == my_reverse(copy_str);
}

//Get the minimum value from a vector
int function4(const vector<int> &vec) {
	int min = INT_MAX;
	if (vec.empty()) {
		die();
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i) < min) {
			min = vec.at(i);
		}
	}
	return min; //Placeholder
}

//Sum a vector
int function5(const vector<int> &vec) {
	if (vec.empty()) {
		die();
	}
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum = sum + vec.at(i);
	}
	return sum; //Placeholder
}

//Returns true or false if year is a leap year or not
bool function6(int year) {
	if (year <= 0) {
		die();
	}
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	} else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
		return true;
	} else {
		return false;
	} //Placeholder
}

//Returns the current time, based on how many minutes past midnight it is
//If minutes == 0, it will return "12:00 AM"
//If minutes == 61, it will return "1:01 AM"
//If minutes == 1234, it will return "8:34 PM"
string function7(int minutes) {
	if (minutes < 0 || minutes >= 2400) {
		die();
	}
	ostringstream temp;
	int hour = minutes / 60;
	int min = minutes % 60;
	if (minutes == 0) {
		return "12:00 AM";
	} else if (hour > 12) {
		temp << hour - 12 << ":";
		if (min < 10) {
			temp << "0" << min << " PM";
		} else {
			temp << min << " PM";
		}
	} else if (hour == 12) {
		temp << hour << ":";
		if (min < 10) {
			temp << "0" <<  min << " PM";
		} else {
			temp << min << " PM";
		}
	} else {
		temp << hour << ":";
		if (min < 10) {
			temp << "0" << min << " AM";
		} else {
			temp << min << " AM";
		}
	}
	return temp.str();
}

//Pointer practice. Can't use [] operator or &, just pointer math and *
//Given an array that starts at begin and ends at one before end
// return the value at index index.
//Example: arr = {11,-22,7,40,85}
//function8(arr,arr+5,3) will return 40 because it is at index 3
//Die if index is out of range
int function8(int *begin, int *end, int index) {
	//YOU:
	if (index < 0) {
		die();
	}
	if (begin + index >= end) {
		die();
	}
	return *(begin + index); //Placeholder
}

//Pointer range practice
//Add up all values in the range between begin and end
//(End is outside the values to be included as usual)
//Cannot use accumulate function, must use a for loop with pointers
//Cannot use [] operator
int function9(int *begin, int *end) {
	int sum = 0;
	for (int *i = begin; i < end; i++) {
		sum += *i;
	}
	return sum; //Placeholder
}

//Count how much each letter appears in a file
//Uppercaseify all letters, and only count letters
//Return the result in a map, which has a key for each letter in the file
// and a value for that key equal to its count
map<char, int> function10(string filename) {
	map<char, int> my_map;
	//my_map['A']++; //Demo code on how to increase the count for the letter A
	//YOU: Open the file held in filename and read one character at a time
	//If it is a letter, uppercase it and increment its count in the map
	ifstream file(filename);
	char temp;
	while (file >> temp) {
		if (!isalpha(temp)) {
			continue;
		}
		temp = static_cast<char>(toupper(static_cast<unsigned char>(temp)));
		if (my_map.count(temp)) {
			my_map.at(temp)++;
		} else {
			my_map.emplace(temp, 1);
		}
	}
	return my_map;
}

int main() {
	cout << "Welcome to The Fundamentals 2.0! Let's Crush It Again! 🐂\n";
	cout << "1)  Uwu-ify a string (version 1)\n";
	cout << "2)  Uwu-ify a string (version 2)\n";
	cout << "3)  Detect a palindrome\n";
	cout << "4)  Minimum value in a vector\n";
	cout << "5)  Sum of a vector\n";
	cout << "6)  Leap Year\n";
	cout << "7)  Clock time\n";
	cout << "8)  Pointer Math\n";
	cout << "9)  Pointer Range based accumulate\n";
	cout << "10) Count Letters in a File\n";
	int choice = read_int(1, 10); //Pick which function to run
	string str_result;
	if (choice == 1)  {
		str_result = readline();
		function1(str_result);
	} else if (choice == 2)  {//lol was >=
		const string str = readline();
		str_result = function1(str);
	} else if (choice == 3)  {
		string str = readline();
		str_result = function3(str) ? "true" : "false";
	} else if (choice == 4)  {
		vector<int> vec;
		cout << "Enter numbers (0 to quit):\n";
		while (true) {
			int x = read();
			if (x) vec.push_back(x);
			else break;
		}
		str_result = to_string(function4(vec));
	} else if (choice == 5)  {
		vector<int> vec;
		cout << "Enter numbers (0 to quit):\n";
		while (true) {
			int x = read();
			if (x) vec.push_back(x);
			else break;
		}
		str_result = to_string(function5(vec));
	} else if (choice == 6)  {
		int year = read();
		str_result = function6(year) ? "true" : "false";
	} else if (choice == 7)  {
		int x = read("Enter how many minutes past midnight: \n");
		str_result = function7(x);
	} else if (choice == 8)  {
		int size = read("Enter the size of the array (min 2, max 200):\n");
		if (size <= 1 or size > 200) die();
		int *arr = new int[size];
		iota(arr, arr + size, 100); //Fills with 100, 101, 102, etc.
		int index = read("Enter the index of the array to read:\n");
		str_result = to_string(function8(arr, arr + size, index));
		delete[] arr;
	} else if (choice == 9)  {
		int size = read("Enter the size of the array (min 2, max 200):\n");
		if (size <= 1 or size > 200) die();
		int *arr = new int[size];
		int val = read("Enter the value to start iota with:\n");
		iota(arr, arr + size, val); //Fills with 100, 101, 102, etc.
		str_result = to_string(function9(arr, arr + size));
		delete[] arr;
	} else if (choice == 10) {
		string filename = read("Enter the filename to open:\n");
		auto my_map = function10(filename);
		for (const auto &val : my_map) {
			cout << val.first << " : " << val.second << endl;
		}
	} else die();
	cout << "The result is: " << str_result << endl;
}
