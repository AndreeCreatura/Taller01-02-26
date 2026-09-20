#pragma once
#include <string>
#include "PatientList.h"


class PatientList;
class Persona;

class Service {
    private:
    std::string name;
    PatientList* patients;

    public:
    Service(std::string name);
    ~Service();

    bool addPatient(Persona* patient);
    int getPatientCount();
    std::string showPatients();
    bool hasPatients();
    std::string getName();


};