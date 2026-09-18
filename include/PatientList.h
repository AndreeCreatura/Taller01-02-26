#pragma once
#include <string>
#include "Persona.h"
using namespace std;

class Persona;


class PatientList {

    private:
    struct Node {
         Persona* patient;
         Node* next;

         Node(Persona* p) {
            patient = p;
            next = nullptr;
         }
    };

    Node* head;

    public:
    PatientList();
    ~PatientList();

    bool addPatient(Persona* p);

    Persona* find(string id);

    string showPatients();

    bool isEmpty();

};