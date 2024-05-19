//
// Created by Student on 9/3/2023.
//
#include "Teacher.h"
#define FIVE_T 5000
#define FIVE_H 500
#define THREE_H 300

Teacher::Teacher(char* name, long id, int senior, int num, char** nameOfPro): Worker(name, id, senior ){
//This function is a constructor, it accepts parameters and initializes the variables accordingly
    this->numOfProfessions = num;
    this->nameOfProfessions = new char* [num];
    for (int i = 0; i< num; ++i){
        this->nameOfProfessions[i] = new char [strlen(nameOfPro[i])+1];
        strcpy(this->nameOfProfessions[i], nameOfPro[i]);
    }
}

Teacher::~Teacher(){
//This function is a destructor
    for (int i = 0; i< numOfProfessions; ++i){
        delete [] nameOfProfessions[i];
    }
    delete [] nameOfProfessions;
}
Teacher::Teacher(const Teacher& teacher): Worker(teacher.getName(),teacher.getId(),teacher.getSenior()){
    //This function is a copy constructor
    this->nameOfProfessions = new char* [teacher.numOfProfessions];
    for(int i = 0; i<numOfProfessions;++i){
        this->nameOfProfessions[i] = new char [strlen(teacher.nameOfProfessions[i]+1)];
        strcpy(this->nameOfProfessions[i],teacher.nameOfProfessions[i]);
    }
    this->numOfProfessions = teacher.numOfProfessions;
}
Teacher& Teacher::operator=(const Teacher& teacher){
    //This function is an operator=
    for (int i = 0; i< numOfProfessions; ++i){
        delete [] nameOfProfessions[i];
    }
    delete [] nameOfProfessions;
    this->nameOfProfessions = new char* [teacher.numOfProfessions];
    for(int i = 0; i<numOfProfessions;++i){
        this->nameOfProfessions[i] = new char [strlen(teacher.nameOfProfessions[i]+1)];
        strcpy(this->nameOfProfessions[i],teacher.nameOfProfessions[i]);
    }
    this->numOfProfessions = teacher.numOfProfessions;
    return *this;
}
void Teacher::print(){
//This function is a print function, it prints all the teacher data
    cout<<"Name worker: " << this->getName()<< endl
    <<"   Type: teacher\n   ID: "<< this->getId()<<endl
    <<"   Seniority:"<< getSenior()<< endl
    <<"   Salary: "<< getSalary()<< endl;
    cout << "----------------------------------------------------\n";
}

float Teacher::getSalary(){
//This function calculates the teacher's salary
    return FIVE_T+getSenior()*FIVE_H+numOfProfessions*THREE_H;
}
int Teacher::getNumOfProfessions()const{
    return numOfProfessions;
}
char** Teacher::getNameOfSubjects()const{
   return nameOfProfessions;
}