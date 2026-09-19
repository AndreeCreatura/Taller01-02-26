#include "Attention.h"
#include <string>
using namespace std;

Attention::Attention(string id, string name, int age, string service) {

    this->ID = id;
    this->name = name;
    this->age = age;
    this->service = service;

}

string Attention::getId() { 
    return this->ID;
}

string Attention::getName() {
    return this->name;
}

int Attention::getAge() {
    return this->age;
}

string Attention::getService() {
    return this->service;
}

string Attention::toString() {
    return "Nombre: " + this->name + " | Edad: " + to_string(this->age) + " | Departamento: " + this->service;
}

Attention::~Attention() {
        
}