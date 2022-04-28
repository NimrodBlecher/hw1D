
#ifndef AVLNODE_H_EMPLOYEE_H
#define AVLNODE_H_EMPLOYEE_H
#include "AVLnode.h"
#include "Worker.h"
#include "Company.h"
class Employee{
    int id;
    int salary;
    AVLnode<Company,int>* my_company;
public:
    Employee(int id, int salary, AVLnode<Company,int>*);
    void hireEmployee(AVLnode<Company,int>* comapny);
    ~Employee() = default;
};



#endif //AVLNODE_H_EMPLOYEE_H
