#pragma once
#include <string>
using namespace std;


class System {
    public:
    virtual void loadPatients(string filePath) = 0;
    virtual void attendPatients(int amount) = 0;
    virtual void showServices() = 0;
    virtual void showHistory() = 0;

    virtual ~System() = default;


};