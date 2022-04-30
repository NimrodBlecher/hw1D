#ifndef AVLNODE_H_MARKET_H
#define AVLNODE_H_MARKET_H
#include "Worker.h"
#include "Company.h"
#include "Employee.h"
#include "AVLnode.h"

using namespace  hw1;

class Market {
    AVLnode<Company*,int>* companies_tree;
    AVLnode<Company*,int>* companies_tree_with_workers;
    AVLnode<Worker*,int>* market_workers_tree_by_id;
    AVLnode<Worker*,int>* market_workers_tree_by_salary;
    int num_of_workers;
    int num_of_companies;
    int num_of_comapny_with_workers;

public:
    Market();
    ~Market() = default;
    void addCompany(int company_id, int value);
    void addWorker(int company_id, int employee_id,int grade, int salary);
    AVLnode<Worker*,int>* getWorkersTreeById();
    AVLnode<Worker*,int>* getWorkersTreeBySalary();
    AVLnode<Company*,int>* getCompaniesTree();
    Company* getCompany(int id);
    void getCompanyInfo(int company_id, int* value, int* num_of_employees); // made by yuval
    void  getEmployeeInfo(int worker_id, int* company_id, int* salary,int* grade); //

};

#endif //AVLNODE_H_MARKET_H
