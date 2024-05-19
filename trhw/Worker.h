//
// Created by Student on 9/3/2023.
//

#ifndef TRHW_WORKER_H
#define TRHW_WORKER_H
#include <iostream>
#include <cstring>
using namespace std;

class Worker {
private:
    char* name;
    long id;                              // Creating the variables of the Worker class
    int seniority;
public:
    Worker(const char*, long, int);
    Worker(const Worker&);
    virtual ~Worker();
    virtual void print()=0;
    virtual float getSalary()=0;
    void setId(long);
    void setSeniority(int);                // The function declaration of the Worker class
    char* getName()const;
    long getId()const;
    int getSenior()const;

};


#endif //TRHW_WORKER_H
