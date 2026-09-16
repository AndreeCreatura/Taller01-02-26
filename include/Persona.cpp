#include "Persona.h"
using namespace std;


Persona::Persona(int ID, string name, int age) {
    this->ID = ID;
    this->name = name;
    this->age = age;
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

Persona::~Persona() {

}


