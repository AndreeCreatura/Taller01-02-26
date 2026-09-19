#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "System.h"
#include "SystemImpl.h"
using namespace std;

bool isNumber(const string& str) {
    if (str.empty()) {
        return false;
    }
    for (char c : str) {
        if(!isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;

}



int main() {

    System* system = new SystemImpl();

    string file = "data/pacientes.txt";

    system->loadPatients(file); // Abrira siempre desde data, para probar algun txt ponga siempre el directorio correcto

    int totalOp = 1;
    int option;
    string input = "";

    bool menu = true;

    do {

        cout << "-------------------- Opcion " << to_string(totalOp) << " --------------------" << endl;

        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender Pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;

        cout << endl;

        cout << "Seleccionar opcion: ";

        getline(cin, input);

        cout << endl;

        if (!isNumber(input)) {
            cout << "Error de formato! Ingrese un numero valido";
            continue;
        }

        try {

            option = stoi(input);
        }
        catch (const out_of_range&) {
            cout << "Numero demasiado grande." << endl;
            continue;
        }

        switch (option) {

        case 1: {
            int amount;

            cout << system->showWaiting() << endl;

            cout << "Ingrese numero de pacientes a atender: ";
            getline(cin, input);
            cout << endl;

            while (!isNumber(input)) {
                cout << "Valor invalido. Ingrese un valor valido: " << endl;
                getline(cin, input);
                cout << endl;

            }

            try {
                amount = stoi(input);
            }
            catch (const out_of_range&) {
                cout << "Numero demasiado grande." << endl;
                continue;
            }

            if (amount <= 0) {
                cout << "Debe atender al menos un paciente." << endl;
                break;
            }

            system->attendPatients(amount);
            totalOp++;
            break;
        }

        case 2:
            system->showServices();
            totalOp++;
            break;

        case 3:
            system->showHistory();
            totalOp++;
            break;

        case 4:
            menu = false;
            cout << "BYE-BYE!" << endl;
            break;
        
        default:
            cout << "Inavlido! Seleccione una opcion entre el 1 y el 4." << endl;
            break;
        }

    } while (menu);

    delete system;
    system = nullptr;

    


    return 0;
}