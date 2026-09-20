#pragma once

#include <string>
#include "Attention.h"


class Attention;

class StackHistory {
    private:

    struct Node {
        Attention* attention;
        Node* next;

        Node(Attention* a) {
            attention = a;
            next = nullptr;
        }
    };

    Node* top;

    public:
    StackHistory();
    ~StackHistory();

    bool isEmpty();
    void push(Attention* a);
    Attention* pop();

    std::string showAttentions();
};