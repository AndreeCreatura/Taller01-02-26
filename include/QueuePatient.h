#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

class Persona; // Definir clases (De lo contrario el programa perece)

class QueuePatient {

    private:
    struct Node {
        Persona* patient;
        Node* next;

        Node(Persona* p) {
            patient = p;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;
    int size;

    public:
    QueuePatient();
    void push(Persona* patient);
    Persona* pop();
    bool isEmpty();
    int getSize();

    ~QueuePatient();


};