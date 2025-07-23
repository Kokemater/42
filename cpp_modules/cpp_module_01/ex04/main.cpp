#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void replaceAll(std::string &content, std::string s1, std::string s2)
{
    size_t pos = 0;
    while((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "BAD USAGE, please try: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::fstream infile(filename.c_str(), std::ios::in);
    if (!infile) {
        std::cout << "ERROR IN THE OPENING OF THE FILE '" << filename << "' " << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();

    replaceAll(content, s1, s2);
    std::cout << content;

    std::fstream outfile(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!outfile) {
        std::cout << "ERROR IN THE OPENING OF THE FILE '" << filename << "' " << std::endl;
        return 1;
    }
    outfile << content;
    outfile.close();

    return 0;
}
