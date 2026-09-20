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
    PatientList* getPatients();
    std::string getName();


};