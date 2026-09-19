#pragma once
#include <string>

class Attention {

    private:
    std::string ID;
    std::string name;
    int age;
    std::string service;

    public:
    Attention(std::string id, std::string name, int age, std::string service);

    std::string getId();
    std::string getName();
    int getAge();
    std::string getService();

    std::string toString();

    ~Attention();

};