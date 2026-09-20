#pragma once
#include <string>
#include "ServiceList.h"
#include "Service.h"
#include "StackHistory.h"

class ServiceList;
class Service;
class StackHistory;

class Hospital {

    private:
    ServiceList* services;
    StackHistory* history;


    public:
    Hospital();
    ~Hospital();

    ServiceList* getServiceList();

    Service* findService(std::string name);

    void registerAttention(Persona* patient);

    std::string showServices();

    StackHistory* getHistory();


};