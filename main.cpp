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

    highTech.addCompany(1,100);
    highTech.addCompany(2,10);
    highTech.addCompany(3,1);
    highTech.addCompany(4,400000000);
    highTech.addCompany(5,20000);
    highTech.addCompany(6,10);

    highTech.addEmployee(1,11,1,100);
    highTech.addEmployee(1,12,1,100);
    highTech.addEmployee(1,13,1,100);
    highTech.addEmployee(2,21,2,200);
    highTech.addEmployee(2,22,2,200);
    highTech.addEmployee(2,23,2,200);
    highTech.addEmployee(3,32,3,300);
    highTech.addEmployee(3,31,3,300);
    highTech.addEmployee(3,30,3,300);

    highTech.promoteEmployee(31,5000,1);
    highTech.acquireCompany(5,6,10);
    cout<<endl << "company tree is: " <<endl;
    print2D(highTech.getCompaniesTree());
    cout<<endl << "companies with employees tree is: " <<endl;
    print2D(highTech.getCompaniesTreeWithEmployees());
    cout<<endl << " employees tree is: " <<endl;
    print2D(highTech.getEmployeesTreeById());
    cout<<endl << " employees tree in 1  is: " <<endl;
    print2D((highTech.getCompany(1))->getEmployeesTreeById());
    cout<<endl << " employees tree in 2  is: " <<endl;
    print2D((highTech.getCompany(2))->getEmployeesTreeById());

    int num_of_employees,value;

    //highTech.acquireCompany(1,2,6);
    cout << "company 1 info is :" << endl;
    highTech.getCompanyInfo(1,&value,&num_of_employees);
    cout << value << " " << num_of_employees << endl;
    cout << "company 5 info is :" << endl;
    highTech.getCompanyInfo(5,&value,&num_of_employees);
    cout << value << " " << num_of_employees << endl;


    cout<<endl << "company tree is: " <<endl;
    print2D(highTech.getCompaniesTree());
    cout<<endl << "companies with employees tree is: " <<endl;

    print2D(highTech.getCompaniesTreeWithEmployees());
    cout<<endl << " employees tree is: " <<endl;
    print2D(highTech.getEmployeesTreeById());
    cout<<endl << " employees tree in 1  is: " <<endl;
    print2D((highTech.getCompany(1))->getEmployeesTreeById());
    cout<<endl << " employees tree in 1 by salary is: " <<endl;
    print2D((highTech.getCompany(1))->getEmployeesTreeBySalary());
//    cout<<endl << " employees tree in 2  is: " <<endl;
//    print2D((highTech.getCompany(2))->getEmployeesTreeById());
    highTech.getCompanyInfo(1,&value,&num_of_employees);

    int highest_earner;
    highTech.getHighestEarner(1,&highest_earner);
    cout << "highest earner in company 1 is  " << highest_earner << endl;

    highTech.getHighestEarner(-3,&highest_earner);
    cout << "highest earner in the market is  " << highest_earner << endl;

    highTech.promoteEmployee(13,500000,1);

    highTech.getHighestEarner(1,&highest_earner);
    cout << "highest earner in company 1 is  " << highest_earner << endl;

    highTech.getHighestEarner(-3,&highest_earner);
    cout << "highest earner in the market is  " << highest_earner << endl;

   highTech.acquireCompany(1,3,6);

    highTech.promoteEmployee(22,6000000,1);

    highTech.getHighestEarner(1,&highest_earner);
    cout << "highest earner in company 1 is  " << highest_earner << endl;

    highTech.getHighestEarner(-9,&highest_earner);
    cout << "highest earner in the market is  " << highest_earner << endl;

    highTech.removeEmployee(22);

    highTech.getHighestEarner(1,&highest_earner);
    cout << "highest earner in company 1 is  " << highest_earner << endl;

    highTech.getHighestEarner(-9,&highest_earner);
    cout << "highest earner in the market is  " << highest_earner << endl;

    cout<<endl<<endl<<endl<<endl;
    print2D(highTech.getEmployeesTreeBySalary());


    cout<<endl << "companies with employees tree is: " <<endl;

    print2D(highTech.getCompaniesTreeWithEmployees());

    int** test;
    int*  number;
    //highTech.getAllEmployeesBySalary(-9,test,number);
    cout << "num of cmp with emp : " << highTech.getNumOfCompaniesWithEmp() << endl;
    cout << "num of emp : " << highTech.getNumOfEmployees() << endl;
    highTech.getHighestEarnerInEachCompany(2,test);
    cout<< "finished" <<endl;
    for ( int i= 0; i <2 ; i++)
    {
        cout<<*test[i] << "<-----num" << endl;
    }


    highTech.removeEmployee(11);
    highTech.removeEmployee(12);
    highTech.removeEmployee(13);
    highTech.removeEmployee(21);
    highTech.removeEmployee(23);
    highTech.removeEmployee(31);
    highTech.removeEmployee(32);
    highTech.removeEmployee(30);


    highTech.removeCompany(1);
    highTech.removeCompany(2);
    //highTech.removeCompany(3);
    highTech.removeCompany(4);
    highTech.removeCompany(5);



//    cout<<endl << "company tree is: " <<endl;
//    print2D(highTech.getCompaniesTree());
//    cout<<endl << "companies with employees tree is: " <<endl;
//
//    print2D(highTech.getCompaniesTreeWithEmployees());
//    cout<<endl << " employees tree is: " <<endl;
//    print2D(highTech.getEmployeesTreeById());
//    cout<<endl << " employees tree in 1  is: " <<endl;
//    print2D((highTech.getCompany(1))->getEmployeesTreeById());
//    cout<<endl << " employees tree in 1 by salary is: " <<endl;
//    print2D((highTech.getCompany(1))->getEmployeesTreeBySalary());
////    cout<<endl << " employees tree in 2  is: " <<endl;
////    print2D((highTech.getCompany(2))->getEmployeesTreeById());
//    highTech.getCompanyInfo(1,&value,&num_of_employees);





return 0;
}