//
// Created by Student on 9/4/2023.
//

#ifndef TRHW_SECRETARY_H
#define TRHW_SECRETARY_H
#include "Worker.h"

class Secretary : virtual public Worker{
private:
    int extraHour;                           // Creating the variables of the Secretary class
public:
    Secretary(char*, long, int, int);
    ~Secretary();
    void print();                            // The function declaration of the Secretary class
    float getSalary();
};


#endif //TRHW_SECRETARY_H
