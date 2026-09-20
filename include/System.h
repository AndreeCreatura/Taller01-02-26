#pragma once
#include <string>


class System {
    public:
    virtual void loadPatients(std::string filePath) = 0;
    virtual std::string attendPatients(int amount) = 0;
    virtual std::string showServices() = 0;
    virtual std::string showHistory() = 0;

    virtual std::string showWaiting() = 0;

    virtual std::string showServicePatients(int index) = 0;

    virtual ~System() = default;


};