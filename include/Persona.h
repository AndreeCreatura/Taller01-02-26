#pragma once
#include <iostream>
#include <string>
using namespace std;


class Persona {
    private:
    int ID;
    string name;
    int age;
    string service;

    public:
    Persona(int ID, string name, int age, string service);
    int getID();
    string getName();
    int getAge();
    string getService();


    ~Persona();

    
};