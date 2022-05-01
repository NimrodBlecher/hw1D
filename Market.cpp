#include "Market.h"

Market ::Market() : companies_tree(nullptr),companies_tree_with_employees(nullptr),market_employees_tree_by_id(nullptr),
        market_employees_tree_by_salary(nullptr),num_of_employees(0),num_of_companies(0) {};


//changing nimrod
void Market:: addCompany(int company_id, int value)
{
    AVLnode<Company*,int>* new_company_node = companies_tree->findKey1(company_id);
    if (new_company_node != nullptr && num_of_companies != 0){
        //throw CompanyAlreadyExist();
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
        //throw EmployeeAlreadyExist();
        return;
    }
    AVLnode<Company*,int>* company_node = (companies_tree->findKey1(company_id));
    if (company_node == nullptr || num_of_companies == 0  )
    {
        //throw CompanyDoesntExist();
        return;
    }
    Employee* employee = new Employee(employee_id,company_id,salary,grade);
    if (num_of_employees == 0)
    {
        market_employees_tree_by_id = new AVLnode<Employee*,int>(employee,employee_id,salary);
        market_employees_tree_by_salary = new AVLnode<Employee*,int>(employee,salary,employee_id);
        employees_route_to_company = new AVLnode<AVLnode<Company*,int>*,int> (company_node,employee_id,company_id);
    }
    else {
        market_employees_tree_by_id = market_employees_tree_by_id -> insertNew(employee,employee_id,salary);
        market_employees_tree_by_salary = market_employees_tree_by_salary-> insertNew(employee,salary,employee_id);
        employees_route_to_company = employees_route_to_company -> insertNew(company_node,employee_id,company_id);
    }
    if (num_of_employees == 0 || companies_tree_with_employees->findKey1(company_id) == nullptr)
    {
        companies_tree_with_employees = companies_tree_with_employees ->insertNew(company_node->getData(),
                                company_id,company_node->getKey2());
        num_of_comapny_with_employees++;
    }
    employee_node_by_id = market_employees_tree_by_id -> find(employee_id,salary);
    AVLnode<Employee*,int>* employee_node_by_salary = market_employees_tree_by_salary-> find(salary,employee_id);
    company_node -> getData() -> hireEmployee(employee_node_by_id,employee_node_by_salary);
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

Company* Market ::getCompany(int id) {
    AVLnode<Company*,int>* company = companies_tree->findKey1(id);
    if(num_of_companies != 0 && company != nullptr)
    {
        return company->getData();
    }
    return nullptr;
}

AVLnode<AVLnode<Company*,int>*,int>* Market ::getEmployeesRouteTree() {
    return employees_route_to_company;
}

void Market:: getCompanyInfo(int company_id, int* value, int* num_of_employees) // made by yuval
{
    if(company_id<=0)
    {
        throw CompanyNegativeId();
    }
    if(value == nullptr || num_of_employees == nullptr)
    {
        throw NullInput();
    }
    AVLnode<Company*,int>* find_company = companies_tree->findKey1(company_id);
    if(num_of_companies == 0 || find_company == nullptr )
    {
        throw CompanyDoesntExist();
    }
    *value =find_company->getData()->getValue();
    *num_of_employees =find_company->getData()->getNumberOfEmployees();
}

void Market:: getEmployeeInfo(int employee_id, int* company_id, int* salary,int* grade) //
{
    if(company_id == nullptr || grade == nullptr || salary == nullptr)
    {
        throw NullInput();
    }
    if(employee_id<=0)
    {
        throw EmployeeNegativeId();
    }
    AVLnode<AVLnode<Company*,int>*,int>* find_employee = employees_route_to_company->findKey1(employee_id);
    if(num_of_employees == 0 || find_employee == nullptr )
    {
        throw EmployeeDoesNotExist();
    }
    *company_id = find_employee->getKey2();
    AVLnode<Employee*,int>* find_employee_in_general_tree = market_employees_tree_by_id->findKey1(employee_id);
    *salary = find_employee_in_general_tree->getKey2();
    *grade = find_employee_in_general_tree->getData()->getGrade();

}

void Market:: increaseCompanyValue(int company_id, int value_to_increase)
{
    if(company_id<=0)
    {
        throw CompanyNegativeId();
    }
    if(value_to_increase<=0)
    {
        throw NegativeIncreaseValue();
    }
    AVLnode<Company*,int>* find_company = companies_tree->findKey1(company_id);
    if(num_of_companies == 0 || find_company == nullptr )
    {
        throw CompanyDoesntExist();
    }
    find_company->getData()->setValue(value_to_increase);
}

void Market :: promoteEmployee(int employee_id, int salary_increase, int bump_grade)
{
    if(employee_id<=0)
    {
        throw EmployeeNegativeId();
    }
    if(salary_increase<=0)
    {
        throw NegativeSalaryIncrease();
    }
    AVLnode<Employee*,int>* find_employee = market_employees_tree_by_id->findKey1(employee_id);
    if(num_of_employees == 0 || find_employee == nullptr )
    {
        throw EmployeeDoesNotExist();
    }
    int old_salary = find_employee->getData()->getSalary();
    find_employee->getData()->setSalary(salary_increase);
    int new_salary = find_employee->getData()->getSalary();
    find_employee->setKey2(new_salary);
    AVLnode<Employee*,int>* find_employee_by_salary = market_employees_tree_by_salary->find(old_salary,employee_id);
    find_employee_by_salary->setKey1(new_salary);
    AVLnode<AVLnode<Company*,int>*,int>* route_to_company = employees_route_to_company->findKey1(employee_id);
    AVLnode<Company*,int>* employee_company = route_to_company->getData();
    employee_company->getData()->getEmployeesTreeById()->findKey1(employee_id)->setKey2(new_salary);
    employee_company->getData()->getEmployeesTreeBySalary()->find(old_salary,employee_id)->setKey1(new_salary);
    AVLnode<Employee*,int>* find_employee_by_salary_in_company = market_employees_tree_by_salary->findKey1(employee_id);

    if(bump_grade>0)
    {
        find_employee->getData()->updateGrade(1);
    }
}