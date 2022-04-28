#include "Company.h"



Company :: Company(int company_id,int value) : id(company_id), value(value),num_of_workers(0){};

void Company::hireWorker(Company *company, Worker* worker) {
    if(workers_tree_by_id == nullptr)
    {
        workers_tree_by_id = new AVLnode<Worker*,int>(worker,worker->getId(),worker->getSalary());
        workers_tree_by_salary = new AVLnode<Worker*,int>(worker,worker->getSalary(),worker->getId());
        return;
    }
    workers_tree_by_id = workers_tree_by_id ->insertNew(worker,worker->getId(),worker -> getSalary());
    workers_tree_by_salary = workers_tree_by_salary ->insertNew(worker,worker->getSalary(),worker -> getId());
}
