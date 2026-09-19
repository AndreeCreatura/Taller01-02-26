#include "QueuePatient.h"
#include "Persona.h"
using namespace std;


QueuePatient::QueuePatient() {
    this->front = nullptr;
    this->rear = nullptr;
    this->size = 0;
}

void QueuePatient::push(Persona* patient) {

    Node* n = new Node(patient);

    if (this->front == nullptr) {
        this->front = n;
        this->rear = n;
        size++;
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
        size++;

    }

}

Persona* QueuePatient::pop() {
    if (isEmpty()) {
        return nullptr;

    }
    Node* aux = this->front;
    Persona* p = aux->patient;

    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete aux;

    size--;


    return p;
    
}


bool QueuePatient::isEmpty() const {
    if (this->front == nullptr) {
        return true;
    } else { 
        return false;
    }
}

int QueuePatient::getSize() {
    return this->size;
}

string QueuePatient::showPatients() const {
    int position = 1;

    string output = "=== PACIENTES EN ESPERA ===\n";

    Node* current = front;

    if (isEmpty()) {
        output = "NO HAY PACIENTES EN ESPERA!\n";
        return output;
    }

    while (current != nullptr) {
        output += to_string(position) + ". ";
        Persona* p = current->patient;
        output += p->getID() + " - " + p->getName() + "\n";
        current = current->next;
        position++;
    }
    output += "\n";

    return output;

}

QueuePatient::~QueuePatient() {

    while(front != nullptr) {
        Node* aux = front;
        front = front->next;

        delete aux;

    }

    rear = nullptr;

}