#include <fstream>
#include <iostream>
#include <sstream>

int change(std::stringstream &buffer, const std::string &from,
        const std::string &to)
{
    if (from.empty()) {
        std::cerr << "Error: string to replace cannot be empty\n";
        return 1;
    }

    std::string input = buffer.str();
    std::string result;

    size_t i = 0;
    while (i < input.length()) {
        if (input.compare(i, from.length(), from) == 0) {
            result += to;
            i += from.length();
        }
        else {
            result += input[i];
            i++;
        }
    }

    buffer.str("");
    buffer.clear();
    buffer << result;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <old_str> <new_str>\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Error: Failed to open file '" << argv[1] << "'\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << in.rdbuf();
    in.close();

    if (change(buffer, argv[2], argv[3]) != 0)
        return 1;

    std::string outFile = std::string(argv[1]) + ".replace";
    std::ofstream out(outFile.c_str());
    if (!out) {
        std::cerr << "Error: Failed to create output file '" << outFile << "'\n";
        return 1;
    }

    out << buffer.str();
    out.close();

    return 0;
}