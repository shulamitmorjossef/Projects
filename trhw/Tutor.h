//
// Created by Student on 9/4/2023.
//

#ifndef TRHW_TUTOR_H
#define TRHW_TUTOR_H
#include "Teacher.h"
#define FOUR 4

class Tutor : virtual public Teacher{
private:
    char clas[FOUR];                                  // Creating the variables of the Tutor class
public:
    Tutor(char*, long, int, int, char**, char []);
    Tutor(const Tutor&);
    ~Tutor();                                        // The function declaration of the Tutor class
    void print();
    float getSalary();
    virtual const char* getClas() ;

};


#endif //TRHW_TUTOR_H
