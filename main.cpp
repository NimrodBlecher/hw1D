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

    Worker* worker21 = new Worker(21, 2, 100, 2);
    Worker* worker22 = new Worker(22, 2, 100, 2);
    Worker* worker23 = new Worker(23, 2, 100, 2);
    Worker* worker24 = new Worker(24,2, 100, 2);
    Worker* worker25 = new Worker(25, 2, 100000, 2);
    Worker* worker13 = new Worker(13, 2, 500, 2);
    Worker* worker14 = new Worker(14, 2, 300, 2);
    Worker* worker15 = new Worker(15, 2, 300, 2);
    Worker* worker16 = new Worker(16,2, 300, 2);


    AVLnode<Worker*,int>* worker21_node = new AVLnode<Worker*,int>(worker21,worker21->getId(),worker21->getSalary());
    AVLnode<Worker*,int>* worker22_node = new AVLnode<Worker*,int>(worker22,worker22->getId(),worker22->getSalary());
    AVLnode<Worker*,int>* worker23_node = new AVLnode<Worker*,int>(worker23,worker23->getId(),worker23->getSalary());
    AVLnode<Worker*,int>* worker24_node = new AVLnode<Worker*,int>(worker24,worker24->getId(),worker24->getSalary());
    AVLnode<Worker*,int>* worker25_node = new AVLnode<Worker*,int>(worker25,worker25->getId(),worker25->getSalary());
    AVLnode<Worker*,int>* worker13_node = new AVLnode<Worker*,int>(worker13,worker13->getId(),worker13->getSalary());
    AVLnode<Worker*,int>* worker14_node = new AVLnode<Worker*,int>(worker14,worker14->getId(),worker14->getSalary());
    AVLnode<Worker*,int>* worker15_node = new AVLnode<Worker*,int>(worker15,worker15->getId(),worker15->getSalary());
    AVLnode<Worker*,int>* worker16_node = new AVLnode<Worker*,int>(worker16,worker16->getId(),worker16->getSalary());


    Company*  google = new Company(1,100);
    Company* microsoft = new Company(2,1000);


    google->hireWorker(worker13_node);
    google->hireWorker(worker14_node);
    google->hireWorker(worker15_node);
    google->hireWorker(worker16_node);
    cout << " Google emplopyees : ";
    print2D(google->getWorkersTreeById());

    cout << endl << endl << endl;


    microsoft->hireWorker(worker21_node);
    microsoft->hireWorker(worker22_node);
    microsoft->hireWorker(worker23_node);
    microsoft->hireWorker(worker24_node);
    microsoft->hireWorker(worker25_node);
    cout << " Microsoft emplopyees : ";
    print2D(microsoft->getWorkersTreeById());
    cout << endl << endl << endl;


    microsoft->buyCompany(google,1.365);

    cout << "Microsoft bought Google:  ";
    print2D(microsoft->getWorkersTreeById());
    cout << endl << endl << endl;
    cout << "new value is :" << microsoft->getValue();
    cout << endl << endl << endl;


    cout << "now Google issssssssssssssssss:  ";
    print2D(google->getWorkersTreeById());


    microsoft->removeWorker(21,100);

    cout << "after firing 21,100" << endl;


    print2D(microsoft->getWorkersTreeById());
    cout << endl << endl << endl << endl;
    print2D(microsoft->getWorkersTreeBySalary());
    cout << endl << endl << endl << endl;

    microsoft->removeWorker(22,100);
    cout << "after firing 22,100" << endl;

    cout << "now Google issssssssssssssssss NUMER 2222:  ";
    print2D(google->getWorkersTreeById());

    print2D(microsoft->getWorkersTreeById());
    cout << endl << endl << endl << endl;
    print2D(microsoft->getWorkersTreeBySalary());
    cout << endl << endl << endl << endl;



    cout << "height is:  "  << microsoft->getWorkersTreeById()->getHeight() << endl;

    microsoft->removeWorker(23,100);
    microsoft->removeWorker(23,1100);
    microsoft->removeWorker(10,100);
    microsoft->removeWorker(24,100);

    cout << "after firing 23,100 24,100" << endl;
    print2D(microsoft->getWorkersTreeById());
    microsoft->removeWorker(25,100000);
    microsoft->removeWorker(13,100);
    cout << "after firing 23,100 24,100 25,100000" << endl;
    print2D(microsoft->getWorkersTreeById());
    cout << endl << endl << endl << endl;
    print2D(microsoft->getWorkersTreeBySalary());
    cout << endl << endl << endl << endl;
    microsoft->removeWorker(13,500);
    microsoft->removeWorker(14,300);
    microsoft->removeWorker(15,300);


    cout << "after firing 13,500 14,300 15,300" << endl;
    print2D(microsoft->getWorkersTreeById());
    cout << endl << endl << endl << endl;
    print2D(microsoft->getWorkersTreeBySalary());
    cout << endl << endl << endl << endl;



    cout << "height is:  "  << microsoft->getWorkersTreeById()->getHeight() << endl;
    microsoft->removeWorker(16,300);
    cout << " should be nothign" << endl;
    print2D(microsoft->getWorkersTreeById());

    if(microsoft->getWorkersTreeById() == nullptr)
    {
        cout << "hehye";
    }

    if((microsoft->getWorkersTreeBySalary()) == nullptr)
    {
    cout << " finally";
    }

    cout << "whoho";
//
//    print2D(google.getWorkersTreeById());
//    print2D(google.getWorkersTreeBySalary());


    delete worker13;
    delete worker14;
    delete worker15;
    delete worker16;
    delete worker21;
    delete worker22;
    delete worker23;
    delete worker24;
    delete worker25;
//
    delete worker13_node;
    delete worker14_node;
    delete worker15_node;
    delete worker16_node;
    delete worker21_node;
    delete worker22_node;
    delete worker23_node;
    delete worker24_node;
    delete worker25_node;


    delete google;
    delete microsoft;

//    int x=1,y=2,z=3;
//    AVLnode<int*,int>* root = new AVLnode<int*,int>(&y,2,2);
//    root->insertNew(&x,1,1);
//    root->insertNew(&z,3,3);
//    deleteTree(root,WITH_DATA);
//    delete root;
//    print2D(root);
    cout<<"bulbul gadolll";

 return 0;
}
