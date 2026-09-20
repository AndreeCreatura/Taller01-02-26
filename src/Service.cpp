#include "Service.h"
#include "PatientList.h"
#include <string>
using namespace std;

Service::Service(string name) {
    this->name = name;
    this->patients = new PatientList();
}

Service::~Service() {
    delete patients;
}

bool Service::addPatient(Persona* patient) {

    return patients->addPatient(patient);

}

PatientList* Service::getPatients() {
    return this->patients;
}

string Service::getName() {
    return this->name;
}