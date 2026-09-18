#pragma once
#include <string>
#include "Service.h"
using namespace std;

class Service;

class ServiceList {

    private:

    struct Node {
        Service* service;
        Node* next;

        Node(Service* s) {
            service = s;
            next = nullptr;
        }
    };

    Node* head;
    int size;


    public:
    ServiceList();
    ~ServiceList();

    void add(Service* service);
    Service* find(string name);

    Service* findByIndex(int index);

    string showServices();

    bool isEmpty();
};