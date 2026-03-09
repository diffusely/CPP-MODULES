#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			std::cout << (char)(std::toupper(argv[i][j]));
		}
	}

	return 0;
}