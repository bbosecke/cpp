#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

int main()
{
    std::string line;
    std::ifstream file("test.txt");

    if(!file.is_open()){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while(std::getline(file, line)){
        cout << line << endl;
    }

    return 0;
}