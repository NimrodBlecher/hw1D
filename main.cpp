#include <iostream>
#include "AVLnode.h"
using std::cout;
using std::endl;

int main() {
    AVLnode<int>* root = new AVLnode<int>(15);
    root = root -> insertNew(6);
    root = root -> insertNew(5);
    root = root -> insertNew(3);
    root = root -> insertNew(2);
    root = root -> insertNew(1);
    print2D(root);
    
}
