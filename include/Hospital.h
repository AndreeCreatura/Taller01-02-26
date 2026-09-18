#pragma once
#include <string>
#include "ServiceList.h"
#include "Service.h"
using namespace std;

class ServiceList;
class Service;

class Hospital {

    private:
    ServiceList* services;

    public:
    Hospital();
    ~Hospital();

    Service* findService(string name);


};