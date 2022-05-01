#include "Employee.h"
Employee:: Employee(int id, int my_company_id, int salary, int grade) :
        id(id),my_company_id(my_company_id),salary(salary),grade(grade) {};

int Employee::getId() const {
    return id;
}

int Employee::getCompanyId() const {
    return my_company_id;
}

int Employee::getSalary() const {
    return salary;
}


void Employee:: setSalary(int addition)
{
    salary += addition;
}

int Employee::getGrade() const
{
    return grade;
}

void Employee:: setCompanyId(int company_id)
{
    my_company_id = company_id;
}


void Employee :: updateGrade(int addition)
{
    grade += addition;
}