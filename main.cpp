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

    Worker worker21(21, 2, 100, 2);
    Worker worker22(22, 2, 100, 2);
    Worker worker23(23, 2, 100, 2);
    Worker worker24(24,2, 100, 2);
    Worker worker25(25, 2, 100000, 2);
    Worker worker13(13, 2, 500, 2);
    Worker worker14(14, 2, 300, 2);
    Worker worker15(15, 2, 300, 2);
    Worker worker16(16,2, 300, 2);


    AVLnode<Worker,int>* worker21_node = new AVLnode<Worker,int>(worker21,worker21.getId(),worker21.getSalary());
    AVLnode<Worker,int>* worker22_node = new AVLnode<Worker,int>(worker22,worker22.getId(),worker22.getSalary());
    AVLnode<Worker,int>* worker23_node = new AVLnode<Worker,int>(worker23,worker23.getId(),worker23.getSalary());
    AVLnode<Worker,int>* worker24_node = new AVLnode<Worker,int>(worker24,worker24.getId(),worker24.getSalary());
    AVLnode<Worker,int>* worker25_node = new AVLnode<Worker,int>(worker25,worker25.getId(),worker25.getSalary());
    AVLnode<Worker,int>* worker13_node = new AVLnode<Worker,int>(worker13,worker13.getId(),worker13.getSalary());
    AVLnode<Worker,int>* worker14_node = new AVLnode<Worker,int>(worker14,worker14.getId(),worker14.getSalary());
    AVLnode<Worker,int>* worker15_node = new AVLnode<Worker,int>(worker15,worker15.getId(),worker15.getSalary());
    AVLnode<Worker,int>* worker16_node = new AVLnode<Worker,int>(worker16,worker16.getId(),worker16.getSalary());


    Company google(1,100);
    Company microsoft(2,1000);


    google.hireWorker(worker13_node);
    google.hireWorker(worker14_node);
    google.hireWorker(worker15_node);
    google.hireWorker(worker16_node);
    cout << " Google emplopyees : ";
    print2D(google.getWorkersTreeById());

    cout << endl << endl << endl;


    microsoft.hireWorker(worker21_node);
    microsoft.hireWorker(worker22_node);
    microsoft.hireWorker(worker23_node);
    microsoft.hireWorker(worker24_node);
    microsoft.hireWorker(worker25_node);
    cout << " Microsoft emplopyees : ";
    print2D(microsoft.getWorkersTreeById());
    cout << endl << endl << endl;


    //AVLnode<AVLnode<Worker,int>*,int>* new_microsoft_workers = mergeTrees(google.getWorkersTreeById(),microsoft.getWorkersTreeById()) ;
    //microsoft.setNewWorkersTreeById(new_microsoft_workers);

    //microsoft.buyCompany(&google,6);

    cout << "Microsoft bought Google:  ";
    print2D(microsoft.getWorkersTreeById());
    cout << endl << endl << endl;

//        google.removeWorker(22,100);
//      google.removeWorker(14,300);
//        google.removeWorker(24,10);
//        google.removeWorker(21,100);
//        google.removeWorker(15,100);
//    google.removeWorker(15,300);


    delete worker21_node;
    delete worker22_node;
    delete worker23_node;
    delete worker24_node;
    delete worker25_node;
    delete worker13_node;
    delete worker14_node;
    delete worker15_node;
    delete worker16_node;



//    print2D(google.getWorkersTreeById());
//    cout << endl << endl << endl << endl;
//    print2D(google.getWorkersTreeBySalary());
//    cout << endl << endl << endl << endl;
//    cout << "height is:  "  << google.getWorkersTreeById()->getHeight() << endl;
//

////
//    cout << "after firing" << endl;
////
//    print2D(google.getWorkersTreeById());
//    cout << endl << endl << endl << endl;
//    print2D(google.getWorkersTreeBySalary());
//    cout << endl << endl << endl << endl;
//
//    int highest_earner = 0;
//    google.getHighestEarner(&highest_earner);
//    cout << "highest earner is : " << endl;
//    cout << highest_earner;
//    cout << endl;
//
//   cout << "height is:  "  <<google.getWorkersTreeById()->getHeight() << endl;
//





 return 0;
}
