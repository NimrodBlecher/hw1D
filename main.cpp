#include <iostream>
#include "AVLnode.h"
#include "Worker.h"
#include "Company.h"
#include "Employee.h"
#include "Market.h"
using std::cout;
using std::endl;
using namespace hw1;

int main() {


Market highTech;
highTech.addCompany(1,100);
highTech.addCompany(2,1200);
highTech.addCompany(2,1500);
highTech.addWorker(2,1,5,500);
highTech.addWorker(2,2,5,600);
highTech.addWorker(2,3,5,500);
highTech.addWorker(2,4,5,600);
highTech.addWorker(2,5,5,500);
highTech.addWorker(2,6,5,600);



highTech.addWorker(1,15,5,700);
highTech.addWorker(1,1,5,700);
highTech.addWorker(1,2,5,700);
highTech.addWorker(1,16,5,700);
highTech.addWorker(1,17,5,700);



AVLnode<Company*,int>* companies = highTech.getCompaniesTree();
    cout << "Companies By Id is : " << endl;
    cout << endl << endl << endl << endl;
print2D(companies);
cout << "Workers By Id is : " << endl;
cout << endl << endl << endl << endl;
print2D(highTech.getWorkersTreeById());
    cout << "Workers Route By Id is : " << endl;
    cout << endl << endl << endl << endl;
print2D(highTech.getWorkersRouteTree());
    cout << "Workers By Salary Id is : " << endl;
    cout << endl << endl << endl << endl;
print2D(highTech.getWorkersTreeBySalary());
    cout << "Workers In Company 1 is : " << endl;
    cout << endl << endl << endl << endl;
print2D(highTech.getCompany(1) -> getWorkersTreeById());
    cout << "Workers In Company 2 is : " << endl;
    cout << endl << endl << endl << endl;
    print2D(highTech.getCompany(2) -> getWorkersTreeById());

int x,y;
highTech.getCompanyInfo(2,&x,&y);
cout<<"value is: " << x<< "    number of workers is: " << y;

 return 0;
}
