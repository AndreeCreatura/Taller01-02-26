#pragma once
#include <iostream>
#include <string>
using namespace std;


class Persona {
    private:
    string ID;
    string name;
    int age;
    string service;

    public:
    Persona(string ID, string name, int age, string service);
    string getID();
    string getName();
    int getAge();
    string getService();


    ~Persona();

    
};