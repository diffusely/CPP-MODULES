#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << "str address:" << &str << "\n";
	std::cout << "ptr address:" << ptr << "\n";
	std::cout << "ref address:" << &ref << "\n";

	std::cout << "str value:" << str << "\n";
	std::cout << "ptr value:" << *ptr << "\n";
	std::cout << "ref value:" << ref << "\n";

	return 0;
}