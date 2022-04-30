#ifndef HW1_AVLNODE_H
#define HW1_AVLNODE_H



#include <iostream>
#include "math.h"
#include "exceptions.h"
#define LEFT 1
#define RIGHT 2
#define WITH_DATA true
#define WITHOUT_DATA false
#include "helpers.h"


namespace hw1 {

    using std::cout;
    using std::endl;

    template<class Data, class Key>
    class AVLnode {
        Key key1;
        Key key2;
        Data data;
        AVLnode *left;
        AVLnode *right;
        AVLnode *parent;
        int height = 0;
    public:
        AVLnode();

        ~AVLnode() = default;

        AVLnode(int key1, int key2);

        explicit AVLnode(Data data, Key key1, Key key2);

        int getHeight();

        void setHeight();

        void updateHeightAfterRotate(AVLnode<Data, Key> *new_root);

        int getLoadFactor();

        Data getData();

        Key getKey1();

        void setKey1(Key key);

        void setKey2(Key key);

        Key getKey2();

        AVLnode *getLeft();

        AVLnode *getRight();

        AVLnode *getParent();

        void setRight(AVLnode<Data, Key> *right);

        void setLeft(AVLnode<Data, Key> *left);

        void setParent(AVLnode<Data, Key> *left);

        void setData(Data new_data);

        AVLnode *insertNew(Data data, Key key1, Key key2);

        AVLnode *fixToRoot();

        AVLnode<Data, Key> *findMax(AVLnode<Data, Key> *start);

        AVLnode *balanceTree();

        AVLnode *rotateLL();

        AVLnode *rotateLR();

        AVLnode *rotateRR();

        AVLnode *rotateRL();

        AVLnode *find(Key A, Key B);

        void inOrder();

        void postOrder();

        AVLnode<Data, Key> **inOrderToArray(AVLnode<Data, Key> *array[], int *start, AVLnode<Data, Key> *root);

        AVLnode<Data, Key> *insertInOrder(AVLnode<Data, Key> *array[], int *start, AVLnode<Data, Key> *root);

        AVLnode<Data, Key> *createEmptyTree(int height, int *leaves_left, AVLnode<Data, Key> *root);


        template<class A, class B>
        friend bool operator<(const AVLnode<A, B> &node1, const AVLnode<A, B> &node2);

        template<class A, class B>
        friend bool operator==(const AVLnode<A, B> &node1, const AVLnode<A, B> &node2);
    };
    template<class Data, class Key>
    void free_node(AVLnode<Data,Key>* node);


    template<class Data, class Key>
    void our_delete(AVLnode<Data,Key>* node, bool data)
    {
        if(data == WITH_DATA)
        {
            if( node -> getData() != nullptr)
            {
                delete (node -> getData());
            }
        }
                delete node;
    }

    template<class Data, class Key>
    AVLnode<Data, Key>::AVLnode() : key1(0), key2(0), left(nullptr), right(nullptr), parent(nullptr) {};


    template<class Data, class Key>
    AVLnode<Data, Key>::AVLnode(int key1, int key2) : key1(key1), key2(key2), left(nullptr), right(nullptr),
                                                      parent(nullptr) {};


    template<class Data, class Key>
    AVLnode<Data,Key>* AVLnode<Data, Key> ::getParent() {
        return  parent;
    }

//    template<class Data, class Key>
//    void AVLnode<Data, Key>::deleteTree() {
//        if (this->left == nullptr && this->right == nullptr) {
//            delete this;
//            return;
//        }
//        if (this->left != nullptr) {
//            this->left->deleteTree();
//        }
//        if (this->right != nullptr) {
//            this->right->deleteTree();
//        }
//        delete this;
//    }
    template<class Data, class Key>
    void deleteTree(AVLnode<Data,Key>* root);

