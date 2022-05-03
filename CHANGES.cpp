#include "Market.h"



Market :: ~Market() {
    deleteTreeWithData(companies_tree);
    deleteTree(market_employees_salary_tree);
    deleteTree(companies_with_employees_tree);
    deleteTree(market_employee_id_tree);
};




Company :: ~Company() {
    deleteTree(employees_tree_by_salary);
    deleteTreeWithData(employees_tree_by_id);
}


template<class Data, class Key>
void deleteTreeWithData(AVLnode<Data,Key>* root) {
    if(root == nullptr)
    {
        return;
    }
    if (root->getRight() == nullptr && root->getLeft() == nullptr) {
        delete (root -> getData());
        delete root;
        return;
    }
    if (root->getLeft() != nullptr) {
        deleteTree(root->getLeft());
        root -> setLeft(nullptr);
    }
    if (root->getRight() != nullptr) {
        deleteTree(root->getRight());
        root ->setRight(nullptr);
    }
    delete (root -> getData());
    deleteTree(root);
}










}

