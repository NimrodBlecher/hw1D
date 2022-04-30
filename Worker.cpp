#include "Worker.h"
Worker:: Worker(int id, int my_company_id, int salary, int grade) :
        id(id),my_company_id(my_company_id),salary(salary),grade(grade) {};

int Worker::getId() {
    return id;
}

int Worker::getSalary() {
    return salary;
}


void Worker:: setSalary(int addition)
{
    salary += addition;
}

void Worker:: setComapnyId(int company_id)
{
    my_company_id = company_id;
}


void Worker :: updateGrade(int addition)
{
    grade += addition;
}