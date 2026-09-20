#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "System.h"
#include "QueuePatient.h"
#include "Hospital.h"
#include "SystemImpl.h"
using namespace std;

SystemImpl::SystemImpl() {
    this->patientQueue = new QueuePatient();
    this->hospital = new Hospital();
}

string SystemImpl::showWaiting() {
    return this->patientQueue->showPatients();
}

bool SystemImpl::checkDuplicate(string id) {
    Persona* p = patientQueue->find(id);
    if (p == nullptr) {
        return false;
    } else {
        return true;
    }
}

void SystemImpl::loadPatients(string filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cout << "File not found!" << std::endl;
        return;
    }
    

    std::string line;

    while(std::getline(file, line)) { 

        stringstream ss(line);

        string id;
        string name;
        string ageTxt;
        string service;

        if (!getline(ss, id, ';') || !getline(ss, name, ';') || !getline(ss, ageTxt, ';') || !getline(ss, service, ';')) {
            cout << "Invalid line: " << line << endl;
            continue;
        }

        string extra;

        if (getline(ss, extra, ';')) {
            cout << "Invalid line: " << line << endl;
            continue;
        }

        if (id.empty() || name.empty() || ageTxt.empty() || service.empty()) {
            cout << "Invalid line: " << line << endl;
        }

        int age;

        try {
            age = stoi(ageTxt);

            if (age < 0) {
                cout << "Invalid Age: " << line << endl;
                continue;

            }
        }
        catch (const invalid_argument&) {
            cout << "Invalid Age: " << line << endl;
            continue;
        }
        catch (const out_of_range&) {
            cout << "Age out of range: " << line << endl;
            continue;
        }

        Service* s = hospital->findService(service);

        if (s == nullptr) {
            cout << "Invalid Service: " << service << endl;
            continue;
        }

        if (checkDuplicate(id)) {
            cout << "Duplicated patient ID: " << id << endl;
            continue;
        }

        Persona* p = new Persona(id, name, age, service);

        patientQueue->push(p);


    }


}

SystemImpl::~SystemImpl() {
    delete patientQueue;
    delete hospital;

}

string SystemImpl::attendPatients(int amount) {
    string output;
    if (amount > patientQueue->getSize()) {
        output += "No se pudo realizar la operacion. La cantidad ingresada es mayor al numero de pacientes.";
        return output;
    }


    for (int i = 0; i < amount; i++) {
        if (patientQueue->isEmpty()) {
            output += "No quedan pacientes en espera.\n";
            return output;
        }

        Persona* patient = patientQueue->pop();

        Service* service = hospital->findService(patient->getService());

        if (service == nullptr) {
            output += "Hubo un error en el manejo del servicio del paciente " + patient->getName() + ".\n";
            delete patient;
            continue;
        }

        if (!service->addPatient(patient)) {
            output += "No se pudo agregar al paciente al servicio.\n";

            continue;

        }

        hospital->registerAttention(patient);

        output += "ID: " + patient->getID() + "\n";
        output += "Nombre: " + patient->getName() + "\n";
        output += "Edad: " + to_string(patient->getAge()) + "\n";
        output += "Servicio: " + patient->getService() + "\n\n";
        output += "Paciente enviado a " + patient->getService() + ".\n\n";
        
    }

    return output;
    

}


string SystemImpl::showServices() {

    return hospital->showServices();

}

string SystemImpl::showHistory() {
    return hospital->showAttentions();

}

string SystemImpl::showServicePatients(int index) {
    string output = "";
    Service* s = hospital->findServiceByIndex(index);
    if (s == nullptr) {
        output = "Error en la validacion de servicio";
        return output;
    }

    output += "=== ESTADO DE " + s->getName() + " ===\n";
    if (s->hasPatients()) {
        output += "No hay pacientes en el departamento de " + s->getName() + ".\n";
    } else {
        output += "Pacientes en el departamento de " + s->getName() + ": " + to_string(s->getPatientCount()) + "\n";
        output += s->showPatients();
    }


    return output;

}


