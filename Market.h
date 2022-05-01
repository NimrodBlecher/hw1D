#ifndef AVLNODE_H_MARKET_H
#define AVLNODE_H_MARKET_H
#include "Employee.h"
#include "Company.h"
#include "AVLnode.h"

using namespace  hw1;

class Market {
    AVLnode<Company*,int>* companies_tree;
    AVLnode<AVLnode<Company*,int>*,int>* companies_tree_with_employees;
    AVLnode<Employee*,int>* market_employees_tree_by_id;
    AVLnode<Employee*,int>* market_employees_tree_by_salary;
    AVLnode<AVLnode<AVLnode<Company*,int>*,int>*,int>* employees_route_to_company;
    int num_of_employees;
    int num_of_companies;
    int num_of_company_with_employees;


public:
    Market();
    ~Market() = default;
    void addCompany(int company_id, int value);
    void addEmployee(int company_id, int employee_id,int grade, int salary);
    void removeCompany(int company_id);
    void removeEmployee (int employee_id);
    AVLnode<Employee*,int>* getEmployeesTreeById();
    AVLnode<Employee*,int>* getEmployeesTreeBySalary();
    AVLnode<AVLnode<AVLnode<Company*,int>*,int>*,int> * getEmployeesRouteTree();
    AVLnode<Company*,int>* getCompaniesTree();
    AVLnode<AVLnode<Company*,int>*,int>* getCompaniesTreeWithEmployees();
    Company* getCompany(int id);
    void getCompanyInfo(int company_id, int* value, int* number_of_employees); // made by yuval
    void  getEmployeeInfo(int employee_id, int* company_id, int* salary,int* grade);




};

#endif //AVLNODE_H_MARKET_H
