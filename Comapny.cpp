#include "Company.h"



Company :: Company(int company_id,int value) : id(company_id), value(value),num_of_workers(0),highest_earner_id(0),
    workers_tree_by_id(nullptr) ,workers_tree_by_salary(nullptr){};

void Company ::setValue(int new_value) {
    value = new_value;
}

int Company :: getId() const {
    return id;
}

void Company::hireWorker (AVLnode<Worker*,int>* worker_by_id, AVLnode<Worker*,int>* worker_by_salary) {
    if(workers_tree_by_id == nullptr)
    {
        workers_tree_by_id = new AVLnode<AVLnode<Worker*,int>*,int> (worker_by_id,worker_by_id->getData()->getId()
                                                   ,worker_by_id->getData()->getSalary());
        workers_tree_by_salary = new AVLnode<AVLnode<Worker*,int>*,int> (worker_by_salary,
                     worker_by_salary->getData()->getSalary(),worker_by_salary->getData()->getId());
        this -> setHighestEarner();
        this -> setNumOfWorkers(1);
        return;
    }
    workers_tree_by_id = workers_tree_by_id ->insertNew(worker_by_id,worker_by_id->getData()->getId()
                                                        ,worker_by_id -> getData()->getSalary());
    workers_tree_by_salary = workers_tree_by_salary ->insertNew(worker_by_salary,
             worker_by_salary->getData()->getSalary(),worker_by_salary->getData()->getId());
    this -> setNumOfWorkers(1);
    this -> setHighestEarner();
}


AVLnode <AVLnode<Worker*,int>*,int>* Company ::getWorkersTreeById() {
    return workers_tree_by_id;
}


AVLnode <AVLnode<Worker*,int>*,int>* Company ::getWorkersTreeBySalary()  {
    return workers_tree_by_salary;
}



void Company ::  getHighestEarner(int* earner_id ) const {
    if (this -> num_of_workers == 0)
    {
        throw CompanyHasNoWorkers();
    }
    *earner_id = highest_earner_id;
}

void  Company :: removeWorker(int remove_id,int salary){
    AVLnode<AVLnode<Worker*,int>*,int>* worker_by_id = workers_tree_by_id -> find(remove_id,salary);
    if (worker_by_id != nullptr)
    {
        setNewWorkersTreeById(deleteNode(remove_id,salary,workers_tree_by_id,WITHOUT_DATA));
        setNewWorkersTreeBySalary(deleteNode(salary,remove_id,workers_tree_by_salary,WITHOUT_DATA));
        setNumOfWorkers(-1);
        setHighestEarner();

    }
}



int Company ::getValue() const {
    return value;
}

void Company ::setHighestEarner() {
    if (num_of_workers == 0)
    {
        highest_earner_id =0;
        return;
    }
    AVLnode<AVLnode<Worker*,int>*,int>* worker  = this -> getWorkersTreeBySalary() ->
            findMax(this-> getWorkersTreeBySalary());
    highest_earner_id = worker -> getData() -> getData() -> getSalary();
}


void Company ::setNumOfWorkers(int addition) {
    num_of_workers += addition;
}

void Company ::setNewWorkersTreeById(AVLnode<AVLnode<Worker*, int>*, int> *new_workers_tree_by_id)
{
    workers_tree_by_id = new_workers_tree_by_id;
}
void Company ::setNewWorkersTreeBySalary(AVLnode<AVLnode<Worker*, int>*, int> *new_workers_tree_by_salary) {
    workers_tree_by_salary = new_workers_tree_by_salary;
}

void Company ::buyCompany(Company* company_to_buy, double factor)
{
    if (this->value < 10*(company_to_buy->getValue()))
    {
        throw CompanyValueNotSufficient();
    }
    this->setNewWorkersTreeById(mergeTrees(this->workers_tree_by_id, company_to_buy->getWorkersTreeById(),WITHOUT_DATA));
    this->setNewWorkersTreeBySalary(mergeTrees(this->workers_tree_by_salary,
                                         company_to_buy->getWorkersTreeBySalary(),WITHOUT_DATA));
    this -> value = floor((this->value + company_to_buy->getValue())*factor);
    setNumOfWorkers(company_to_buy->num_of_workers);
    company_to_buy -> setNumOfWorkers(-(company_to_buy-> num_of_workers));
}


//void Company ::destroyCompany()
//{
//    workers_tree_by_salary->deleteTree();
//    workers_tree_by_id->deleteTree();
//    delete this;
//}

