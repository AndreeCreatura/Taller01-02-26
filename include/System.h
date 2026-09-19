#pragma once
#include <string>


class System {
    public:
    virtual void loadPatients(std::string filePath) = 0;
    virtual void attendPatients(int amount) = 0;
    virtual void showServices() = 0;
    virtual void showHistory() = 0;

    virtual std::string showWaiting() = 0;

    virtual ~System() = default;


};