#include "Company.h"



Company :: Company(int company_id,int value) : id(company_id), value(value),num_of_workers(0),highest_earner_id(0),
    workers_tree_by_id(nullptr) ,workers_tree_by_salary(nullptr){};

Company :: ~Company()
{
    workers_tree_by_salary->deleteTree();
    workers_tree_by_id->deleteTree();
}

int Company :: getId() {
    return id;
}

void Company::hireWorker (AVLnode<Worker,int>* worker) {
    if(workers_tree_by_id == nullptr)
    {
        workers_tree_by_id = new AVLnode<AVLnode<Worker,int>*,int> (worker,worker->getData().getId()
                                                                    ,worker->getData().getSalary());
        workers_tree_by_salary = new AVLnode<AVLnode<Worker,int>*,int> (worker,worker->getData().getSalary()
                                                                        ,worker->getData().getId());
        this -> setHighestEarner();
        this -> setNumOfWorkers(1);
        return;
    }
    workers_tree_by_id = workers_tree_by_id ->insertNew(worker,worker->getData().getId()
                                                        ,worker -> getData().getSalary());
    workers_tree_by_salary = workers_tree_by_salary ->insertNew(worker,worker->getData().getSalary()
                                                                ,worker->getData().getId());
    this -> setNumOfWorkers(1);
    this -> setHighestEarner();
}


AVLnode <AVLnode<Worker,int>*,int>* Company ::getWorkersTreeById() {
    return workers_tree_by_id;
}


AVLnode <AVLnode<Worker,int>*,int>* Company ::getWorkersTreeBySalary()  {
    return workers_tree_by_salary;
}



void Company ::  getHighestEarner(int* earner_id ){
    if (this -> num_of_workers == 0)
    {
        throw CompanyHasNoWorkers();
    }
    AVLnode<AVLnode<Worker,int>*,int>* workers = workers_tree_by_salary;
    while (workers -> getRight() != nullptr)
    {
        workers = workers -> getRight();
    }
    *earner_id = workers -> getData() ->getData(). getId();
}

void  Company :: removeWorker(int remove_id,int salary){
    workers_tree_by_id  = workers_tree_by_id -> deleteNode(remove_id,salary);
    workers_tree_by_salary = workers_tree_by_salary -> deleteNode(salary,remove_id);
}


void Company :: setValue(int addition) {
    value += addition;
}

int Company ::getValue() {
    return value;
}

void Company ::setHighestEarner() {
    AVLnode<AVLnode<Worker,int>*,int>* worker  = this -> getWorkersTreeBySalary() ->
            findMax(this-> getWorkersTreeBySalary());
    highest_earner_id = worker -> getData() -> getData() . getSalary();
}


void Company ::setNumOfWorkers(int addition) {
    num_of_workers += addition;
}

void Company ::setNewWorkersTreeById(AVLnode<AVLnode<Worker, int>*, int> *new_workers_tree_by_id)
{
    workers_tree_by_id = new_workers_tree_by_id;
}
void Company ::setNewWorkersTreeBySalary(AVLnode<AVLnode<Worker, int>*, int> *new_workers_tree_by_salary) {
    workers_tree_by_salary = new_workers_tree_by_salary;
}

void Company ::buyCompany(Company* company_to_buy, double factor)
{
    if (this->value < 10*(company_to_buy->getValue()))
    {
        throw CompanyValueNotSufficient();
    }
    this->workers_tree_by_id = mergeTrees(this->workers_tree_by_id, company_to_buy->getWorkersTreeById());
    this->workers_tree_by_salary = mergeTrees(this->workers_tree_by_salary, company_to_buy->getWorkersTreeBySalary());
    this->value = floor((this->value + company_to_buy->getValue())*factor);

}


//void Company ::destroyCompany()
//{
//    workers_tree_by_salary->deleteTree();
//    workers_tree_by_id->deleteTree();
//    delete this;
//}

