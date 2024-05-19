//
// Created by Student on 9/4/2023.
//

#include "Tutor.h"
#define FIVE_T 5000
#define FIVE_H 500
#define THREE_H 300
#define THOUSAND 1000

Tutor::Tutor(char* name, long id, int senior, int num, char** nameOfPro, char clas[]): Worker(name, id, senior ),
Teacher(name, id, senior, num, nameOfPro){
//This function is a constructor, it accepts parameters and initializes the variables accordingly
    strcpy(this->clas,clas);
}
Tutor::Tutor(const Tutor& tutor):
//This function is a copy constructor
Worker(tutor.getName(),tutor.getId(),tutor.getSenior()),
Teacher(tutor.getName(),tutor.getId(),tutor.getSenior(),tutor.getNumOfProfessions(), tutor.getNameOfSubjects()){
    strcpy(this->clas,tutor.clas);

}
Tutor::~Tutor(){
//This function is a destructor
}
void Tutor::print(){
//This function is a print function, it prints all the tutor data
    cout<<"Name worker: " << this->getName()<< endl
        <<"   Type: tutor\n   ID: "<< this->getId()<<endl
        <<"   Seniority:"<< getSenior()<< endl
        <<"   Salary: "<< getSalary()<< endl;
    cout << "----------------------------------------------------\n";
}

float Tutor::getSalary(){
//This function calculates the tutor's salary

    return Teacher::getSalary()+THOUSAND;
}
const char* Tutor::getClas(){
    return clas;
}