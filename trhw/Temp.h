//
// Created by Student on 9/4/2023.
//

#ifndef TRHW_TEMP_H
#define TRHW_TEMP_H
#include "Teacher.h"
class Temp : virtual public Teacher {
private:
    int sumOfHour;                                  // Creating the variables of the Temp class
public:
    Temp(char*, long, int, int, char**, int);
    ~Temp();                                        // The function declaration of the Temp class
    void print();
    float getSalary();

};


#endif //TRHW_TEMP_H
