#ifndef HW1_AVLNODE_H
#define HW1_AVLNODE_H

using std::cout;
using std::endl;
template <class Data, class Key>
class AVLnode {
    Key key;
    Data data;
    AVLnode* left;
    AVLnode* right;
    AVLnode* parent;
public:
    AVLnode() = default;
    explicit AVLnode(Data data,Key key);
    int getHeight();
    int getLoadFactor();
    Data getData();
    AVLnode* getLeft();
    AVLnode* getRight();
    //actions:
    AVLnode* insertNew(Data data);
    AVLnode* fixToRoot ();
    void deleteNode(Data data);
    AVLnode* balanceTree ();
    AVLnode* rotateLL();
    AVLnode* rotateLR();
    AVLnode* rotateRR();
    AVLnode* rotateRL();

};

template <class Data, class Key>
void print2DUtil(AVLnode<Data, Key> *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->getRight(), space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = 10; i < space; i++)
        cout<<" ";
    cout<<root->getData()<<"\n";

    // Process left child
    print2DUtil(root->getLeft(), space);
}

// Wrapper over print2DUtil()
template <class Data, class Key>
void print2D(AVLnode<Data, Key> *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}



template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::getLeft() {
    return this->left;
}

template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::getRight() {
    return this -> right;
}


template <class Data, class Key>
Data AVLnode<Data, Key> ::getData() {
    return data;
}

template <class Data, class Key>
AVLnode<Data, Key> :: AVLnode (Data data,Key key) : data(data) ,key(key) ,left(nullptr),right(nullptr),parent(nullptr) {};

template <class Data, class Key>
int AVLnode<Data, Key> :: getHeight() {
    if (this -> left == nullptr && this -> right == nullptr)
    {
        return 0;
    }
    int left_height = 0;
    int right_height = 0;
    if (this -> left == nullptr)
    {
         left_height = 0;
    }
    else {
        left_height = this -> left -> getHeight();
    }
    if (this -> right == nullptr)
    {
        right_height = 0;
    }
    else {
        right_height = this -> right -> getHeight();
    }
        int height = left_height;
        if (right_height > left_height) {
            height = right_height;
        }
        return height + 1;
    }


template <class Data, class Key>
int AVLnode<Data, Key> ::getLoadFactor() {
    int left_height = -1;
    int right_height = -1;
    if (this -> left != nullptr)
    {
        left_height = this -> left -> getHeight();
    }
    if (this -> right != nullptr)
    {
        right_height = this -> right -> getHeight();
    }
    return left_height - right_height;
}

template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::fixToRoot() {
    AVLnode<Data, Key>* node = this;
    while (node -> parent != nullptr)
    {
        node = node -> balanceTree();
        if (node -> parent == nullptr)
        {
            return node;
        }
        node = node -> parent;
    }
    return node -> balanceTree();
}


template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> :: insertNew(Data data) {
    cout << "adding " << data << endl;
    AVLnode<Data, Key>* insert_node = this;
    AVLnode<Data, Key>* new_node = new AVLnode(data);
    while (insert_node != nullptr) {
        if (insert_node -> data > data) {
            if (insert_node -> left == nullptr)
            {
                insert_node -> left = new_node;
                break;
            }
            insert_node = insert_node -> left;
            continue;
        }
        if (insert_node -> right == nullptr)
        {
            insert_node -> right = new_node;
            break;
        }
        insert_node = insert_node -> right;
    }
        new_node -> parent = insert_node;
        new_node -> left = nullptr;
        new_node -> right = nullptr;
        return new_node -> fixToRoot();
    }


template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::rotateLL() {
    AVLnode<Data, Key>* new_root = this -> left;
    this -> left = new_root -> right;
    new_root -> right = this;
    new_root -> parent = this -> parent;
    if (this -> parent != nullptr)
    {
        this -> parent -> left = new_root;
    }
    this -> parent = new_root;
    return new_root;
};

template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::rotateRR() {
    AVLnode<Data, Key>* new_root = this->right;
    new_root->left = this;
    new_root -> parent = this -> parent;
    if (this -> parent != nullptr)
    {
        this -> parent -> right = new_root;
    }
    this -> right = new_root -> left;
    this -> parent = new_root;
    return new_root;
};

template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::rotateLR() {
    this->left = this -> left -> rotateRR();
    return this -> rotateLL();
};

template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> ::rotateRL() {
    this->right = this -> right -> rotateLL() ;
    return this -> rotateRR();
};


template <class Data, class Key>
AVLnode<Data, Key>* AVLnode<Data, Key> :: balanceTree() {
    cout << "load factor is " << this -> getLoadFactor() << endl;
    if (this -> getLoadFactor() == 2)
    {
        if(this -> getLeft() -> getLoadFactor() >= 0)
        {
            cout << "LL" << endl;
            return this -> rotateLL();
        }
        else if (this -> getLeft() -> getLoadFactor() == -1)
        {
            cout << "LR" << endl;
            return this -> rotateLR();
        }
    }
    else if (this -> getLoadFactor() == -2) {
        if (this->getRight()->getLoadFactor() <= 0) {
            cout << "RR" << endl;
            return this -> rotateRR();
        }
        else if (this->getRight()->getLoadFactor() == 1) {
            cout << "RL" << endl;
            return this -> rotateRL();
        }
    }
    cout << "normal" << endl;
    return this;
}
#endif //HW1_AVLNODE_H
