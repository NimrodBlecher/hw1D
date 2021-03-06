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
    int highest_earner_id;

public:
    Market();
    ~Market() = default;
    void addCompany(int company_id, int value);
    void addEmployee(int company_id, int employee_id,int grade, int salary);
    void removeCompany(int company_id);
    void removeEmployee (int employee_id);
    void setHighestEarnerId ();
    int getHighestEarnerId () const;
    int getNumOfCompaniesWithEmp () const;
    int getNumOfEmployees () const;
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
    void acquireCompany(int acquirer_id, int target_id, double factor);
    void getHighestEarner(int company_id,int* employee_id);
    void getAllEmployeesBySalary(int company_id, int** employees, int* num_of_employees);
    void inReverseOrderToSalaryArray(int* employees_by_salary_array,int* start, AVLnode<Employee*,int>* root  );
    void getHighestEarnerInEachCompany(int number_of_companies_to_find, int* employees_by_id[]);
    void inOrderToEmployeesArray(int* employees_array, AVLnode<Company*,int>* root,int* start,int* times_left);
//




};

#endif //AVLNODE_H_MARKET_H
