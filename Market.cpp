#include "Market.h"

Market ::Market() : companies_tree(nullptr),companies_with_employees_tree(nullptr),market_employee_id_tree(
        nullptr),market_employees_salary_tree(nullptr), num_of_employees(0),num_of_companies(0),
        num_of_company_with_employees(0),highest_earner_id(0) {};


void Market ::setHighestEarnerId() {
    if (num_of_employees == 0)
    {
        highest_earner_id =0;
        return;
    }
    AVLnode<Employee*,int>* employee  =  getEmployeesTreeBySalary() -> findMax( getEmployeesTreeBySalary());
    highest_earner_id = employee -> getData()-> getId();
}

int Market ::getHighestEarnerId() const {
    return highest_earner_id;
}

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
    setHighestEarnerId();
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
        return nullptr;
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
    cout<< "removing employee numer :" << employee_id<<endl;
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
    setHighestEarnerId();
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
    AVLnode<Company*,int>* company_node = companies_with_employees_tree ->findKey1(company_id);
    if(num_of_company_with_employees != 0 && company_node != nullptr)
    {

        company_node->getData()->setValue(value_to_increase);
    }

}


void Market:: hireEmployee(int employee_id, int new_company_id)
{
    if(employee_id<=0 || new_company_id <=0)
    {
        throw BadInput();
    }
    Employee* employee = market_employee_id_tree->findKey1(employee_id) ->getData();
    int new_employee_id = employee->getId();
    int new_employee_grade = employee->getGrade();
    int new_employee_salary = employee->getSalary();
    if(num_of_employees ==0 || employee == nullptr)
    {
        throw EmployeeDoesNotExist();
    }
    removeEmployee(employee_id);
    try
    {
        addEmployee(new_company_id,new_employee_id,new_employee_grade,new_employee_salary);
    }
    catch(CompanyDoesntExist&)
    {
        throw CompanyDoesntExist();
    };
}

void  Market ::  promoteEmployee(int employee_id, int salary_increase, int bump_grade) {
    bool upgrade = UPGRADE;
    if (bump_grade <= 0)
    {
        upgrade = DO_NOT_UPGRADE;
    }
    AVLnode<Employee*,int>* employee_to_promote_node = market_employee_id_tree ->findKey1(employee_id);
    if ( num_of_employees == 0 || employee_to_promote_node == nullptr )
    {
        throw EmployeeDoesNotExist();
    }
    Employee* employee_to_promote  = employee_to_promote_node -> getData();
    int old_salary = employee_to_promote -> getSalary();
    int new_salary = old_salary + salary_increase;
    int company_id = employee_to_promote -> getCompanyId();
    Company* company_hiring = companies_with_employees_tree ->findKey1(company_id) -> getData();
    company_hiring -> promoteEmployeeInCompany(employee_id,salary_increase,upgrade);
    if (num_of_employees == 1)
    {
        AVLnode<Employee*,int>* employee_in_id_node = market_employee_id_tree->findKey1(employee_id);
        employee_in_id_node ->setKey2(new_salary);
        AVLnode<Employee*,int>* employee_in_salary_node = market_employees_salary_tree->find(old_salary,employee_id);
        employee_in_salary_node ->setKey1(new_salary);
    }
    else
    {
        market_employee_id_tree = deleteNode(employee_id,old_salary,market_employee_id_tree);
        market_employee_id_tree = market_employee_id_tree ->insertNew(employee_to_promote,employee_id,new_salary);
        market_employees_salary_tree = deleteNode(old_salary,employee_id,market_employees_salary_tree);
        market_employees_salary_tree = market_employees_salary_tree ->insertNew(employee_to_promote,
                                                                                new_salary,employee_id);
    }
    setHighestEarnerId();
}

