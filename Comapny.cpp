#include "Company.h"



Company :: Company(int company_id,int value) : id(company_id), value(value),num_of_employees(0),highest_earner_id(0),
    employees_tree_by_id(nullptr) ,employees_tree_by_salary(nullptr){};

void Company ::setValue(int new_value) {
    value = new_value;
}

int Company :: getId() const {
    return id;
}



int Company ::getNumberOfEmployees() const {
    return num_of_employees;
}


void Company::hireEmployee (AVLnode<Employee*,int>* employee_by_id, AVLnode<Employee*,int>* employee_by_salary) {
    if(num_of_employees == 0)
    {
        employees_tree_by_id = new AVLnode<AVLnode<Employee*,int>*,int> (employee_by_id,employee_by_id->getData()->getId()
                                                   ,employee_by_id->getData()->getSalary());
        employees_tree_by_salary = new AVLnode<AVLnode<Employee*,int>*,int> (employee_by_salary,
                     employee_by_salary->getData()->getSalary(),employee_by_salary->getData()->getId());
    }
    else
    {
        employees_tree_by_id = employees_tree_by_id ->insertNew(employee_by_id,employee_by_id->getData()->getId()
                ,employee_by_id -> getData()->getSalary());
        employees_tree_by_salary = employees_tree_by_salary ->insertNew(employee_by_salary,
                   employee_by_salary->getData()->getSalary(),employee_by_salary->getData()->getId());
   }
    this -> setNumOfEmployees(1);
    this -> setHighestEarner();
}


AVLnode <AVLnode<Employee*,int>*,int>* Company ::getEmployeesTreeById() {
    return employees_tree_by_id;
}


AVLnode <AVLnode<Employee*,int>*,int>* Company ::getEmployeesTreeBySalary()  {
    return employees_tree_by_salary;
}



void Company ::  getHighestEarner(int* earner_id ) const {
    if (this -> num_of_employees == 0)
    {
        throw CompanyHasNoEmployees();
    }
    *earner_id = highest_earner_id;
}

void  Company :: removeEmployee(int remove_id,int salary){
    AVLnode<AVLnode<Employee*,int>*,int>* employee_by_id = employees_tree_by_id -> find(remove_id,salary);
    if (num_of_employees != 0 && employee_by_id != nullptr)
    {
        setNewEmployeesTreeById(deleteNode(remove_id,salary,employees_tree_by_id,WITHOUT_DATA));
        setNewEmployeesTreeBySalary(deleteNode(salary,remove_id,employees_tree_by_salary,WITHOUT_DATA));
        setNumOfEmployees(-1);
        setHighestEarner();
    }
}



int Company ::getValue() const {
    return value;
}

void Company ::setHighestEarner() {
    if (num_of_employees == 0)
    {
        highest_earner_id =0;
        return;
    }
    AVLnode<AVLnode<Employee*,int>*,int>* employee  = this -> getEmployeesTreeBySalary() ->
            findMax(this-> getEmployeesTreeBySalary());
    highest_earner_id = employee -> getData() -> getData() -> getSalary();
}


void Company ::setNumOfEmployees(int addition) {
    num_of_employees += addition;
}

void Company ::setNewEmployeesTreeById(AVLnode<AVLnode<Employee*, int>*, int> *new_employees_tree_by_id)
{
    employees_tree_by_id = new_employees_tree_by_id;
}
void Company ::setNewEmployeesTreeBySalary(AVLnode<AVLnode<Employee*, int>*, int> *new_employees_tree_by_salary) {
    employees_tree_by_salary = new_employees_tree_by_salary;
}

void Company ::buyCompany(Company* company_to_buy, double factor)
{
    if (this->value < 10*(company_to_buy->getValue()))
    {
        throw CompanyValueNotSufficient();
    }
    this->setNewEmployeesTreeById(mergeTrees(this->employees_tree_by_id, company_to_buy->getEmployeesTreeById(),WITHOUT_DATA));
    this->setNewEmployeesTreeBySalary(mergeTrees(this->employees_tree_by_salary,
                                         company_to_buy->getEmployeesTreeBySalary(),WITHOUT_DATA));
    this -> value = floor((this->value + company_to_buy->getValue())*factor);
    setNumOfEmployees(company_to_buy->num_of_employees);
    company_to_buy -> setNumOfEmployees(-(company_to_buy-> num_of_employees));
}


//void Company ::destroyCompany()
//{
//    employees_tree_by_salary->deleteTree();
//    employees_tree_by_id->deleteTree();
//    delete this;
//}

