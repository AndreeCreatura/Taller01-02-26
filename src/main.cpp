#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main() {

    std::ifstream file("data/pacientes.txt");

    if (!file.is_open()) {
        std::cout << "File not found!" << std::endl;
        return 1;
    }
    

    std::string line;

    while(std::getline(file, line)) { 
        std::cout << line << std::endl;
    }

    file.close();


    std::cout << "Hello World" << std::endl;

    return 0;
}