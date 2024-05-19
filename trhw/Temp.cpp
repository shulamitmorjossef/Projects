//
// Created by Student on 9/4/2023.
//

#include "Temp.h"
#define ZERO 0
#define FIVE 5
#define TEN 10
#define THREE_H 300
#define SEVEN_H 700

Temp::Temp(char* name, long id, int senior, int num, char** nameOfPro, int sum): Worker(name,id,senior),
Teacher(name, id, senior,num, nameOfPro){
//This function is a constructor, it accepts parameters and initializes the variables accordingly
    sumOfHour = sum;
}

Temp::~Temp(){
//This function is a destructor
}
void Temp::print(){
//This function is a print function, it prints all the temp data
    cout<<"Name worker: " << this->getName()<< endl
        <<"   Type: temp(a substitute teacher)\n   ID: "<< this->getId()<<endl
        <<"   Seniority:"<< getSenior()<< endl
        <<"   Salary: "<< getSalary()<< endl;
    cout << "----------------------------------------------------\n";
}

float Temp::getSalary(){
//This function calculates the temp's salary
    float sal = ZERO;
    sal = sal + sumOfHour*THREE_H;
    if(getSenior()>FIVE && sumOfHour>TEN)
        sal = sal + SEVEN_H;
    return sal;
}