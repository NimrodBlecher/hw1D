//
// Created by Blecher on 28/04/2022.
//

#include "Market.h"

void Market:: AddCompany(Company* new_company)
{
    if(this->companies_tree == nullptr && this->companies_tree_with_workers == nullptr)
    {
        this->companies_tree = new AVLnode<Company,int>(*new_company, new_company->getId(),new_company->getValue());
    }
    else
    {
        this->companies_tree->insertNew(*new_company,new_company->getId(),new_company->getValue());
    }
}


void Market::AddWorker(Worker *new_worker, Company* company_hiring) {
    if(this->workers_tree_by_id == nullptr && this->workers_tree_by_salary == nullptr)
    {
        this->workers_tree_by_id = new AVLnode<Worker,int>(*new_worker, new_worker->getId(),new_worker->getSalary());
        this->workers_tree_by_salary = new AVLnode<Worker,int>(*new_worker, new_worker->getSalary(),new_worker->getId());

    }
    else
    {
        this->workers_tree_by_id->insertNew(*new_worker,new_worker->getId(),new_worker->getSalary());
        this->workers_tree_by_salary->insertNew(*new_worker,new_worker->getSalary(),new_worker->getId());
    }
}

