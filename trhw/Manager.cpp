//
// Created by Student on 9/4/2023.
//

#include "Manager.h"
#define TEN_T 10000
#define EIGHT_H 800
Manager::Manager(char* name, long id, int senior): Worker(name,id,senior){
//This function is a constructor, it accepts parameters and initializes the variables accordingly

}
Manager::~Manager(){
//This function is a destructor
}
void Manager::print(){
//This function is a print function, it prints all the manager data
    cout<<"Name worker: " << this->getName()<< endl
        <<"   Type: manager\n   ID: "<< this->getId()<<endl
        <<"   Seniority:"<< getSenior()<< endl
        <<"   Salary: "<< getSalary()<< endl;
    cout << "----------------------------------------------------\n";
}
float Manager::getSalary() {
//This function calculates the manager's salary
    return TEN_T+EIGHT_H * getSenior();
}