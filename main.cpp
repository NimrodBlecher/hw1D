#include <iostream>
#include "AVLnode.h"
#include "Employee.h"
#include "Company.h"
#include "Market.h"
using std::cout;
using std::endl;
using namespace hw1;

int main() {

    Market highTech;

    highTech.addCompany(20,200000);
    highTech.addCompany(10,33333);
    highTech.addCompany(40,4646546);
    highTech.addCompany(30,999999);

    highTech.addEmployee(10,11,5,600);
    highTech.addEmployee(20,21,13,600);
    highTech.addEmployee(10,12,5,600);
    highTech.addEmployee(20,22,13,600);
    highTech.addEmployee(30,31,5,600);
    highTech.addEmployee(40,41,13,600);
    highTech.addEmployee(40,42,5,600);
    highTech.addEmployee(30,32,13,600);


//    AVLnode<int,int>* companies = highTech.getCompaniesTree();
//    cout << "Companies By Id is : " << endl;
//    cout << endl << endl << endl << endl;
//    print2D(companies);
//    cout << "Employees By Id is : " << endl;
//    cout << endl << endl << endl << endl;
//    print2D(highTech.getEmployeesTreeById());


    highTech.removeEmployee(11);
    highTech.removeEmployee(21);
    highTech.removeEmployee(22);
    cout << "after removing employee 21,22 , and Company 20 along :  ";
    print2D(highTech.getCompaniesTreeWithEmployees());
    cout << endl << endl << endl;
    highTech.addEmployee(20,21,10,66);
    highTech.addEmployee(20,22,10,66);
    highTech.addEmployee(20,23,10,33);
    highTech.addEmployee(20,24,10,33);
    highTech.addEmployee(20,25,10,55);
    highTech.addEmployee(20,26,10,55);
    highTech.addEmployee(20,27,10,77);
    highTech.addEmployee(20,28,10,77);
    highTech.addEmployee(20,29,10,77);
    int salary,grade,company_id;
    highTech.getEmployeeInfo(27,&company_id,&salary,&grade);
    cout << " employee 27 info :" << company_id << " " << salary << " " << grade << endl;
    int num_of_employees,value;
    highTech.getCompanyInfo(40,&value,&num_of_employees);
    cout << " Company 40 info :" << company_id << " " << value << " " << num_of_employees << endl;
    cout << "after renew company 20 :  ";
    print2D(highTech.getCompaniesTreeWithEmployees());
    print2D(highTech.getCompany(20)-> getEmployeesTreeById());
    highTech.removeEmployee(31);
    highTech.removeEmployee(12);
    highTech.removeCompany(10);
    highTech.removeEmployee(41);
    highTech.removeEmployee(42);
    highTech.removeEmployee(32);
    highTech.getCompanyInfo(30,&value,&num_of_employees);
    cout << " Company 30 info :" << company_id << " " << value << " " << num_of_employees << endl;
    highTech.removeCompany(30);
    highTech.removeCompany(40);
    highTech.removeEmployee(21);
    highTech.removeEmployee(22);
    highTech.removeEmployee(23);
    highTech.removeEmployee(24);
    highTech.removeEmployee(25);
    highTech.removeEmployee(26);
    highTech.removeEmployee(27);
    highTech.removeEmployee(28);
    highTech.removeEmployee(29);
    highTech.removeCompany(20);
    print2D(highTech.getCompaniesTreeWithEmployees());
    print2D(highTech.getCompaniesTree());
    print2D(highTech.getEmployeesTreeById());
    print2D(highTech.getEmployeesTreeBySalary());

//    Company* company_20 = highTech.getCompany(20);
////    print2D(company_20->getEmployeesTreeById());
//   Company* company_10 = highTech.getCompany(10);
////    print2D(company_10->getEmployeesTreeById());
//
//
//    print2D(highTech.getCompaniesTreeWithEmployees());



//    print2D(company_20->getEmployeesTreeById());
//    print2D(company_10->getEmployeesTreeById());









return 0;
}