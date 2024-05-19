//
// Created by Student on 9/5/2023.
//

#ifndef TRHW_SCHOOL_H
#define TRHW_SCHOOL_H
#include "Worker.h"
#include "Teacher.h"
#include "Temp.h"
#include "Tutor.h"
#include "Manager.h"
#include "Secretary.h"
#include "Deputy.h"

class School {
private:
    int sumOfWorker;
    Worker** employs;                    // Creating the variables of the School class
    bool managerExist;
public:
    School();
    ~School();
    void menu();
    void addWorker();
    void printWorkers();
    void printProfession();
    void printTutors();
    void printManagement();                // The function declaration of the School class
    bool checkId(int);
    bool checkTutor(char[FOUR]);
    void updateArray(Worker*);

};


#endif //TRHW_SCHOOL_H
