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

int Service::getPatientCount() {
    return patients->getSize();
}

bool Service::hasPatients() {
    return !patients->isEmpty();
}

string Service::showPatients() {
    return patients->showPatients();
}

string Service::getName() {
    return this->name;
}