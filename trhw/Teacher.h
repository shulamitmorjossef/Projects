//
// Created by Student on 9/3/2023.
//

#ifndef TRHW_TEACHER_H
#define TRHW_TEACHER_H
#include "Worker.h"
#include <cstring>


class Teacher : virtual public Worker{
private:
    int numOfProfessions;                             // Creating the variables of the Teacher class
    char** nameOfProfessions;
public:
    Teacher(char*, long, int, int, char**);
    ~Teacher();
    Teacher(const Teacher&);
    Teacher& operator=(const Teacher&);                  // The function declaration of the Teacher class
    void print();
    float getSalary();
    int getNumOfProfessions()const;
    char** getNameOfSubjects()const;

};


#endif //TRHW_TEACHER_H