    template<class Data, class Key>
    void deleteTree(AVLnode<Data,Key>* root,bool data) {
        if(root == nullptr)
        {
            return;
        }
        if (root->getRight() == nullptr && root->getLeft() == nullptr) {
            our_delete(root,data);
            return;
        }
        if (root->getLeft() != nullptr) {
            our_delete(root->getLeft(),data);
        }
        if (root->getRight() != nullptr) {
            our_delete(root->getRight(),data);
        }
        our_delete(root,data);
    }

    template<class Data, class Key>
    void AVLnode<Data, Key>::setRight(AVLnode<Data, Key> *right) {
        this->right = right;
    }

    template<class Data, class Key>
    void AVLnode<Data, Key>::setLeft(AVLnode<Data, Key> *left) {
        this->left = left;
    }

    template<class Data, class Key>
    void AVLnode<Data, Key>::setParent(AVLnode<Data, Key> *new_parent) {
        this -> parent = new_parent;
    }

    template<class Data, class Key>
    void AVLnode<Data, Key>::setData(Data new_data) {
        this -> data = new_data;
    }


    template<class Data, class Key>
    void AVLnode<Data, Key>::setKey1(Key key) {
        key1 = key;
    }


    template<class Data, class Key>
    void AVLnode<Data, Key>::setKey2(Key key) {
        key2 = key;
    }


    template<class Data, class Key>
    AVLnode<Data, Key> *mergeTrees(AVLnode<Data, Key> *root1, AVLnode<Data, Key> *root2,bool data);


    template<class Data, class Key>
    AVLnode<Data, Key> *mergeTrees(AVLnode<Data, Key> *root1, AVLnode<Data, Key> *root2,bool data) {
        int start1 = 0, start2 = 0;
        AVLnode<Data, Key> **tree1_array = new AVLnode<Data, Key> *[(int) pow(2, root1->getHeight() + 1)];
        for (int i = 0; i < pow(2, root1->getHeight() + 1); i++) {
            tree1_array[i] = nullptr;
        }
        tree1_array = root1->inOrderToArray(tree1_array, &start1, root1);
        int num_of_nodes1 = 0, num_of_nodes2 = 0;

        AVLnode<Data, Key> **tree1_array_start = tree1_array;

        while (*tree1_array != nullptr) {
            num_of_nodes1++;
            *tree1_array++;
        }
//        cout << "hi" << endl;
        AVLnode<Data, Key> **tree2_array = new AVLnode<Data, Key> *[(int) pow(2, root2->getHeight() + 1)];
        for (int i = 0; i < pow(2, root2->getHeight() + 1); i++) {
            tree2_array[i] = nullptr;
        }
        tree2_array = root2->inOrderToArray(tree2_array, &start2, root2);

        AVLnode<Data, Key> **tree2_array_start = tree2_array;

        while (*tree2_array != nullptr) {
            num_of_nodes2++;
            *tree2_array++;
        }

//        cout << "nodes are " << endl << num_of_nodes1 << "," << num_of_nodes2 << endl;
        AVLnode<Data, Key> **merged_trees_array = new AVLnode<Data, Key> *[(int) (pow(2, root1->getHeight() + 1) +
                                                                                  pow(2, root2->getHeight() + 1))];
        for (int i = 0; i < pow(2, root1->getHeight() + 1) + pow(2, root2->getHeight() + 1); i++) {
            merged_trees_array[i] = nullptr;
        }
        ///// UP until now i have a both trees in sorted array -  i have to merge the arrays, and then create a almost empty tree and insert the merged array in order
        merge_ordered_arrays(tree1_array_start, tree2_array_start, merged_trees_array);
        AVLnode<Data, Key> **merged_trees_array_start = merged_trees_array;

        // now i have an ordered array of all workers and the end of it is nullptr
        int semi_full_tree_height = floor(
                log2(num_of_nodes1 + num_of_nodes2));
//        cout << "num1 is " << num_of_nodes1 << "and numb 2 is : "
//             << num_of_nodes2;// <----------------------- calculate the new tree height
//        cout << " number is:" << semi_full_tree_height << "fuck me" << endl;
        AVLnode<Data, Key> *merged_tree = new AVLnode<Data, Key>;
        int diff_from_full = pow(2, semi_full_tree_height + 1) - 1 - num_of_nodes2 - num_of_nodes1;
        int leaves_left = pow(2, semi_full_tree_height) - diff_from_full;
//        cout << "sdefsdfsdfsdfsdfs  " << semi_full_tree_height;
//        cout << "              Sadfsdfdsfsdfsdfsd" << leaves_left;
        merged_tree = merged_tree->createEmptyTree(semi_full_tree_height, &leaves_left, merged_tree);
//    merged_tree->createEmptyFullTree(semi_full_tree_height, merged_tree);
//    print2D(merged_tree);
//    cout << endl << endl << endl;
//    int diff_from_full = pow(2, semi_full_tree_height + 1) - 1 - num_of_nodes2 - num_of_nodes1;
//    cout << "diff from full is :" << diff_from_full << endl;
//    merged_tree = merged_tree->createSemiFullTree(diff_from_full);
//    print2D(merged_tree);
        int start = 0;
        merged_tree->insertInOrder(merged_trees_array, &start, merged_tree);
//        cout << "got out of the func" << endl;
        deleteTree(root1,data);
        deleteTree(root2,data);
        return merged_tree;
    }


