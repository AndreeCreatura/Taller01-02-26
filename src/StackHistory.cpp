#include "StackHistory.h"
#include "Attention.h"
#include <string>
using namespace std;

StackHistory::StackHistory() {
    this->top = nullptr;
}

StackHistory::~StackHistory() {
    while(top != nullptr) {
        Node* aux = top;
        top = top->next;

        delete aux->attention;
        delete aux;

    }

}

bool StackHistory::isEmpty() {
    if (top == nullptr) {
        return true;
    } else {
        return false;
    }
}

void StackHistory::push(Attention* a) {
    Node* n = new Node(a);

    if (top == nullptr) {
        top = n;
    } else {
        n->next = top;
        top = n;
    }

}

Attention* StackHistory::pop() {
    if (isEmpty()) {
        return nullptr;

    }
    Node* aux = this->top;
    Attention* a = aux->attention;

    top = top->next;

    delete aux;

    return a;
}

string StackHistory::showAttentions() {
    string output = "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===\n\n";

    if (isEmpty()) {
        output += "No hay registro de atencion.\n";
        return output;
    }

    Node* current = top;
    while (current != nullptr) {
        output += current->attention->toString() + "\n";
        current = current->next;
    }

    output += "\n";
    return output;

}