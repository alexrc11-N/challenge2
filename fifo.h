/* 
 * Author: Alex Rosado
 *  challenge 2
 * 
 *This file contains the structure definition for storing data, a node definition for the linked list,
 * and a class definition for the FIFO data structure. The FIFO class provides basic functionalities such as 
 * push, pull, peek, and check if the queue is empty.
 * 
 */
#ifndef FIFO_H
#define FIFO_H

#include <string>

// Data structure
struct Data {
    int id;
    std::string information;
};

// Node for linked list
struct Node {
    Data data;
    Node* next;
};

class FIFO {
public:
    FIFO();
    ~FIFO();

    bool push(int id, const std::string& data);
    bool pull(Data& passedData);
    bool peek(Data& passedData) const;
    bool isEmpty() const;

private:
    Node* head;
    Node* tail;
};

#endif // FIFO_H
