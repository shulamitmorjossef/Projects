//
// Created by Student on 9/5/2023.
//

#include "School.h"
#define ZERO 0
#define TEN 10

typedef enum {ADDWORKER = 1, PRINTWORKER = 2, PRINTPROFESSION = 3, PRINTTUTORS = 4, PRINTMANAGEMENT = 5, EXIT = 6} menu;
typedef enum {TEACHER = 'A', TEMP = 'B', TUTOR = 'C', DEPUTY = 'D', MANAGER = 'E', SECRETARY = 'F'} secMenu;

School::School(): sumOfWorker(ZERO), employs(nullptr), managerExist(false){
    //This function is an empty constructor
}
School::~School(){
    //This function is a destructor
    for(int i = 0; i<sumOfWorker;++i){
        delete employs[i];
    }
    delete [] employs;
}

void School::menu() {
    //This function prints the main menu and calls the appropriate function of the user's choice
    int choice ;
    bool again = true;
    while (again) {
        cout << "Main menu:\n"
                "  1. Add worker\n"
                "  2. Print workers\n"
                "  3. Print profession\n"
                "  4. Print tutors\n"
                "  5. Print management\n"
                "  6. Exit\n";
        cin >> choice;
        switch (choice) {
            case ADDWORKER:
                addWorker();
                break;
            case PRINTWORKER:
                printWorkers();
                break;
            case PRINTPROFESSION:
                printProfession();
                break;
            case PRINTTUTORS:
                printTutors();
                break;
            case PRINTMANAGEMENT:
                printManagement();
                break;
            case EXIT:
                again = false;
                break;
            default:
                cout << "Error\n";
        }
    }
}
void School::addWorker(){
    //This function prints all types of employees that can be added to the array,
    // and receives from the user a new employee according to the user's choice
    char choice, name[TEN], tmp [TEN];
    long id;
    int senior, numOfPro;
    char** nameOfPro;
    cout<<"Choose type of worker:\n"
          " A. Teacher\n"
          " B. Temp\n"
          " C. Tutor\n"
          " D. Deputy\n"
          " E. Manager\n"
          " F. Secretary\n";
    cin>>choice;
    switch (choice) {
        //For each user selection, we will create a new object,
        //check that the input is correct, and send a pointer to the object to a function that will add it to the array
        case TEACHER:
            cout<<"Enter id number: \n";
            cin>>id;
            if(checkId(id)) {
                cout << "An ID already exists in the system, it is not possible to enter this employee again\n";
                cout << "----------------------------------------------------\n";
            }
            else {
                Teacher* newTeacher;
                cout << "Enter name of teacher:\n";
                cin >> name;
                cout << "Enter seniority:\n";
                cin >> senior;
                cout << "Enter number of professional:\n";
                cin >> numOfPro;
                cout << "Enter professional:\n";
                nameOfPro = new char *[numOfPro];                        //Receiving employee details from the user
                for (int i = 0; i < numOfPro; ++i) {
                    cin >> tmp;
                    nameOfPro[i] = new char[strlen(tmp) + 1];
                    strcpy(nameOfPro[i], tmp);
                }
                newTeacher = new Teacher(name, id, senior, numOfPro, nameOfPro);
                updateArray(newTeacher);
                cout << "A teacher has been successfully added\n";
                cout<<"----------------------------------------------------\n";
            }
            break;
        case TEMP:
            Temp* newTemp;
            int sumOfHour;
            cout<<"Enter id number: \n";
            cin>>id;
            if(checkId(id)) {
                cout << "An ID already exists in the system, it is not possible to enter this employee again\n";
                cout << "----------------------------------------------------\n";
            }
            else {
                cout << "Enter name of temp:\n";
                cin >> name;
                cout << "Enter number of hours:\n";
                cin >> sumOfHour;
                cout << "Enter seniority:\n";                       // Receiving employee details from the user
                cin >> senior;
                cout << "Enter number of professional:\n";
                cin >> numOfPro;
                cout << "Enter professional:\n";
                nameOfPro = new char *[numOfPro];
                for (int i = 0; i < numOfPro; ++i) {
                    cin >> tmp;
                    nameOfPro[i] = new char[strlen(tmp) + 1];
                    strcpy(nameOfPro[i], tmp);
                }
                newTemp = new Temp(name, id, senior, numOfPro, nameOfPro, sumOfHour);
                updateArray(newTemp);
                cout << "A temp has been successfully added\n";
                cout<<"----------------------------------------------------\n";
            }
            break;
        case TUTOR:
            Tutor* newTutor;
            char clasT[FOUR];
            cout<<"Enter id number: \n";
            cin>>id;
            if(checkId(id)) {
                cout << "An ID already exists in the system, it is not possible to enter this employee again\n";
                cout << "----------------------------------------------------\n";
            }
            else {
                cout << "Enter name of tutor:\n";
                cin >> name;
                cout << "Enter class of tutor:\n";
                cin >> clasT;
                if(checkTutor(clasT)) {
                    cout << "This class already has an tutor, it is not possible to add another tutor to this class \n";
                    cout << "----------------------------------------------------\n";
                }
                else {
                    cout << "Enter seniority:\n";
                    cin >> senior;
                    cout << "Enter number of professional:\n";
                    cin >> numOfPro;
                    cout << "Enter professional:\n";                       //Receiving employee details from the user
                    nameOfPro = new char *[numOfPro];
                    for (int i = 0; i < numOfPro; ++i) {
                        cin >> tmp;
                        nameOfPro[i] = new char[strlen(tmp) + 1];
                        strcpy(nameOfPro[i], tmp);
                    }
                    newTutor = new Tutor(name, id, senior, numOfPro, nameOfPro, clasT);
                    updateArray(newTutor);
                    cout << "A tutor has been successfully added\n";
                    cout<<"----------------------------------------------------\n";
                }
            }
            break;
        case DEPUTY:
            Deputy* newDeputy;
            char clasD[FOUR];
            cout<<"Enter id number: \n";
            cin>>id;
            if(checkId(id)) {
                cout << "An ID already exists in the system, it is not possible to enter this employee again\n";
                cout << "----------------------------------------------------\n";
            }
            else {
                cout << "Enter name of deputy:\n";
                cin >> name;
                cout << "Enter class of deputy:\n";
                cin >> clasD;
                if(checkTutor(clasD)) {
                    cout << "This class already has a tutor, it is not possible to add another tutor to this class \n";
                    cout << "----------------------------------------------------\n";
                }
                else {
                    cout << "Enter seniority:\n";
                    cin >> senior;
                    cout << "Enter number of professional:\n";
                    cin >> numOfPro;
                    cout << "Enter professional:\n";              // Receiving employee details from the user
                    nameOfPro = new char *[numOfPro];
                    for (int i = 0; i < numOfPro; ++i) {
                        cin >> tmp;
                        nameOfPro[i] = new char[strlen(tmp) + 1];
                        strcpy(nameOfPro[i], tmp);
                    }
                    newDeputy = new Deputy(name, id, senior, numOfPro, nameOfPro, clasD);
                    updateArray(newDeputy);
                    cout << "A deputy has been successfully added\n";
                    cout<<"----------------------------------------------------\n";
                }
            }
            break;
        case MANAGER:
            if(managerExist) {
                cout << "There is already a manager for the school, it is not possible to add a manager \n";
                cout << "----------------------------------------------------\n";
            }
            else {
                Manager* newManager;
                cout << "Enter id number: \n";
                cin >> id;
                if(checkId(id)) {
                    cout << "An ID already exists in the system, it is not possible to enter this employee again\n";
                    cout << "----------------------------------------------------\n";
                }
                else {
                    cout << "Enter name of manager:\n";
                    cin >> name;                                                 //Receiving employee details from the user
                    cout << "Enter seniority:\n";
                    cin >> senior;
                    newManager = new Manager(name, id, senior);
                    updateArray(newManager);
                    managerExist = true;
                    cout << "A manager has been successfully added\n";
                    cout<<"----------------------------------------------------\n";
                }
            }
            break;
        case SECRETARY:
            Secretary* newSecretary;
            int extraHours;
            cout<<"Enter id number: \n";
            cin>>id;
            if(checkId(id)) {
                cout << "An ID already exists in the system, it is not possible to enter this employee again\n";
                cout << "----------------------------------------------------\n";
            }
            else {
                cout << "Enter name of secretary:\n";
                cin >> name;
                cout << "Enter seniority:\n";                           //Receiving employee details from the user
                cin >> senior;
                cout << "Enter number of extra hours:\n";
                cin >> extraHours;
                newSecretary = new Secretary(name, id, senior, extraHours);
                updateArray(newSecretary);
                cout << "A secretary has been successfully added\n";
                cout<<"----------------------------------------------------\n";
            }
            break;
        default:
            cout << "Error\n";
    }
}
void School::printWorkers(){
    //This function prints all the details of the employees in the school
    for(int i = 0; i<sumOfWorker; ++i){
        employs[i]->print();
    }
}
void School::printProfession(){
    //This function takes a subject from the user and prints all the teachers in the school who teach it
    char subject[TEN];
    char** array;
    Teacher* pt;
    cout<<"Enter subject:\n";
    cin>>subject;
    cout<<"The teachers that can teach "<< subject<< ":\n";
    for(int i = 0;i<sumOfWorker;++i){
        if(pt = dynamic_cast<Teacher*>(employs[i]) ){
            array = pt->getNameOfSubjects();
            for(int j = 0; j<pt->getNumOfProfessions();++j){
                if(strcmp(subject, array[j]) == 0){
                    cout<<pt->getName()<<endl;
                    j = pt->getNumOfProfessions();
                }
            }
        }
    }
    cout<<"----------------------------------------------------\n";
}
void School::printTutors(){
    //This function prints the names of the tutors in the school and their classes
    Tutor* pt;
    cout<<"The tutors:\n";
    for(int i = 0;i<sumOfWorker;++i) {
        if(pt = dynamic_cast<Tutor*>(employs[i])){
            cout<<pt->getName()<<": "<< pt->getClas()<<endl;
        }
    }
    cout<<"----------------------------------------------------\n";
}
void School::printManagement(){
    //This function prints the names of the school manager and his deputies
    Deputy* pd;
    Manager* pm;
    for(int i = 0; i<sumOfWorker; ++i) {
        if (pm = dynamic_cast<Manager*>(employs[i])) {
            cout << "The manager: \n" << employs[i]->getName() << endl;
        }
    }
    cout << "The deputies: \n";
    for(int i = 0; i<sumOfWorker; ++i) {
        if (pd = dynamic_cast<Deputy*>(employs[i])) {
            cout << employs[i]->getName() << endl;
        }
    }
    cout<<"----------------------------------------------------\n";
}
void School::updateArray(Worker* newWorker){
//This function accepts a pointer to the employee as a parameter and adds it to the employee array
    Worker** newArray = new Worker * [sumOfWorker+1];
    for(int i = 0; i<sumOfWorker; ++i){
         newArray[i] = employs[i];
    }
    newArray[sumOfWorker] = newWorker;
    ++sumOfWorker;
    delete employs;
    employs = newArray;
}
bool School::checkId(int id){
    //This function accepts an ID number as a parameter and checks if there is already an employ in the system with this ID number
    for (int i = 0; i < sumOfWorker; ++i) {
        if(id == employs[i]->getId())
            return true;
    }
    return false;

}
bool School::checkTutor(char clas[FOUR] ){
    //This function accepts a class as a parameter and checks if there is already a tutor for this class
    Tutor* pt;
    for (int i = 0; i < sumOfWorker; ++i) {
        if (pt = dynamic_cast<Tutor *>(employs[i])) {
            if (strcmp(pt->getClas(), clas) == 0 )
                return true;
        }
    }
    return false;
}

