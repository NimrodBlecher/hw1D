//#include "Market.h"
//
//// ewfwerfwerfwef
//void inOrderToEmployeesArray(int** employees_array,int* start, AVLnode<Company*,int>* root,int* times_left);
//
//void Market ::getHighestEarnerInEachCompany(int number_of_companies_to_find, int **employees_by_id) {
//    if (number_of_companies_to_find == 0 || employees_by_id == nullptr)
//    {
//        throw InvalidInput();
//    }
//    if (num_of_company_with_employees < number_of_companies_to_find)
//    {
//        throw NotEnoughCompaniesWithEmployees();
//    }
//    int** array_to_return = new int*[number_of_companies_to_find];
//    int x = 0 , y = number_of_companies_to_find;
//    AVLnode<Company*,int>* root = companies_with_employees_tree;
//    inOrderToEmployeesArray(array_to_return,&x,root,&y);
//    employees_by_id = array_to_return;
//}
//
//
//
//void inOrderToEmployeesArray(int** employees_array,int* start, AVLnode<Company*,int>* root,int* times_left)
//{
//    if (root == nullptr || *times_left == 0) {
//        return;
//    }
//    if (root->getLeft() != nullptr && *times_left > 0) {
//        inOrderToEmployeesArray(employees_array,start,root->getLeft(),times_left);
//    }
////        cout << root->getKey1() << ", " << endl;
////        cout << "start is : " << *start << endl;
//    root -> getData() ->getHighestEarner(employees_array[*start]);
//    (*start)++;
//    (*times_left)--;
//    if (root->getRight() != nullptr && *times_left > 0) {
//        inOrderToEmployeesArray(employees_array, start, root->getRight(),times_left);
//    }
//}
//
//
//



