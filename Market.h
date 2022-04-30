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

};

#endif //AVLNODE_H_MARKET_H
