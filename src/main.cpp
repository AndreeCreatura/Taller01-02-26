#include <iostream>
#include <string>
#include <fstream>
#include "System.h"
#include "SystemImpl.h"
using namespace std;










int main() {

    System* system = new SystemImpl();

    string file = "data/pacientes.txt";

    system->loadPatients(file); // Abrira siempre desde data

    std::cout << "Hello World" << std::endl;

    
    return 0;
}