#ifndef AVLNODE_H_MARKET_H
#define AVLNODE_H_MARKET_H
#include "Employee.h"
#include "Company.h"
#include "AVLnode.h"

using namespace  hw1;

class Market {
    AVLnode<int,int>* companies_tree;
    AVLnode<Company*,int>* companies_with_employees_tree;
    AVLnode<Employee*,int>* market_employee_id_tree;
    AVLnode<Employee*,int>* market_employees_salary_tree;
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
    AVLnode<int,int>* getCompaniesTree();
    AVLnode<Company*,int>* getCompaniesTreeWithEmployees();
    Company* getCompany(int id);
    void getCompanyInfo(int company_id, int* value, int* number_of_employees); // made by yuval
    void  getEmployeeInfo(int employee_id, int* company_id, int* salary,int* grade);
    void increaseCompanyValue(int company_id, int value_to_increase);
    void hireEmployee(int employee_id, int new_company_id);
    void promoteEmployee(int employee_id, int salary_increase, int bump_grade);




};

#endif //AVLNODE_H_MARKET_H
