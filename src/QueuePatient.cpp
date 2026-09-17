#include "QueuePatient.h"
#include "Persona.h"
using namespace std;


QueuePatient::QueuePatient() {
    this->front = nullptr;
    this->rear = nullptr;
}

void QueuePatient::push(Persona* patient) {

    Node* n = new Node(patient);

    if (this->front == nullptr) {
        this->front = n;
        this->rear = n;
    } else {
        
        
        /*
        Node* ptr = front;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        ptr->next = n;
        [Recorre manualmente la cola]
        */

        rear->next = n;
        rear = n;

    }

}

Persona* QueuePatient::pop() {
    if (isEmpty()) {
        return nullptr;

    }
    Node* aux = this->front;
    Persona* p = aux->patient;

    front = front->next;

    delete aux;

    if (front == nullptr) {
        rear = nullptr;
    }

    return p;
    
}


bool QueuePatient::isEmpty() {
    if (this->front == nullptr) {
        return true;
    } else { 
        return false;
    }
}

QueuePatient::~QueuePatient() {

    while(front != nullptr) {
        Node* aux = front;
        front = front->next;

        delete aux;

    }

}