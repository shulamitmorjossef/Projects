//
// Created by Student on 9/3/2023.
//
#include <iostream>
#include "Worker.h"
#include <cstring>

using namespace std;

Worker::Worker(const char* name, long id, int senior){
//This function is a constructor, it accepts parameters and initializes the variables accordingly
    this->name = new char(strlen(name)+1);
    strcpy(this->name, name);
    setId(id);
    setSeniority(senior);
}
Worker::Worker(const Worker& worker){
    //This function is a copy constructor
    this->id = worker.id;
    this->seniority = worker.seniority;
    this->name = new char [strlen(worker.name)+1];
    strcpy(this->name,worker.name);
}
Worker::~Worker(){
//This function is a destructor
    delete [] name;
}
void Worker::print()
 {
//This function is a print function, it prints all the employee data
    cout<<"Name of worker: "<< name<<endl;
    cout<<"    ID: "<<id<<"\n    Seniority: "<< seniority<<endl;
    cout << "----------------------------------------------------\n";
}
void Worker::setId(long id){
    this->id = id;
}
void Worker::setSeniority(int senior){
    this->seniority = senior;
}
char* Worker::getName()const{
//This function returns the name of the employee
    return name;
}
long Worker::getId()const{
//This function returns the ID of the employee
    return id;
}
int Worker::getSenior()const{
//This function returns the seniority of the employee
    return seniority;
}
