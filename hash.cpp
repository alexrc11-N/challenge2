/* 
 * Author: Alex Rosado
 *  challenge 2
 *  
 *This file provides the implementation for the FIFO class defined in fifo.h.
 * It includes the constructor and destructor for the FIFO class, and definitions for 
 * operations such as push, pull, peek, and checking if the queue is empty.
 * 
 */
#include "hash.h"

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
    if (!head) {
        return false;
    }

    passedData = head->data;
    Node* oldHead = head;
    head = head->next;
    delete oldHead;

    if (!head) {
        tail = nullptr;
    }

    return true;
}

bool FIFO::peek(Data& passedData) const {
    if (!head) {
        return false;
    }

    passedData = head->data;
    return true;
}

bool FIFO::isEmpty() const {
    return !head;
}
