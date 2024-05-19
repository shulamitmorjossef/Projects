//
// Created by Student on 9/4/2023.
//

#include "Deputy.h"
#define THOUSAND 1000
Deputy::Deputy(char* name, long id, int senior, int num, char** nameOfPro, char clas[])
: Worker(name, id, senior ),
Teacher(name, id, senior, num, nameOfPro),                   // Boot line
Tutor(name,id,senior,num,nameOfPro,clas){
//This function is a constructor, it accepts parameters and initializes the variables accordingly

}

Deputy::~Deputy(){
//This function is a destructor
}
void Deputy::print(){
//This function is a print function, it prints all the tutor data
    cout<<"Name worker: " << this->getName()<< endl
        <<"   Type: deputy\n   ID: "<< this->getId()<<endl
        <<"   Seniority:"<< getSenior()<< endl
        <<"   Salary: "<< getSalary()<< endl;
    cout << "----------------------------------------------------\n";
}

float Deputy::getSalary(){
//This function calculates the tutor's salary
    return Tutor::getSalary()+THOUSAND;
}
