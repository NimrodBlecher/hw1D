#ifndef AVLNODE_H_COMPANY_H
#define AVLNODE_H_COMPANY_H
#include "Worker.h"
#include "AVLnode.h"
class Company {
    int id;
    int num_of_workers;
    int value;
    AVLnode<Worker*,int>* workers_tree_by_id;
    AVLnode<Worker*,int>* workers_tree_by_salary;
public:
    Company() = default;
    Company(int company_id,int value);
    ~Company() = default;
    void hireWorker(Company* company,Worker* worker);
};


#endif //AVLNODE_H_COMPANY_H
