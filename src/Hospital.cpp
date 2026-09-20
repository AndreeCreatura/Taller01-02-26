#include <string>
#include "Hospital.h"
using namespace std;



Hospital::Hospital() {
    this->services = new ServiceList();
    this->history = new StackHistory();
    services->add("Urgencias");
    services->add("Medicina General");
    services->add("Cardiologia");
    services->add("Neurologia");
    services->add("Traumatologia");
    services->add("Cirugia");
    services->add("Pediatria");
    services->add("Hospitalizacion");

}

string Hospital::showServices() {
    return this->services->showServices();
}

Service* Hospital::findService(string name) {
    Service* s = services->find(name);
    if (s == nullptr) {
        return nullptr;
    } else return s;

}

void Hospital::registerAttention(Persona* patient) {
    Attention* a = new Attention(patient->getID(), patient->getName(), patient->getAge(), patient->getService());
    history->push(a);

}


Service* Hospital::findServiceByIndex(int index) {
    return services->findByIndex(index);
}

string Hospital::showAttentions() {
    return history->showAttentions();
}



Hospital::~Hospital() {

    delete history;
    delete services;
    
}