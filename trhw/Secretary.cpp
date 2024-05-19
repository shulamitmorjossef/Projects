//
// Created by Student on 9/4/2023.
//

#include "Secretary.h"
#define SIXTY 60
#define TWO_H 200
#define FIVE_T 5000
Secretary::Secretary(char* name, long id, int senior, int extraHours): Worker(name,id,senior){
//This function is a constructor, it accepts parameters and initializes the variables accordingly
    this->extraHour = extraHours;
}
Secretary::~Secretary() {
//This function is a destructor

}
void Secretary::print(){
//This function is a print function, it prints all the manager data
    cout<<"Name worker: " << this->getName()<< endl
        <<"   Type: secretary\n   ID: "<< this->getId()<<endl
        <<"   Seniority:"<< getSenior()<< endl
        <<"   Salary: "<< getSalary()<< endl;
    cout << "----------------------------------------------------\n";
}
float Secretary::getSalary() {
//This function calculates the manager's salary
    return FIVE_T+TWO_H * getSenior()+extraHour* SIXTY;
}