#include <iostream>
#include "AVLnode.h"
#include "Worker.h"
#include "Company.h"
#include "Employee.h"
using std::cout;
using std::endl;

int main() {
    Worker worker1(2, 2, 2, 2);
    AVLnode<Worker,int>* root = new AVLnode<Worker,int>(worker1,worker1.getId(),worker1.getSalary());
    Worker worker2(2, 2, 25, 2);
    root = root -> insertNew(worker2,worker2.getId(),worker2.getSalary());
    Worker worker3(2, 2, 1, 2);
    root = root -> insertNew(worker3,worker3.getId(),worker3.getSalary());
    Worker worker4(2,2, 66, 2);
    root = root -> insertNew(worker4,worker4.getId(),worker4.getSalary());
    Worker worker5(43, 2, 1, 2);
    root = root -> insertNew(worker5,worker5.getId(),worker5.getSalary());
    Worker worker6(46, 2, 1, 2);
    root = root -> insertNew(worker6,worker6.getId(),worker6.getSalary());
    Worker worker7(48,2, 6, 2);
    root = root -> insertNew(worker7,worker7.getId(),worker7.getSalary());
    Worker worker8(131, 2, 1, 2);
    root = root -> insertNew(worker8,worker8.getId(),worker8.getSalary());
    Worker worker9(292,2, 6, 2);
    root = root -> insertNew(worker9,worker9.getId(),worker9.getSalary());
    Worker worker10(433, 2, 1, 2);
    root = root -> insertNew(worker10,worker10.getId(),worker10.getSalary());
    Worker worker11(466, 2, 1, 2);
    root = root -> insertNew(worker11,worker11.getId(),worker11.getSalary());
    Worker worker12(1,2, 6, 2);
    root = root -> insertNew(worker12,worker12.getId(),worker12.getSalary());
    print2D(root);
    cout << endl;

// tree  2 :
    Worker worker13(2, 2, 54954, 2);
    AVLnode<Worker,int>* root2 = new AVLnode<Worker,int>(worker13,worker13.getId(),worker13.getSalary());
    Worker worker14(2, 2, 965425, 2);
    root2 = root2 -> insertNew(worker14,worker14.getId(),worker14.getSalary());
    Worker worker15(93, 2, 1, 2);
    root2 = root2 -> insertNew(worker15,worker15.getId(),worker15.getSalary());
    Worker worker16(94,2, 66, 2);
    root2 = root2 -> insertNew(worker16,worker16.getId(),worker16.getSalary());
    Worker worker17(95, 2, 1, 2);
    root2 = root2 -> insertNew(worker17,worker17.getId(),worker17.getSalary());
    Worker worker18(96, 2, 1, 2);
    root2 = root2 -> insertNew(worker18,worker18.getId(),worker18.getSalary());
    Worker worker19(97,2, 6, 2);
    root2 = root2 -> insertNew(worker19,worker19.getId(),worker19.getSalary());
    Worker worker20(333, 2, 1, 2);
    root2 = root2 -> insertNew(worker20,worker20.getId(),worker20.getSalary());
    Worker worker21(3334,2, 6, 2);
    root2 = root2 -> insertNew(worker21,worker21.getId(),worker21.getSalary());


    print2D(root2);
    cout << endl;

    AVLnode<Worker,int>* tree3 = mergeTrees(root,root2);
    tree3->deleteTree();
    delete tree3;
    //tree3 = root2;

    cout << endl << endl << endl;
    cout << "after delete";
    cout << tree3 -> getKey1();
    print2D(tree3);

 return 0;
}
