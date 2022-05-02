#include "Market.h"

Market ::Market() : companies_tree(nullptr),companies_with_employees_tree(nullptr),market_employee_id_tree(
        nullptr),market_employees_salary_tree(nullptr), num_of_employees(0),num_of_companies(0),num_of_company_with_employees(0) {};


//changing nimrod
void Market:: addCompany(int company_id, int value)
{
    AVLnode<int,int>* new_company_node = companies_tree->findKey1(company_id);
    if (num_of_companies != 0 && new_company_node != nullptr ){
        throw CompanyAlreadyExist();
    }
    if(num_of_companies == 0)
    {
       companies_tree = new AVLnode<int,int>(value,company_id,company_id);
       num_of_companies++;
    }
    else
    {
        companies_tree = companies_tree->insertNew(value,company_id,company_id);
        num_of_companies++;
    }
}


//changing nimrod
void Market::addEmployee(int company_id, int employee_id, int grade, int salary) {
    if(employee_id<=0 || company_id<=0 || grade<0 || salary<= 0)
    {
        throw BadInput();
    }
    AVLnode<Employee *, int> *employee_node_by_id = market_employee_id_tree->findKey1(employee_id);
    if (num_of_employees != 0 && employee_node_by_id != nullptr) {
        throw EmployeeAlreadyExist();
    }
    Employee* new_employee = new Employee(employee_id,company_id,salary,grade);
    AVLnode<int,int>* company_info = companies_tree ->findKey1(company_id);
    if( num_of_companies == 0 || company_info == nullptr)
    {
        throw CompanyDoesntExist();
    }
    int company_value = company_info -> getData();
    AVLnode<Company*,int>* company_hiring = companies_with_employees_tree ->findKey1(company_id);
    if(num_of_company_with_employees == 0 || company_hiring == nullptr)
    {
        Company* new_company = new Company(company_id,company_value);
        new_company -> hireEmployee(new_employee);
        if (num_of_company_with_employees ==0)
        {
            companies_with_employees_tree = new AVLnode<Company*,int>(new_company,company_id,company_id);
        }
        else
        {
            companies_with_employees_tree = companies_with_employees_tree ->insertNew(new_company,company_id,company_id);
        }
        num_of_company_with_employees++;
    }
    else
    {
        company_hiring->getData()->hireEmployee(new_employee);
    }

    market_employee_id_tree = market_employee_id_tree->insertNew(new_employee,employee_id,salary);
    market_employees_salary_tree = market_employees_salary_tree->insertNew(new_employee,salary,employee_id);
    num_of_employees++;



}

AVLnode<Employee*,int>* Market ::getEmployeesTreeBySalary() {
    return market_employees_salary_tree;
}

AVLnode<Employee*,int>* Market ::getEmployeesTreeById() {
    return market_employee_id_tree;
}

AVLnode<int,int>* Market ::getCompaniesTree() {
    return companies_tree;
}

AVLnode<Company*,int>* Market ::getCompaniesTreeWithEmployees() {
    return companies_with_employees_tree;
}

Company* Market ::getCompany(int id) {
    if (num_of_companies == 0)
    {
        throw CompanyDoesntExist();
    }
    AVLnode<Company*,int>* company_node_with_employees = companies_with_employees_tree->findKey1(id);
    if(num_of_company_with_employees == 0 || company_node_with_employees == nullptr )
    {
        AVLnode<int,int>* company_info_node = companies_tree ->findKey1(id);
        if (company_info_node == nullptr)
        {
            throw CompanyDoesntExist();
        }
        return nullptr;
    }
    return company_node_with_employees -> getData();
}


void Market:: getCompanyInfo(int company_id, int* value, int* number_of_employees) // made by yuval
{
    if (num_of_companies == 0)
    {
        throw CompanyDoesntExist();
    }
    if(company_id<=0 || value == nullptr || number_of_employees == nullptr)
    {
        throw InvalidInput();
    }
    AVLnode<Company*,int>* company_node_with_employees = companies_with_employees_tree->findKey1(company_id);
    if(num_of_company_with_employees == 0 || company_node_with_employees == nullptr )
    {
        AVLnode<int,int>* company_info_node = companies_tree ->findKey1(company_id);
        if (company_info_node == nullptr)
        {
            throw CompanyDoesntExist();
        }
        *value = company_info_node->getData();
        *number_of_employees =0;
        return;
    }
    *value = company_node_with_employees->getData()->getValue();
    *number_of_employees =company_node_with_employees->getData()->getNumOfEmployees();
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
    AVLnode<Employee*,int>* employee_node = market_employee_id_tree->findKey1(employee_id);
    if(num_of_employees == 0 || employee_node == nullptr )
    {
        throw EmployeeDoesNotExist();
    }
    Employee* employee_to_get_info = employee_node->getData();
    *company_id = employee_to_get_info->getCompanyId();
    *salary = employee_to_get_info->getSalary();
    *grade = employee_to_get_info->getGrade();

}

void Market ::removeEmployee(int employee_id) {
    if(employee_id<=0)
    {
        throw EmployeeNegativeId();
    }
    AVLnode<Employee*,int>* employee_node_to_delete_id = market_employee_id_tree ->findKey1(employee_id);
    if( num_of_employees == 0 || employee_node_to_delete_id == nullptr)
    {
        throw EmployeeDoesNotExist();
    }
    Employee* employee_to_delete = ( employee_node_to_delete_id )-> getData();
    int salary = employee_to_delete -> getSalary();
    int company_id = employee_to_delete -> getCompanyId();
    AVLnode<Company*,int>* company_node_to_delete = companies_with_employees_tree ->findKey1(company_id);
    Company* company = company_node_to_delete->getData();
    company->removeEmployee(employee_id,salary);
    if (company -> getNumOfEmployees() == 0)
    {
        delete company;
        companies_with_employees_tree = deleteNode(company_id,company_id,companies_with_employees_tree);
        cout<< "removing last employee and Company " << company_id << endl;


    }
    market_employees_salary_tree = deleteNode(salary,employee_id,market_employees_salary_tree);
    market_employee_id_tree = deleteNode(employee_id,salary,market_employee_id_tree);
    num_of_employees--;
    delete employee_to_delete;
}






void Market :: removeCompany(int company_id) {
    AVLnode<int,int>* company_info = companies_tree ->findKey1(company_id);
    if (num_of_companies == 0 || company_info == nullptr)
    {
        throw CompanyDoesntExist();
    }
    AVLnode<Company*,int>* company_node = companies_with_employees_tree ->findKey1(company_id);
    if (num_of_company_with_employees != 0 && company_node != nullptr)
    {
        throw CompanyHasEmployeesAntCanNotBeDeleted();
    }
    //Company* company_to_delete = company_node->getData();
    companies_tree = deleteNode(company_id,company_id,companies_tree);
    num_of_companies--;
    //delete(company_to_delete);
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
    AVLnode<int,int>* company_info = companies_tree->findKey1(company_id);
    if(num_of_companies == 0 || company_info == nullptr )
    {
        throw CompanyDoesntExist();
    }
    int current_value = company_info -> getData();
    company_info->setData(value_to_increase+current_value);
    Company* company = companies_with_employees_tree ->findKey1(company_id) -> getData();
    company ->setValue(value_to_increase);
}
