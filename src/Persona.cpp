#include "Persona.h"
using namespace std;


Persona::Persona(int ID, string name, int age, string service) {
    this->ID = ID;
    this->name = name;
    this->age = age;
    this->service;
}

int Persona::getID() {
    return this->ID;
}

int Persona::getAge() {
    return this->age;
}

string Persona::getName() {
    return this->name;
}

string Persona::getService() {
    return this->service;
}

Persona::~Persona() {

}


