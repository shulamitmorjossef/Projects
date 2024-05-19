//
// Created by Student on 9/4/2023.
//

#ifndef TRHW_DEPUTY_H
#define TRHW_DEPUTY_H
#include "Tutor.h"

class Deputy : virtual public Tutor{
public:
    Deputy(char*, long, int, int, char**, char []);
    ~Deputy();                                        // The function declaration of the Deputy class
    void print();
    float getSalary();

};


#endif //TRHW_DEPUTY_H
