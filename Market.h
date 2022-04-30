#ifndef AVLNODE_H_MARKET_H
#define AVLNODE_H_MARKET_H
#include "Employee.h"
#include "Company.h"
#include "AVLnode.h"

using namespace  hw1;

class Market {
    AVLnode<Company*,int>* companies_tree;
    AVLnode<Company*,int>* companies_tree_with_employees;
    AVLnode<Employee*,int>* market_employees_tree_by_id;
    AVLnode<Employee*,int>* market_employees_tree_by_salary;
    AVLnode<AVLnode<Company*,int>*,int>* employees_route_to_company;
    int num_of_employees;
    int num_of_companies;
    int num_of_comapny_with_employees;


public:
    Market();
    ~Market() = default;
    void addCompany(int company_id, int value);
    void addEmployee(int company_id, int employee_id,int grade, int salary);
    AVLnode<Employee*,int>* getEmployeesTreeById();
    AVLnode<Employee*,int>* getEmployeesTreeBySalary();
    AVLnode<AVLnode<Company*,int>*,int>* getEmployeesRouteTree();
    AVLnode<Company*,int>* getCompaniesTree();
    Company* getCompany(int id);
    void getCompanyInfo(int company_id, int* value, int* num_of_employees); // made by yuval
    void  getEmployeeInfo(int employee_id, int* company_id, int* salary,int* grade);
//    void Remove//



};

#endif //AVLNODE_H_MARKET_H
