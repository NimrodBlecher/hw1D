#ifndef AVLNODE_H_COMPANY_H
#define AVLNODE_H_COMPANY_H
#include "Employee.h"
#include "AVLnode.h"
#define UPGRADE true
#define DO_NOT_UPGRADE false
using namespace  hw1;


class Company {
    int id;
    int num_of_employees;
    int value;
    int highest_earner_id;
    AVLnode<Employee*,int>* employees_tree_by_id;
    AVLnode<Employee*,int>* employees_tree_by_salary;
public:
    Company() = default;
    Company(int company_id,int value);
    ~Company() =default;
    void hireEmployee(Employee* employee);
    int getId() const;
    int getCompanyId() const;
    void getHighestEarner(int* earner_id) const;
    void removeEmployee(int remove_id,int salary);
    int  getValue() const;
    void  setValue(int addition);
    void promoteEmployeeInCompany(int employee_id,int salary_addition,bool upgrade);
    void setHighestEarner();
    void setNumOfEmployees(int addition);
    int getNumOfEmployees() const;
    void setNewEmployeesTreeById(AVLnode<Employee*,int>* new_employees_tree_by_id);
    void setNewEmployeesTreeBySalary(AVLnode<Employee*,int>* new_employees_tree_by_salary);
    AVLnode <Employee*,int>* getEmployeesTreeById();
    AVLnode <Employee*,int>* getEmployeesTreeBySalary();
    void buyCompany(Company* company_to_buy, double factor);
    void inOrderChangingCompanyId(AVLnode<Employee*, int>* root, int new_company_id);
};

//
#endif //AVLNODE_H_COMPANY_H
