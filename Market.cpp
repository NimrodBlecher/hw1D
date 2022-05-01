#include "Market.h"

Market ::Market() : companies_tree(nullptr),companies_tree_with_employees(nullptr),market_employees_tree_by_id(nullptr),
        market_employees_tree_by_salary(nullptr),employees_route_to_company(nullptr),num_of_employees(0),num_of_companies(0),num_of_company_with_employees(0) {};


//changing nimrod
void Market:: addCompany(int company_id, int value)
{
    AVLnode<Company*,int>* new_company_node = companies_tree->findKey1(company_id);
    if (num_of_companies != 0 && new_company_node != nullptr ){
        throw CompanyAlreadyExist();
        return;
    }
    Company* new_company =  new Company(company_id,value);
    if(num_of_companies == 0)
    {
       companies_tree = new AVLnode<Company*,int>(new_company,company_id,value);
       num_of_companies++;
    }
    else
    {
        companies_tree = companies_tree->insertNew(new_company,company_id,value);
        num_of_companies++;
    }
}


//changing nimrod
void Market::addEmployee(int company_id, int employee_id, int grade, int salary) {
    AVLnode<Employee*,int>* employee_node_by_id = market_employees_tree_by_id->findKey1(employee_id);
    if( num_of_employees != 0 && employee_node_by_id != nullptr )
    {
        throw EmployeeAlreadyExist();
        return;
    }
    AVLnode<Company*,int>* company_node = (companies_tree->findKey1(company_id));
    if (num_of_companies == 0 ||  company_node == nullptr)
    {
        throw CompanyDoesntExist();
        return;
    }
    int value = company_node->getKey2();
    Employee* employee = new Employee(employee_id,company_id,salary,grade);
    if (num_of_employees == 0)
    {
        market_employees_tree_by_id = new AVLnode<Employee*,int>(employee,employee_id,salary);
        market_employees_tree_by_salary = new AVLnode<Employee*,int>(employee,salary,employee_id);
        companies_tree_with_employees = new AVLnode<AVLnode<Company*,int>*,int>(company_node,company_id,value);
        employees_route_to_company = new AVLnode<AVLnode<AVLnode<Company*,int>*,int>*,int> (companies_tree_with_employees,employee_id,company_id);
    }
    else {
        AVLnode<AVLnode<Company *, int> *, int> *shortcut_company = companies_tree_with_employees->find(company_id,
                                                                                                        value);
        if (companies_tree_with_employees->findKey1(company_id) == nullptr) {
            companies_tree_with_employees = companies_tree_with_employees->insertNew(company_node,
                                                                                     company_id, value);
            num_of_company_with_employees++;
        }
        market_employees_tree_by_id = market_employees_tree_by_id->insertNew(employee, employee_id, salary);
        market_employees_tree_by_salary = market_employees_tree_by_salary->insertNew(employee, salary, employee_id);
        employees_route_to_company = employees_route_to_company->insertNew(shortcut_company, employee_id, company_id);
    }
    employee_node_by_id = market_employees_tree_by_id->find(employee_id, salary);
    AVLnode<Employee *, int> *employee_node_by_salary = market_employees_tree_by_salary->find(salary, employee_id);
    company_node->getData()->hireEmployee(employee_node_by_id, employee_node_by_salary);
    num_of_employees++;
}


AVLnode<Employee*,int>* Market ::getEmployeesTreeBySalary() {
    return market_employees_tree_by_salary;
}

AVLnode<Employee*,int>* Market ::getEmployeesTreeById() {
    return market_employees_tree_by_id;
}

AVLnode<Company*,int>* Market ::getCompaniesTree() {
    return companies_tree;
}

AVLnode<AVLnode<Company*,int>*,int>* Market ::getCompaniesTreeWithEmployees() {
    return companies_tree_with_employees;
}

Company* Market ::getCompany(int id) {
    AVLnode<Company*,int>* company = companies_tree->findKey1(id);
    if(num_of_companies != 0 && company != nullptr)
    {
        return company->getData();
    }
    return nullptr;
}

AVLnode<AVLnode<AVLnode<Company*,int>*,int>*,int> * Market ::getEmployeesRouteTree() {
    return employees_route_to_company;
}

void Market:: getCompanyInfo(int company_id, int* value, int* number_of_employees) // made by yuval
{
    if(company_id<=0)
    {
        throw CompanyNegativeId();
    }
    if(value == nullptr || number_of_employees == nullptr)
    {
        throw NullInput();
    }
    AVLnode<Company*,int>* find_company = companies_tree->findKey1(company_id);
    if( num_of_companies == 0 || find_company == nullptr )
    {
        throw CompanyDoesntExist();
        return;
    }
    *value = find_company->getData()->getValue();
    *number_of_employees =find_company->getData()->getNumOfEmployees();
}

void Market:: getEmployeeInfo(int employee_id, int* company_id, int* salary,int* grade)
{


}

void Market ::removeEmployee(int employee_id) {
    AVLnode<AVLnode<AVLnode<Company*,int>*,int>*,int>* my_shortcut_to_company_node
                                                = employees_route_to_company->findKey1(employee_id);
    if(num_of_employees == 0 || my_shortcut_to_company_node == nullptr)
    {
        throw EmployeeDoesNotExist();
    }
    AVLnode<AVLnode<Company*,int>*,int>* company_node = my_shortcut_to_company_node ->getData();
    Company* my_company = company_node -> getData() -> getData();
    AVLnode<Employee*,int>* employee_in_id_market_tree = market_employees_tree_by_id -> findKey1(employee_id);
    int salary = employee_in_id_market_tree->getKey2();
    int company_id = company_node -> getKey1();
    employees_route_to_company = deleteNode(employee_id,company_id,employees_route_to_company,WITHOUT_DATA);
    market_employees_tree_by_salary = deleteNode(salary,employee_id,market_employees_tree_by_salary,WITH_DATA);
    my_company -> removeEmployee(employee_id,salary);
    num_of_employees--;
    if (my_company -> getNumOfEmployees() == 0)
    {
        companies_tree_with_employees = deleteNode(company_id,my_company->getValue(),companies_tree_with_employees,WITHOUT_DATA);
        num_of_company_with_employees--;
    }
   market_employees_tree_by_id = deleteNode(employee_id,salary,market_employees_tree_by_id,WITHOUT_DATA);
}

void Market :: removeCompany(int company_id) {
    AVLnode<Company*,int>* company_node = companies_tree ->findKey1(company_id);
    if (num_of_companies == 0 || company_node == nullptr)
    {
        throw CompanyDoesntExist();
    }
    if (company_node -> getData() -> getNumOfEmployees() != 0)
    {
        throw CompanyHasEmployeesAntCanNotBeDeleted();
    }
    int value = company_node -> getKey2();
    companies_tree = deleteNode(company_id,value,companies_tree,WITHOUT_DATA);
    num_of_companies--;
}
