#include <iostream>
#include "AVLnode.h"
#include "Employee.h"
#include "Company.h"
#include "Market.h"
using std::cout;
using std::endl;
using namespace hw1;

int main() {


Market highTech;highTech.addEmployee(2,4,5,600);

highTech.addCompany(1,100);
highTech.addCompany(2,1200);
highTech.addCompany(2,1500);

highTech.addEmployee(2,1,5,500);
highTech.addEmployee(2,2,5,600);
highTech.addEmployee(2,3,5,500);
highTech.addEmployee(2,4,5,600);
highTech.addEmployee(2,5,5,500);
highTech.addEmployee(2,6,5,600);



highTech.addEmployee(1,15,5,700);
highTech.addEmployee(1,1,5,700);
highTech.addEmployee(1,2,5,700);
highTech.addEmployee(1,16,5,700);
highTech.addEmployee(1,17,5,700);



AVLnode<Company*,int>* companies = highTech.getCompaniesTree();
    cout << "Companies By Id is : " << endl;
    cout << endl << endl << endl << endl;
print2D(companies);
cout << "Employees By Id is : " << endl;
cout << endl << endl << endl << endl;
print2D(highTech.getEmployeesTreeById());
    cout << "Employees Route By Id is : " << endl;
    cout << endl << endl << endl << endl;
print2D(highTech.getEmployeesRouteTree());
    cout << "Employees By Salary Id is : " << endl;
    cout << endl << endl << endl << endl;
print2D(highTech.getEmployeesTreeBySalary());
    cout << "Employees In Company 1 is : " << endl;
    cout << endl << endl << endl << endl;
print2D(highTech.getCompany(1) -> getEmployeesTreeById());
    cout << "Employees In Company 2 is : " << endl;
    cout << endl << endl << endl << endl;
    print2D(highTech.getCompany(2) -> getEmployeesTreeById());

int x,y;
highTech.getCompanyInfo(2,&x,&y);
cout<<"value is: " << x<< "    number of employees is: " << y;

 return 0;
}
