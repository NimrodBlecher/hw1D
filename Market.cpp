//
// Created by Blecher on 28/04/2022.
//

#include "Market.h"

void Market:: AddCompany(int company_id, int value)
{
    AVLnode<Company*,int>* new_company_node = companies_tree->find(company_id,value);
    Company* new_company =  new Company(company_id,value);
    if ( new_company_node != nullptr){
        throw CompanyAlreadyExists();
    }
    if(companies_tree == nullptr)
    {
       companies_tree = new AVLnode<Company*,int>(new_company,company_id,value);
    }
    else
    {
        companies_tree->insertNew(new_company,company_id,value);
    }
}


//void Market::AddWorker(Worker *new_worker, Company* company_hiring) {
//    if(this->workers_tree_by_id == nullptr && this->workers_tree_by_salary == nullptr)
//    {
//        this->workers_tree_by_id = new AVLnode<Worker,int>(*new_worker, new_worker->getId(),new_worker->getSalary());
//        this->workers_tree_by_salary = new AVLnode<Worker,int>(*new_worker, new_worker->getSalary(),new_worker->getId());
//
//    }
//    else
//    {
//        this->workers_tree_by_id->insertNew(*new_worker,new_worker->getId(),new_worker->getSalary());
//        this->workers_tree_by_salary->insertNew(*new_worker,new_worker->getSalary(),new_worker->getId());
//    }
//}

