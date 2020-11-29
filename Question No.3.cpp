#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node* left;
    node* right;
    int height;
    node()
    {
        val = 0;
        left = NULL;
        right = NULL;
        height = 0;
    }


};

class binarySearch_Tree
{
public:
    node* root;
    binarySearch_Tree()
    {
        root = NULL;
    }
    node* newNode(int item)
    {
        node* temp = new node;
        temp->val = item;
        return temp;
    }
    void rootInsert(int temp)
    {
        if (root == NULL)
        {
            root = newNode(temp);
        }
    }
    node* insert(node* temp1, int temp2)
    {

        if (temp1 == NULL)
        {
            temp1 = newNode(temp2);
            return temp1;
        }

        if (temp2 < temp1->val)
        {
            temp1->left = insert(temp1->left, temp2);
        }
        else if (temp2 > temp1->val)
        {
            temp1->right = insert(temp1->right, temp2);
        }

        return temp1;
    }


};
class avl_tree
{
public:
    node* root;
    int balance;
    avl_tree()
    {
        root = NULL;
        balance = 0;
    }

    node* minValNode(node* temp)
    {

        if (temp->left == NULL)
        {
            return temp;
        }
        minValNode(temp->left);


    }
    node* maxValNode(node* temp)
    {

        if (temp->right == NULL)
        {
            return temp;
        }
        minValNode(temp->right);


    }

    int maxVal(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }

    }

    int height(node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        return temp->height;
    }


    node* leftRotation(node* temp)
    {
        node* temp1 = temp->right;
        node* temp2 = temp1->left;


        temp1->left = temp;
        temp->right = temp2;


        temp->height = maxVal(height(temp->left),
            height(temp->right)) + 1;
        temp1->height = maxVal(height(temp1->left),
            height(temp1->right)) + 1;


        return temp1;
    }

    node* rightRotation(node* temp)
    {
        node* temp1 = temp->left;
        node* temp2 = temp1->right;


        temp1->right = temp;
        temp->left = temp2;


        temp->height = maxVal(height(temp->left),
            height(temp->right)) + 1;
        temp1->height = maxVal(height(temp1->left),
            height(temp1->right)) + 1;


        return temp1;
    }



    int getBalance(node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        return height(temp->left) - height(temp->right);
    }
    void rootInsert(int key)
    {
        if (root == NULL)
        {
            root = new node;
            root->val = key;
            root->height = 1;
        }
    }


    node* insert(node* temp1, int key)
    {

        if (temp1 == NULL)
        {
            temp1 = new node;
            temp1->val = key;
            temp1->height = 1;
            return temp1;
        }

        if (key < temp1->val)
        {
            temp1->left = insert(temp1->left, key);
        }

        else if (key > temp1->val)
        {
            temp1->right = insert(temp1->right, key);
        }



        temp1->height = 1 + maxVal(height(temp1->left), height(temp1->right));
        balance = getBalance(temp1);

        if (balance > 1 && key < temp1->left->val)
            return rightRotation(temp1);


        if (balance < -1 && key > temp1->right->val)
            return leftRotation(temp1);


        if (balance > 1 && key > temp1->left->val)
        {
            temp1->left = leftRotation(temp1->left);
            return rightRotation(temp1);
        }

        if (balance < -1 && key < temp1->right->val)
        {
            temp1->right = rightRotation(temp1->right);
            return leftRotation(temp1);
        }

        return temp1;
    }

    void AVLconverter(binarySearch_Tree temp1)
    {
        ValTraverse(temp1.root);
    }
    node* ValTraverse(node* temp)
    {
        if (temp == NULL)
        {
            return temp;
        }
        root = insert(root, temp->val);
        ValTraverse(temp->left);
        ValTraverse(temp->right);
    }

    void PreOrder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << temp->val << " ";
        PreOrder(temp->left);
        PreOrder(temp->right);

    }
    void InOrder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }
        InOrder(temp->left);
        cout << temp->val << " ";
        InOrder(temp->right);

    }
    void PostOrder(node* temp)
    {
        if (temp == NULL)
        {
            return;
        }
        InOrder(temp->left);
        InOrder(temp->right);
        cout << temp->val << " ";

    }

};

int main()
{
    binarySearch_Tree b1;
    avl_tree a1;
    int loopInput;
    int value;
    bool loopCounter = true;
    while (loopCounter)
    {
        cout << "Press 1 to insert root into BST Tree" << endl;
        cout << "Press 2 to insert into BST" << endl;
        cout << "Press 3 to convert into AVL" << endl;
        cout << "Press 4 to print PreOrder" << endl;
        cout << "Press 5 to print InOrder" << endl;
        cout << "Press 6 to print PostOrder" << endl;
        cout << "Press 7 to end" << endl;
        cin >> loopInput;
        system("pause");
        system("cls");
        if (loopInput == 1)
        {
            cout << "Enter Value" << endl;
            cin >> value;
            b1.rootInsert(value);
            cout << endl;
        }
        else if (loopInput == 2)
        {
            cout << "Enter Value" << endl;
            cin >> value;
            b1.insert(b1.root, value);
        }
        else if (loopInput == 3)
        {
            a1.AVLconverter(b1);
            cout << endl;
            cout << "BST Successfully converted into AVL" << endl;

        }
        else if (loopInput == 4)
        {
            cout << endl;
            a1.PreOrder(a1.root);
            cout << endl;
        }
        else if (loopInput == 5)
        {
            cout << endl;
            a1.InOrder(a1.root);
            cout << endl;
            cout << endl;
        }
        else if (loopInput == 6)
        {
            cout << endl;
            a1.PostOrder(a1.root);
            cout << endl;
            cout << endl;
        }
        else if (loopInput == 7)
        {
            loopCounter = false;
        }


    }
}