    template<class Data, class Key>
    void
    merge_ordered_arrays(AVLnode<Data, Key> *source1, AVLnode<Data, Key> *source2, AVLnode<Data, Key> *destination);


    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::createEmptyTree(int height, int *leaves_left, AVLnode<Data, Key> *root) {
        if (height == 0) {
            (*leaves_left)--;
            return root;
        }
        if (*leaves_left == 0 && height == 1) {
            return root;
        }
        root->height = height;
        AVLnode<Data, Key> *new_node_left = new AVLnode<Data, Key>;
        root->left = createEmptyTree(height - 1, leaves_left, new_node_left);
        root->left = new_node_left;
        new_node_left->parent = root;
        if (*leaves_left == 0 && height == 1) {
            return root;
        }
        AVLnode<Data, Key> *new_node_right = new AVLnode<Data, Key>;

        root->right = createEmptyTree(height - 1, leaves_left, new_node_right);
        root->right = new_node_right;
        new_node_right->parent = root;
        return root;
    }

    template<class Data, class Key>
    AVLnode<Data, Key> *
    AVLnode<Data, Key>::insertInOrder(AVLnode<Data, Key> **array, int *start, AVLnode<Data, Key> *root) {
//        cout << "im here" << endl;
        if (root == nullptr) {
//            cout << "null ptr" << endl;
            return nullptr;
        }
        if (root->left != nullptr) {
//            cout << "left " << endl;
            root->left = root->left->insertInOrder(array, start, root->left);

        }
//        cout << "middle" << endl;
        root->data = ((array)[*start])->getData();
        root->key1 = ((array)[*start])->getKey1();
        root->key2 = ((array)[*start])->getKey2();
//        cout << (*array)->getKey1() << endl;
        (*start)++;

        if (root->right != nullptr) {
//            cout << "right" << endl;
            root->right = root->right->insertInOrder(array, start, root->right);
        }
        return this;
    }


    template<class Data, class Key>
    bool operator<(const AVLnode<Data, Key> &node1, const AVLnode<Data, Key> &node2) {
        if (node1.key1 < node2.key1) {
            return true;
        } else if (node1.key1 == node2.key1) {
            return node1.key2 < node2.key2;
        }
        return false;
    }

    template<class Data, class Key>
    bool operator == (const AVLnode<Data, Key> &node1, const AVLnode<Data, Key> &node2) {
        return (node1.key1 == node2.key1 && node1.key2 == node2.key2);
    }

    template<class Data, class Key>
    bool operator > (const AVLnode<Data, Key> &node1, const AVLnode<Data, Key> &node2) {
        if (node1 < node2 || node1 == node2) {
            return false;
        }
        return true;
    }

