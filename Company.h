#ifndef AVLNODE_H_COMPANY_H
#define AVLNODE_H_COMPANY_H
#include "Employee.h"
#include "AVLnode.h"
using namespace  hw1;


class Company {
    int id;
    int num_of_employees;
    int value;
    int highest_earner_id;
    AVLnode<AVLnode<Employee*,int>*,int>* employees_tree_by_id;
    AVLnode<AVLnode<Employee*,int>*,int>* employees_tree_by_salary;
public:
    Company() = default;
    Company(int company_id,int value);
    ~Company() =default;
    void hireEmployee(AVLnode<Employee*,int>* employee_by_id,AVLnode<Employee*,int>* employee_by_salary);
    int getId() const;
    void getHighestEarner(int* earner_id) const;
    void removeEmployee(int remove_id,int salary);
    int  getValue() const;
    int  getNumberOfEmployees() const;
    void  setValue(int new_value);
    void setHighestEarner();
    void setNumOfEmployees(int addition);
    int getNumOfEmployees() const;
    void setNewEmployeesTreeById(AVLnode<AVLnode<Employee*,int>*,int>* new_employees_tree_by_id);
    void setNewEmployeesTreeBySalary(AVLnode<AVLnode<Employee*,int>*,int>* new_employees_tree_by_salary);
    AVLnode <AVLnode<Employee*,int>*,int>* getEmployeesTreeById();
    AVLnode <AVLnode<Employee*,int>*,int>* getEmployeesTreeBySalary();
    void buyCompany(Company* company_to_buy, double factor);




};


#endif //AVLNODE_H_COMPANY_H
