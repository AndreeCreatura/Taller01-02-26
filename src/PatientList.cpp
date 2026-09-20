#include "PatientList.h"
#include "Persona.h"
#include <string>
using namespace std;

PatientList::PatientList() {
    this->head = nullptr;
    this->size = 0;
}

PatientList::~PatientList() {
    Node* current = head;
    while (current != nullptr) {
        Node* aux = head;
        head = head->next;

        delete aux->patient;
        delete aux;

    }
}

bool PatientList::addPatient(Persona* p) {

    Node* n = new Node(p);

    if (isEmpty()) {
        this->head = n;
        size++;
        return true;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = n;
    size++;
    return true;

}

string PatientList::showPatients() {
    string output = "";

    if (isEmpty()) {
        return "No hay pacientes registrados en el servicio establecido";
    }

    Node* current = head;

    while (current != nullptr) {
        output += current->patient->getName() + " (" + to_string(current->patient->getAge()) + ")\n";
        current = current->next;
    }

    return output;

}

int PatientList::getSize() {
    return this->size;
}

bool PatientList::isEmpty() {
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}