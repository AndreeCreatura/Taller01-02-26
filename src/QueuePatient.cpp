#include "QueuePatient.h"
#include "Persona.h"
using namespace std;


QueuePatient::QueuePatient() {
    this->front == nullptr;
}

void QueuePatient::push(Persona* patient) {

    Node* n = new Node(patient);

    if (this->front == nullptr) {
        this->front = n;
    } else {
        Node* ptr = front;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        ptr->next = n;
    }

}

Persona* QueuePatient::pop() {
    Node* aux = this->front;
    Persona* p = aux->patient;

    front = front->next;

    delete aux;

    return p;
    
}


bool QueuePatient::isEmpty() {
    if (this->front == nullptr) {
        return true;
    } else { 
        return false;
    }
}