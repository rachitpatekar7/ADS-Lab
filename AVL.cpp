#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

class AVL
{
    
public:
	node* root;
    AVL()
    {
        root = NULL;
    }
    void create_avl();
    node* insert(node *root, int key);
    node* LL(node* t);
    node* RR(node* t);
    node* LR(node* t);
    node* RL(node* t);
    node* Balance(node* t);
    int BF(node* t);
    int ht(node*);
    void inorder(node*);
};

void AVL::create_avl()
{
    int key;
    char ch;
    
    do
    {
        cout<<"Enter Key: ";
        cin>>key;
        root = insert(root, key);
        cout<<"Do you want to continue? (y/n): ";
        cin>>ch;
    }
    while(ch=='y' || ch=='Y');
}

node* AVL::insert(node* root, int key)
{
    if(root == NULL)
    {
        root = new node(key);
        return root;
    }
    else if(key < root->data)
    {
        root->left = insert(root->left, key);
        root = Balance(root);
    }
    else
    {
        root->right = insert(root->right, key);
        root = Balance(root);
    }
    return root;
}

node* AVL::Balance(node* t)
{
    int bf = BF(t);
    if(bf > 1)
    {
        if(BF(t->left) >= 0)
            return LL(t);
        else
            return LR(t);
    }
    else if(bf < -1)
    {
        if(BF(t->right) <= 0)
            return RR(t);
        else
            return RL(t);
    }
    return t;
}

node* AVL::LL(node* t)
{
    node* y = t->left;
    t->left = y->right;
    y->right = t;
    return y;
}

node* AVL::RR(node* t)
{
    node* y = t->right;
    t->right = y->left;
    y->left = t;
    return y;
}

node* AVL::LR(node* t)
{
    t->left = RR(t->left);
    return LL(t);
}

node* AVL::RL(node* t)
{
    t->right = LL(t->right);
    return RR(t);
}

int AVL::BF(node* t)
{
    return ht(t->left) - ht(t->right);
}

int AVL::ht(node *t)
{
    if(t == NULL)
        return 0;
    else
        return max(ht(t->left), ht(t->right)) + 1;
}

void AVL::inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    AVL tree;
    tree.create_avl();
    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    return 0;
}

