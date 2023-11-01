/* 
 * Author: Alex Rosado
 *  challenge 2
 *  
 *This file provides the implementation for the FIFO class defined in fifo.h.
 * It includes the constructor and destructor for the FIFO class, and definitions for 
 * operations such as push, pull, peek, and checking if the queue is empty.
 * 
 */
#include "fifo.h"

FIFO::FIFO() : head(nullptr), tail(nullptr) {}

FIFO::~FIFO() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool FIFO::push(int id, const std::string& data) {
    Node* newNode = new Node{ {id, data}, nullptr };

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

bool FIFO::pull(Data& passedData) {
    bool result = false; 

    if (head) {
        passedData = head->data;
        Node* oldHead = head;
        head = head->next;
        delete oldHead;

        if (!head) {
            tail = nullptr;
        }

        result = true; 
    }

    return result;
}


bool FIFO::peek(Data& passedData) const {
    bool result = false; 

    if (head) {
        passedData = head->data;
        result = true; 
    }

    return result;
}


bool FIFO::isEmpty() const {
    return !head;
}
