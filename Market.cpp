#include "Market.h"

Market ::Market() : companies_tree(nullptr),companies_tree_with_workers(nullptr),market_workers_tree_by_id(nullptr),
        market_workers_tree_by_salary(nullptr),num_of_workers(0),num_of_companies(0) {};


//changing nimrod
void Market:: addCompany(int company_id, int value)
{
    AVLnode<Company*,int>* new_company_node = companies_tree->findKey1(company_id);
    if (new_company_node != nullptr && num_of_companies != 0){
        //throw CompanyAlreadyExist();
        return;
    }
    Company* new_company =  new Company(company_id,value);
    if(num_of_companies == 0)
    {
       companies_tree = new AVLnode<Company*,int>(new_company,company_id,value);
       num_of_companies++;
    }
    else
    {
        companies_tree = companies_tree->insertNew(new_company,company_id,value);
        num_of_companies++;
    }
}


//changing nimrod
void Market::addWorker(int company_id, int worker_id, int grade, int salary) {
    AVLnode<Worker*,int>* worker_node_by_id = market_workers_tree_by_id->findKey1(worker_id);
    if( num_of_workers != 0 && worker_node_by_id != nullptr )
    {
        //throw WorkerAlreadyExist();
        return;
    }
    AVLnode<Company*,int>* company_node = (companies_tree->findKey1(company_id));
    if (company_node == nullptr || num_of_companies == 0  )
    {
        //throw CompanyDoesntExist();
        return;
    }
    Worker* worker = new Worker(worker_id,company_id,salary,grade);
    if (num_of_workers == 0)
    {
        market_workers_tree_by_id = new AVLnode<Worker*,int>(worker,worker_id,salary);
        market_workers_tree_by_salary = new AVLnode<Worker*,int>(worker,salary,worker_id);
        workers_route_to_company = new AVLnode<AVLnode<Company*,int>*,int> (company_node,worker_id,company_id);
    }
    else {
        market_workers_tree_by_id = market_workers_tree_by_id -> insertNew(worker,worker_id,salary);
        market_workers_tree_by_salary = market_workers_tree_by_salary-> insertNew(worker,salary,worker_id);
        workers_route_to_company = workers_route_to_company -> insertNew(company_node,worker_id,company_id);
    }
    if (num_of_workers == 0 || companies_tree_with_workers->findKey1(company_id) == nullptr)
    {
        companies_tree_with_workers = companies_tree_with_workers ->insertNew(company_node->getData(),
                                company_id,company_node->getKey2());
    }
    worker_node_by_id = market_workers_tree_by_id -> find(worker_id,salary);
    AVLnode<Worker*,int>* worker_node_by_salary = market_workers_tree_by_salary-> find(salary,worker_id);
    company_node -> getData() -> hireWorker(worker_node_by_id,worker_node_by_salary);
    num_of_workers++;
}


AVLnode<Worker*,int>* Market ::getWorkersTreeBySalary() {
    return market_workers_tree_by_salary;
}

AVLnode<Worker*,int>* Market ::getWorkersTreeById() {
    return market_workers_tree_by_id;
}

AVLnode<Company*,int>* Market ::getCompaniesTree() {
    return companies_tree;
}

Company* Market ::getCompany(int id) {
    AVLnode<Company*,int>* company = companies_tree->findKey1(id);
    if(num_of_companies != 0 && company != nullptr)
    {
        return company->getData();
    }
    return nullptr;
}

AVLnode<AVLnode<Company*,int>*,int>* Market ::getWorkersRouteTree() {
    return workers_route_to_company;
}
