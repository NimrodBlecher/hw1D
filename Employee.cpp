
#include "Employee.h"


Employee:: Employee(int id, int salary, AVLnode<Company,int>* my_company) :
id(id),salary(salary),my_company(my_company){};

void Employee::hireEmployee(AVLnode<Company,int>* company) {
    my_company = company;
}

