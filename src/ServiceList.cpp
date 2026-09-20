#include "ServiceList.h"
#include "Service.h"
#include <string>
using namespace std;

ServiceList::ServiceList() {
    this->head = nullptr;
    this->size = 0;
}

void ServiceList::add(string name) {
    Service* s = new Service(name);
    Node* n = new Node(s);

    if (isEmpty()) {
        this->head = n;
        size++;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = n;
    size++;

}

Service* ServiceList::find(string name) {

    Node* current = head;

    while (current != nullptr) {
        if (current->service->getName() == name) {
            return current->service;
        }

        current = current->next;
    }


    return nullptr;

}

string ServiceList::showServices() {
    string output = "";

    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        output += to_string(position) + ". " + current->service->getName() + "\n";

        current = current->next;
        position++;
    }



    return output;

}

Service* ServiceList::findByIndex(int index) {

    if (index <= 0) return nullptr;
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (position == index) {
            return current->service;
        }

        current = current->next;
        position++;
    }

    return nullptr;

}

bool ServiceList::isEmpty() {
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
    }
}

ServiceList::~ServiceList() {
    while(head != nullptr) {
        Node* aux = head;
        head = head->next;

        delete aux->service;
        delete aux;

    }

}

