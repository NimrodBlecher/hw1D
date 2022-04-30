#ifndef AVLNODE_H_COMPANY_H
#define AVLNODE_H_COMPANY_H
#include "Worker.h"
#include "AVLnode.h"
using namespace  hw1;


class Company {
    int id;
    int num_of_workers;
    int value;
    int highest_earner_id;
    AVLnode<AVLnode<Worker*,int>*,int>* workers_tree_by_id;
    AVLnode<AVLnode<Worker*,int>*,int>* workers_tree_by_salary;
public:
    Company() = default;
    Company(int company_id,int value);
    ~Company() =default;
    void hireWorker(AVLnode<Worker*,int>* worker_by_id,AVLnode<Worker*,int>* worker_by_salary);
    int getId() const;
    void getHighestEarner(int* earner_id) const;
    void removeWorker(int remove_id,int salary);
    int  getValue() const;
    int  getNumberOfWorkers();
    void  setValue(int new_value);
    void setHighestEarner();
    void setNumOfWorkers(int addition);
    int getNumOfWorkers() const;
    void setNewWorkersTreeById(AVLnode<AVLnode<Worker*,int>*,int>* new_workers_tree_by_id);
    void setNewWorkersTreeBySalary(AVLnode<AVLnode<Worker*,int>*,int>* new_workers_tree_by_salary);
    AVLnode <AVLnode<Worker*,int>*,int>* getWorkersTreeById();
    AVLnode <AVLnode<Worker*,int>*,int>* getWorkersTreeBySalary();
    void buyCompany(Company* company_to_buy, double factor);




};


#endif //AVLNODE_H_COMPANY_H
