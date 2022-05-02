#include "Company.h"



Company :: Company(int company_id,int value) : id(company_id), value(value),num_of_employees(0),highest_earner_id(0),
    employees_tree_by_id(nullptr) ,employees_tree_by_salary(nullptr){};

void Company ::setValue(int addition) {
    value += addition;
}

int Company :: getId() const {
    return id;
}



int Company ::getNumOfEmployees() const {
    return num_of_employees;
}


int Company ::getCompanyId() const {
    return id;
}


void Company::hireEmployee (Employee* employee) { // MAKE SURE YOU INSERTED THE EMPLOYEE WITH THE RIGHT SALARY,ID,COMPANY_ID,ETC...
    if(num_of_employees == 0)
    {
        employees_tree_by_id = new AVLnode<Employee*,int> (employee,employee->getId(),employee->getSalary());
        employees_tree_by_salary = new AVLnode<Employee*,int> (employee,employee->getSalary(),employee->getId());
    }
    else
    {
        employees_tree_by_id = employees_tree_by_id ->insertNew(employee,employee->getId(),employee -> getSalary());
        employees_tree_by_salary = employees_tree_by_salary ->insertNew(employee,employee->getSalary(),employee->getId());
   }
    this -> setNumOfEmployees(1);
    this -> setHighestEarner();
}


AVLnode <Employee*,int>* Company ::getEmployeesTreeById() {
    return employees_tree_by_id;
}


AVLnode <Employee*,int>* Company ::getEmployeesTreeBySalary()  {
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
    AVLnode<Employee*,int>* employee_by_id = employees_tree_by_id -> find(remove_id,salary);
    if (num_of_employees != 0 && employee_by_id != nullptr)
    {

        setNewEmployeesTreeById(deleteNode(remove_id,salary,employees_tree_by_id));
        setNewEmployeesTreeBySalary(deleteNode(salary,remove_id,employees_tree_by_salary));
        setNumOfEmployees(-1);
        setHighestEarner();
        if (num_of_employees == 0)
        {
            setNewEmployeesTreeById(nullptr);
            setNewEmployeesTreeBySalary(nullptr);
        }
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
    AVLnode<Employee*,int>* employee  = this -> getEmployeesTreeBySalary() ->
            findMax(this-> getEmployeesTreeBySalary());
    highest_earner_id = employee -> getData()-> getId();
}


void Company ::setNumOfEmployees(int addition) {
    num_of_employees += addition;
}

void Company ::setNewEmployeesTreeById(AVLnode<Employee*, int> *new_employees_tree_by_id)
{
    employees_tree_by_id = new_employees_tree_by_id;
}
void Company ::setNewEmployeesTreeBySalary(AVLnode<Employee*, int> *new_employees_tree_by_salary) {
    employees_tree_by_salary = new_employees_tree_by_salary;
}

void Company ::buyCompany(Company* company_to_buy, double factor)
{
    if (this->value < 10*(company_to_buy->getValue()))
    {
        throw CompanyValueNotSufficient();
    }
    this->setNewEmployeesTreeById(mergeTrees(this->employees_tree_by_id, company_to_buy->getEmployeesTreeById()));
    this->setNewEmployeesTreeBySalary(mergeTrees(this->employees_tree_by_salary,
                                         company_to_buy->getEmployeesTreeBySalary()));
    this -> value = floor((this->value + company_to_buy->getValue())*factor);
    setNumOfEmployees(company_to_buy->num_of_employees);
    company_to_buy -> setNumOfEmployees(-(company_to_buy-> num_of_employees));
}


