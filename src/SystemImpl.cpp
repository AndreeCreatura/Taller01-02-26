#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "System.h"
#include "SystemImpl.h"
using namespace std;

SystemImpl::SystemImpl() {
    this->patientQueue = new QueuePatient();
}

void SystemImpl::loadPatients(string filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cout << "File not found!" << std::endl;
        return;
    }
    

    std::string line;

    while(std::getline(file, line)) { 
        std::cout << line << std::endl;

        stringstream ss(line);

        string idTxt;
        string name;
        string ageTxt;
        string service;

        if (!getline(ss, idTxt, ';') || !getline(ss, name, ';') || !getline(ss, ageTxt, ';') || !getline(ss, service, ';')) {
            cout << "Invalid line: " << line << endl;
            continue;
        }

        string extra;

        if (getline(ss, extra, ';')) {
            cout << "Invalid line: " << line << endl;
            continue;
        }

        int age;
        int id;

        try {
            age = stoi(ageTxt);
            id = stoi(idTxt);

            if (age < 0) {
                cout << "Invalid Age: " << line << endl;
                continue;

            }
        }
        catch (invalid_argument) {
            cout << "Invalid Age or ID: " << line << endl;
            continue;
        }

        Persona* p = new Persona(id, name, age, service);
        patientQueue->push(p);


    }

    cout << patientQueue->showPatients() << endl;


}

SystemImpl::~SystemImpl() {

}

void SystemImpl::attendPatients(int amount) {

}


void SystemImpl::showServices() {

}

void SystemImpl::showHistory() {

}



void SystemImpl::run() {

}
