/* 
 * Author: Alex Rosado
 *  Challenge 2
 * 
 * test hash to test its functionality
 */
#include "main.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    Data passedData;
    bool operationStatus;
    int testCounter = 0;
    int catchCounter = 0;
    int stackSize;

    if (argv[1]) {
        stackSize = std::stoi(argv[1]);
    } else {
        stackSize = VALID_STACKSIZE;
    }

    FIFO fifo;

    // Testing for pull() (EMPTY FIFO)
    std::cout << "- TESTING PULL WITH EMPTY FIFO-" << std::endl;
    for (int i = 0; i < stackSize; i++) {
        testCounter++;
        try {
            operationStatus = fifo.pull(passedData);
            std::cout << "Pull Operation Successful? : " << std::boolalpha << operationStatus << std::endl;
        } catch (...) {
            catchCounter++;
            std::cout << "Pull failed." << std::endl;
        }
    }
    std::cout << "PULL TEST COMPLETED " << std::endl;
    std::cout << std::endl;

    // Testing for push()
    std::cout << "- TESTING PUSH -" << std::endl;
    for (int i = 0; i < stackSize; i++) {
        testCounter++;
        int value = rand() % TESTVALUE3 + LOWERBOUND;
        std::string strtemp = std::to_string(value);  // generate random string based on value
        try {
            operationStatus = fifo.push(value, strtemp);
            std::cout << "Pushed ID: " << value << ", Data: " << strtemp 
                      << ". Operation Successful? : " << std::boolalpha << operationStatus << std::endl;
        } catch (...) {
            catchCounter++;
            std::cout << "Push failed." << std::endl;
        }
    }
    std::cout << "- PUSH TEST COMPLETED -" << std::endl;
    std::cout << std::endl;

  // Testing for pull() (FILLED FIFO)
    std::cout << "- TESTING PULL WITH FILLED FIFO-" << std::endl;
    for (int i = 0; i < stackSize; i++) {
        testCounter++;
        try {
            operationStatus = fifo.pull(passedData);
            std::cout << "Pull Operation Successful? : " << std::boolalpha << operationStatus << std::endl;
        } catch (...) {
            catchCounter++;
            std::cout << "Pull failed." << std::endl;
        }
    }
    std::cout << "- PULL TEST COMPLETED -" << std::endl;
    std::cout << std::endl;

    // Test FIFO isEmpty() functionality
    std::cout << "- TESTING FIFO IS EMPTY -" << std::endl;
    std::cout << "Is FIFO Empty? : " << std::boolalpha << fifo.isEmpty() << std::endl;
    std::cout << "- IS EMPTY TEST COMPLETED -" << std::endl;
    std::cout << std::endl;

    return 0;
  }