    template<class Data, class Key>
    bool operator!=(const AVLnode<Data, Key> &node1, const AVLnode<Data, Key> &node2) {
        return !(node1 == node2);
    }


    template<class Data, class Key>
    void print2DUtil(AVLnode<Data, Key> *root, int space) {
        // Base case
        if (root == nullptr)
            return;

        // Increase distance between levels
        space += 10;

        // Process right child first
        print2DUtil(root->getRight(), space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << root->getKey1() <<"," << root->getKey2() << "\n";

        // Process left child
        print2DUtil(root->getLeft(), space);
    }

// Wrapper over print2DUtil()
    template<class Data, class Key>
    void print2D(AVLnode<Data, Key> *root) {
        // Pass initial space count as 0
        print2DUtil(root, 0);
    }


    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::getLeft() {
        return this->left;
    }

    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::getRight() {
        return this->right;
    }


    template<class Data, class Key>
    Data AVLnode<Data, Key>::getData() {
        return data;
    }

    template<class Data, class Key>
    Key AVLnode<Data, Key>::getKey1() {
        return key1;
    }

    template<class Data, class Key>
    Key AVLnode<Data, Key>::getKey2() {
        return key2;
    }

    template<class Data, class Key>
    AVLnode<Data, Key>::AVLnode(Data data, Key key1, Key key2) :
            data(data), key1(key1), key2(key2), left(nullptr), right(nullptr), parent(nullptr), height(0) {};

    template<class Data, class Key>
    int AVLnode<Data, Key>::getHeight() {
        return height;
    }

    template<class Data, class Key>
    void AVLnode<Data, Key>::updateHeightAfterRotate(AVLnode<Data, Key> *new_root) {
        if (new_root->left != nullptr) {
            new_root->left->setHeight();
        }
        if (new_root->right != nullptr) {
            new_root->right->setHeight();
        }
        new_root->setHeight();
    }


    template<class Data, class Key>
    void AVLnode<Data, Key>::setHeight() {
        int left_height = -1;
        int right_height = -1;
        if (this->left != nullptr) {
            left_height = this->left->getHeight();
        }
        if (this->right != nullptr) {
            right_height = this->right->getHeight();
        }
        this->height = max(left_height, right_height) + 1;
    }

    template<class Data, class Key>
    int AVLnode<Data, Key>::getLoadFactor() {
        int left_height = -1;
        int right_height = -1;
        if (this->left != nullptr) {
            left_height = this->left->getHeight();
        }
        if (this->right != nullptr) {
            right_height = this->right->getHeight();
        }
        return left_height - right_height;
    }

    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::fixToRoot() {
        AVLnode<Data, Key> *node = this;
        while (node != nullptr) {
            node->setHeight();
            node = node->balanceTree();
            if (node->parent == nullptr) {
                return node;
            }
            node = node->parent;
        }
        return nullptr;
    }


    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::insertNew(Data data, Key key1, Key key2) {
        AVLnode<Data, Key> *insert_node = this;
        AVLnode<Data, Key> *new_node = new AVLnode(data, key1, key2);
        while (insert_node != nullptr) {
            if (*new_node < *insert_node) {
                if (insert_node->left == nullptr) {
                    insert_node->left = new_node;
                    break;
                }
                insert_node = insert_node->left;
                continue;
            } else if (*insert_node < *new_node) {
                if (insert_node->right == nullptr) {
                    insert_node->right = new_node;
                    break;
                }
                insert_node = insert_node->right;
                continue;
            } else {
                our_delete(new_node,WITH_DATA);
                return this;
            }
        }
        new_node->parent = insert_node;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node->fixToRoot();
    }

    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::find(Key A, Key B) {
        AVLnode<Data, Key> *node_to_find = new AVLnode<Data, Key>(A, B);
        AVLnode<Data, Key> *find_node = this;
        while (find_node != nullptr) {
            if (*find_node < *node_to_find) {
                find_node = find_node->right;
                continue;
            } else if (*find_node > *node_to_find) {
                find_node = find_node->left;
                continue;
            } else {
                return find_node;
            }
        }
        return nullptr;
    }


    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::rotateLL() {
        int direction = LEFT;
        if (this->parent != nullptr) {
            if (this->parent->left == nullptr || !(*(this->parent->left) == *this)) {
                direction = RIGHT;
            }
        }
        AVLnode<Data, Key> *new_root = this->left;
        this->left = new_root->right;
        if (new_root->right != nullptr) {
            new_root->right->parent = this;
        }
        new_root->right = this;
        new_root->parent = this->parent;
        if (this->parent == nullptr) {
            this->parent = new_root;
            updateHeightAfterRotate(new_root);
            return new_root;
        } else if (direction == LEFT) {
            this->parent->left = new_root;
        } else {
            this->parent->right = new_root;
        }
        this->parent = new_root;
        updateHeightAfterRotate(new_root);
        return new_root;
    };

    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::rotateRR() {
        int direction = LEFT;
        if (this->parent != nullptr) {
            if (this->parent->left == nullptr || *(this->parent->left) != *this) {
                direction = RIGHT;
            }
        }
        AVLnode<Data, Key> *new_root = this->right;
        this->right = new_root->left;
        if (new_root->left != nullptr) {
            new_root->left->parent = this;
        }
        new_root->left = this;
        new_root->parent = this->parent;
        if (this->parent == nullptr) {
            this->parent = new_root;
            updateHeightAfterRotate(new_root);
            return new_root;
        }
        if (direction == LEFT) {
            this->parent->left = new_root;
        } else {
            this->parent->right = new_root;
        }
        this->parent = new_root;
        updateHeightAfterRotate(new_root);
        return new_root;
    };

    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::rotateLR() {
        AVLnode<Data, Key> *tmp_node = this->left->rotateRR();
        tmp_node->parent = this;
        this->left = tmp_node;
        return this->rotateLL();
    };

    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::rotateRL() {
        AVLnode<Data, Key> *tmp_node = this->right->rotateLL();
        tmp_node->parent = this;
        this->right = tmp_node;
        return this->rotateRR();
    };


    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::balanceTree() {
        if (this->getLoadFactor() == 2) {
            if (this->getLeft()->getLoadFactor() >= 0) {
                return this->rotateLL();
            } else if (this->getLeft()->getLoadFactor() == -1) {
                return this->rotateLR();
            }
        } else if (this->getLoadFactor() == -2) {
            if (this->getRight()->getLoadFactor() <= 0) {
                return this->rotateRR();
            } else if (this->getRight()->getLoadFactor() == 1) {
                return this->rotateRL();
            }
        }
        return this;
    }


    template<class Data, class Key>
    AVLnode<Data, Key> *AVLnode<Data, Key>::findMax(AVLnode<Data, Key> *start) {
        if (start == nullptr) {
            return nullptr;
        }
        while (start->right != nullptr) {
            start = start->right;
        }
        return start;
    }

    template<class Data, class Key>
    AVLnode<Data,Key>*  deleteNode(Key A, Key B,AVLnode<Data,Key>* root,bool data);

    template<class Data, class Key>
        AVLnode<Data,Key>*  deleteNode(Key A, Key B ,AVLnode<Data,Key>* root,bool data) {
        AVLnode<Data, Key> *find_node = root->find(A, B);
        if (find_node == nullptr) {
            return root;
        }
        if (find_node == root && (root->getHeight()) == 0)
        {
            our_delete(root,data);
            return nullptr;
        }
        AVLnode<Data, Key> *find_node_dad = find_node->getParent();
        AVLnode<Data, Key> *replace_node = root -> findMax(find_node->getLeft());
        if (replace_node == nullptr) {
            if (find_node->getRight() == nullptr) {
                if (find_node_dad == nullptr) {
                    our_delete(find_node,data);
                   // cout << "deleting root" << "data is : " << find_node->getKey1() << endl;
                    return nullptr;
                }
                if ((*find_node) < (*find_node_dad)) {
                    find_node_dad->setLeft(nullptr);
                } else {
                    find_node_dad->setRight(nullptr);
                }
                our_delete(find_node,data);
                return find_node_dad->fixToRoot();
            } else {
                if (find_node_dad == nullptr) {
                    find_node->setKey1(find_node->getRight()->getKey1());
                    find_node->setKey2(find_node->getRight()->getKey2());
                    find_node->setData(find_node->getRight()->getData());
                    our_delete(find_node->getRight(),data);
                    find_node->setRight(nullptr);
                    return find_node;
                }
                if (*find_node < *find_node_dad) {
                    find_node_dad->setLeft(find_node->getRight());
                    find_node->getRight()->setParent(find_node_dad);
                } else {

                    find_node_dad->setRight(find_node->getRight());
                    find_node->getRight()->setParent(find_node_dad);
                }
                our_delete(find_node,data);
                return find_node_dad->getRight()->fixToRoot();
            }

        }
        AVLnode<Data, Key> *replace_parent = replace_node->getParent();
        find_node->setData(replace_node->getData());
        find_node->setKey1(replace_node->getKey1());
        find_node->setKey2(replace_node->getKey2());
        if (*(replace_node->getParent()) == *find_node) {
            find_node->setLeft(replace_node->getLeft());
            replace_node -> setParent( find_node);
            our_delete(replace_node,data);
            return replace_parent->fixToRoot();
        }
        if (replace_node -> getLeft() != nullptr)
        {
            replace_parent->setRight(replace_node -> getLeft());
        }
        else
        {
            replace_parent -> setRight(nullptr);
        }
        our_delete(replace_node,data);
        return replace_parent->fixToRoot();
    }




    template<class Data, class Key>
    void AVLnode<Data, Key>::inOrder() {
        if (this == nullptr) {
            return;
        }
        if (this->left != nullptr) {
            this->left->inOrder();

        }
        cout << this->getKey1() << ", ";
        if (this->right != nullptr) {
            this->right->inOrder();
        }
    }


    template<class Data, class Key>
    void AVLnode<Data, Key>::postOrder() {
        if (this == nullptr) {
            return;
        }
        if (this->left != nullptr) {
            this->left->postOrder();

        }
        if (this->right != nullptr) {
            this->right->postOrder();
        }
        cout << this->getKey1() << ", ";
    }

    template<class Data, class Key>
    AVLnode<Data, Key> **
    AVLnode<Data, Key>::inOrderToArray(AVLnode<Data, Key> *array[], int *start, AVLnode<Data, Key> *root) {
        if (root == nullptr) {
            return NULL;
        }
        if (root->left != nullptr) {
            root->left->inOrderToArray(array, start, root->left);
        }
//        cout << root->getKey1() << ", " << endl;
//        cout << "start is : " << *start << endl;
        array[*start] = root;
        (*start)++;
        if (root->right != nullptr) {
            root->right->inOrderToArray(array, start, root->right);
        }
        return array;
    }


    template<class Data, class Key>
    void merge_ordered_arrays(AVLnode<Data, Key> *source1[], AVLnode<Data, Key> *source2[],
                              AVLnode<Data, Key> *destination[]) {
//        cout << "ji" << endl;
        int i = 0, j = 0;
        while (source1[i] != nullptr && source2[j] != nullptr) {
            if (*(source1[i]) < *(source2[j])) {
                destination[i + j] = source1[i];
//                cout << source1[i]->getKey1() << "<------------" << endl;
                i++;
            } else {
//                cout << source2[j]->getKey1() << "<------------" << endl;
                destination[i + j] = source2[j];
                j++;
            }
        }
//        cout << "reached end of one of the array" << endl;
        if (source1[i] == nullptr) {
            while (source2[j] != nullptr) {
                destination[i + j] = source2[j];
                j++;
            }
        } else {
            while (source1[i] != nullptr) {
                destination[i + j] = source1[i];
                i++;
            }

        }
    }

}
#endif //HW1_AVLNODE_H
