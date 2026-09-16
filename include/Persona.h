#pragma once
#include <iostream>
#include <string>
using namespace std;


class Persona {
    private:
    int ID;
    string name;
    int age;

    public:
    Persona(int ID, string name, int age);
    int getID();
    string getName();
    int getAge();


    ~Persona();

    
};