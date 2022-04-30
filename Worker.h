#ifndef AVLNODE_H_WORKER_H
#define AVLNODE_H_WORKER_H
#include "AVLnode.h"
using namespace hw1;

class Worker {
    int id;
    int my_company_id;
    int salary;
    int grade;
public:
    Worker() = default;
    Worker(int id, int my_company_id, int salary, int grade);
    ~Worker() = default;
    void updateGrade(int addition);
    int getId();
    int getSalary();
    void setSalary(int addition);
    void setComapnyId(int company_id);
    int getCompanyId();
};





#endif //AVLNODE_H_Worker_H
