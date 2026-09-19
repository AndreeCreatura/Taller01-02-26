#pragma once

#include <string>
#include "System.h"
#include "QueuePatient.h"
#include "Hospital.h"

class SystemImpl : public System {
    private:
    QueuePatient* patientQueue;
    Hospital* hospital;



    public:
    SystemImpl();
    ~SystemImpl();

    std::string showWaiting() override;

    void loadPatients(std::string filePath) override;
    void attendPatients(int amount) override;
    void showServices() override;
    void showHistory() override;

};