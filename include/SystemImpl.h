#pragma once
#include <string>
#include "System.h"
#include "QueuePatient.h"
using namespace std;

class SystemImpl : public System {
    private:
    QueuePatient* patientQueue;



    public:
    SystemImpl();
    ~SystemImpl();

    void loadPatients(string filePath) override;
    void attendPatients(int amount) override;
    void showServices() override;
    void showHistory() override;

    void run();

};