void Market:: acquireCompany(int acquirer_id, int target_id, double factor)
{
    if(acquirer_id<=0 || target_id<=0 || target_id==acquirer_id || factor<1.00)
    {
        throw BadInput();
    }
    AVLnode<int,int>* company_buying_info = companies_tree->findKey1(acquirer_id);
    if(num_of_companies ==0 || company_buying_info == nullptr)
    {
        throw CompanyDoesntExist();
    }
    AVLnode<int,int>* company_to_buy_info = companies_tree->findKey1(target_id);
    if(num_of_companies ==0 || company_to_buy_info == nullptr)
    {
        throw CompanyDoesntExist();
    }
    int value_of_buying_company = company_buying_info->getData();
    int value_of_company_to_buy = company_to_buy_info->getData();
    if(value_of_buying_company<10*value_of_company_to_buy)
    {
        throw CompanyValueNotSufficient();
    }
    int new_value = floor((value_of_buying_company + value_of_company_to_buy)*factor);
    company_buying_info->setData(new_value);

    AVLnode<Company*,int>* company_to_buy = companies_with_employees_tree->findKey1(target_id);
    AVLnode<Company*,int>* company_buying = companies_with_employees_tree->findKey1(acquirer_id);
    if(num_of_company_with_employees ==0 || company_to_buy == nullptr)
    {
        companies_tree = deleteNode(target_id,target_id,companies_tree);
        if(num_of_company_with_employees == 0 || company_buying == nullptr)
        {
            return;
        }
        company_buying->getData()->setValue(new_value);
        return;
    }
    Company* company_to_buy_and_delete = company_to_buy->getData();
    if(num_of_company_with_employees == 0 || company_buying == nullptr)
    {
        Company* new_company = new Company(acquirer_id,value_of_buying_company);
        companies_with_employees_tree->insertNew(new_company,acquirer_id,acquirer_id);
        new_company->buyCompany(company_to_buy->getData(),factor);
        companies_with_employees_tree = deleteNode(target_id,target_id,companies_with_employees_tree);
        removeCompany(target_id);
        delete company_to_buy_and_delete;
        return;
    }
    (company_buying->getData())->buyCompany(company_to_buy->getData(),factor);
    companies_with_employees_tree = deleteNode(target_id,target_id,companies_with_employees_tree);
    removeCompany(target_id);
    delete company_to_buy_and_delete;
}


void Market ::getHighestEarner(int company_id, int *employee_id) {
    if (company_id == 0 || employee_id == nullptr)
    {
        throw InvalidInput();
    }
    if (company_id < 0)
    {
        if (num_of_employees == 0)
        {
            throw NoEmployeesInMarket();
        }
        *employee_id = highest_earner_id;
        return;
    }
    else{
        AVLnode<int,int>* company_info = companies_tree ->findKey1(company_id);
        if(num_of_companies == 0 || company_info == nullptr)
        {
            cout << num_of_companies;
            cout << "hrere";
            throw CompanyDoesntExist();
        }
        else
        {
            AVLnode<Company*,int>* company_node = companies_with_employees_tree ->findKey1(company_id);
            if (num_of_company_with_employees == 0 || company_node == nullptr)
            {
                throw CompanyHasNoEmployees();
            }
            Company* company = company_node -> getData();
            company ->getHighestEarner(employee_id);
        }

    }
}
void Market:: getAllEmployeesBySalary(int company_id, int** employees, int* num_of_employees)
{

    if(employees == nullptr || num_of_employees == nullptr || company_id == 0)
    {
        throw BadInput();
    }
    if(company_id<0)
    {
        if(this->num_of_employees == 0)
        {
            throw NoEmployeesInMarket();
        }
        *num_of_employees = this->num_of_employees;
        int** tmp_array = new int*[this->num_of_employees];
        int start =0;
        inReverseOrderToSalaryArray(tmp_array,&start,market_employees_salary_tree);
        employees = tmp_array;
    }
    else
    {
        AVLnode<int,int>* company_info_node = companies_tree->findKey1(company_id);
        if(num_of_companies ==0 || company_info_node == nullptr)
        {
            throw CompanyDoesntExist();
        }
        AVLnode<Company*,int>* company_node = companies_with_employees_tree->findKey1(company_id);
        if(num_of_company_with_employees ==0 || company_node == nullptr)
        {
            throw CompanyHasNoEmployees();
        }
        Company* company = company_node->getData();
        *num_of_employees = company->getNumOfEmployees();
        int** tmp_array = new int*[company->getNumOfEmployees()];
        int start =0;
        inReverseOrderToSalaryArray(tmp_array,&start,company->getEmployeesTreeBySalary());
        employees = tmp_array;
    }
}

void Market:: inReverseOrderToSalaryArray(int** employees_by_salary_array,int* start, AVLnode<Employee*,int>* root )
{
    cout<<"yoyoyo";
    if (root == nullptr) {
        return;
    }
    if (root->getRight() != nullptr) {
        inReverseOrderToSalaryArray(employees_by_salary_array,start,root->getRight());
    }
    *(employees_by_salary_array[*start]) = (root->getData())->getId();
    (*start)++;
    cout<<"did this";
    if (root->getLeft() != nullptr) {
        inReverseOrderToSalaryArray(employees_by_salary_array,start,root->getLeft());
    }
}

//