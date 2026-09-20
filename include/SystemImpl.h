#pragma once

#include <string>
#include "System.h"
#include "QueuePatient.h"
#include "Hospital.h"

class SystemImpl : public System {
    private:
    QueuePatient* patientQueue;
    Hospital* hospital;
    bool checkDuplicate(std::string id);
    bool parseLine(const std::string& line, std::string& id, std::string& name, std::string& age, std::string& service);



    public:
    SystemImpl();
    ~SystemImpl();

    std::string showWaiting() override;

    void loadPatients(std::string filePath) override;
    std::string attendPatients(int amount) override;
    std::string showServices() override;
    std::string showHistory() override;
    std::string showServicePatients(int index) override;

};