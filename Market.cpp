//
// Created by Blecher on 28/04/2022.
//

#include "Market.h"

Market ::Market() : companies_tree(nullptr),companies_tree_with_workers(nullptr),market_workers_tree_by_id(nullptr),
        market_workers_tree_by_salary(nullptr),num_of_workers(0),num_of_companies(0) {};


void Market:: addCompany(int company_id, int value)
{
    AVLnode<Company*,int>* new_company_node = companies_tree->find(company_id,value);
    if (new_company_node != nullptr){
        throw CompanyAlreadyExist();
    }
    Company* new_company =  new Company(company_id,value);
    new_company ->setValue(value);
    if(companies_tree == nullptr)
    {
       companies_tree = new AVLnode<Company*,int>(new_company,company_id,value);
    }
    else
    {
        companies_tree->insertNew(new_company,company_id,value);
    }
}



void Market::addWorker(int company_id, int worker_id, int grade, int salary) {
    AVLnode<Worker*,int>* worker_node_by_id = market_workers_tree_by_id->findKey1(worker_id);
    if(worker_node_by_id != nullptr)
    {
        throw WorkerAlreadyExist();
    }
    AVLnode<Company*,int>* company_node = (companies_tree->findKey1(worker_id));
    if (num_of_companies == 0 || company_node == nullptr)
    {
        throw CompanyDoesntExist();
    }
    Worker* worker = new Worker(worker_id,company_id,salary,grade);
    if (num_of_workers == 0)
    {
        market_workers_tree_by_id = new AVLnode<Worker*,int>(worker,worker_id,salary);
        market_workers_tree_by_salary = new AVLnode<Worker*,int>(worker,salary,salary);
    }
    market_workers_tree_by_id->insertNew(worker,worker_id,salary);
    market_workers_tree_by_salary->insertNew(worker,salary,worker_id);
    worker_node_by_id = market_workers_tree_by_id-> find(worker_id,salary);
    AVLnode<Worker*,int>* worker_node_by_salary = market_workers_tree_by_id-> find(salary,worker_id);
    company_node -> getData() ->hireWorker(worker_node_by_id,worker_node_by_salary);










}




