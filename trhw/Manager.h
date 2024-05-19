//
// Created by Student on 9/4/2023.
//

#ifndef TRHW_MANAGER_H
#define TRHW_MANAGER_H
#include "Worker.h"

class Manager : virtual public Worker{
public:
    Manager(char*, long, int);
    ~Manager();                                // The function declaration of the Manager class
    void print();
    float getSalary();
};


#endif //TRHW_MANAGER_H
