#pragma once
#include <string>
#include "PatientList.h"
#include "Persona.h"
using namespace std;


class PatientList;
class Persona;

class Service {
    private:
    string name;
    PatientList* patients;

    public:
    Service(string name);
    ~Service();

    bool addPatient(Persona* patient);

};