#ifndef AVLNODE_H_MARKET_H
#define AVLNODE_H_MARKET_H
#include "Worker.h"
#include "Company.h"
#include "Employee.h"
#include "AVLnode.h"

using namespace  hw1;

class Market {
    AVLnode<Company,int>* companies_tree;
    AVLnode<Company,int>* companies_tree_with_workers;
    AVLnode<Worker,int>* workers_tree_by_id;
    AVLnode<Worker,int>* workers_tree_by_salary;
};

#endif //AVLNODE_H_MARKET_H
