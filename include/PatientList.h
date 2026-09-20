#pragma once
#include <string>
#include "Persona.h"

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
    int size;

    public:
    PatientList();
    ~PatientList();

    bool addPatient(Persona* p);

    // Persona* find(std::string id);

    std::string showPatients();

    int getSize();

    bool isEmpty();

};