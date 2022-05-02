#include "Market.h"

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
    company_hiring -> promoteEmployee(employee_id,salary_increase,upgrade);
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

}
