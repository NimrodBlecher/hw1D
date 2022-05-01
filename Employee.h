#ifndef AVLNODE_H_EMPLOYEE_H
#define AVLNODE_H_EMPLOYEE_H
#include "AVLnode.h"
using namespace hw1;

class Employee {
    int id;
    int my_company_id;
    int salary;
    int grade;
public:
    Employee() = default;
    Employee(int id, int my_company_id, int salary, int grade);
    ~Employee() = default;
    void updateGrade(int addition);
    int getGrade() const;
    int getId() const;
    int getSalary() const ;
    void setSalary(int addition);
    void setCompanyId(int company_id);
    int getCompanyId() const;
};





#endif //AVLNODE_H_Employee_H
