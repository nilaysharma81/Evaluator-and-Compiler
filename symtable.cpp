#include "symtable.h"
// #include <iostream>
// using namespace std;

SymbolTable::SymbolTable()
{
    root = NULL;
    size = 0;
}

void H_up(SymNode *n)
{
    if (n == NULL)
    {
        return;
    }
    if (n->left == NULL && n->right == NULL)
    {
        n->height = 0;
    }
    else if (n->left != NULL && n->right == NULL)
    {
        n->height = 1 + n->left->height;
    }
    else if (n->left == NULL && n->right != NULL)
    {
        n->height = 1 + n->right->height;
    }
    else
    {
        n->height = 1 + max(n->left->height, n->right->height);
    }
}

SymNode *successor_dhundo(SymNode *n)
{
    SymNode *temp = n;
    temp = temp->right;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

int balance_batao(SymNode *n1)
{
    if (n1 == NULL)
    {
        return 0;
    }
    else if (n1->left == NULL && n1->right != NULL)
    {
        return -(n1->right->height) - 1;
    }
    else if (n1->left != NULL && n1->right == NULL)
    {
        return 1 + n1->left->height;
    }
    else if (n1->left != NULL && n1->right != NULL)
    {
        return n1->left->height - n1->right->height;
    }
    return 0;
}

SymNode *balancer(SymNode *n)
{
    int iska_balance = balance_batao(n);
    if (abs(iska_balance) <= 1)
    {
        return NULL;
    }
    if (iska_balance == 2)
    {
        int a;
        int b;
        if (n->left->left)
        {
            a = n->left->left->height;
        }
        else
        {
            a = -1;
        }
        if (n->left->right)
        {
            b = n->left->right->height;
        }
        else
        {
            b = -1;
        }

        if (a < b)
        {
            return n->LeftRightRotation();
        }
        else
        {
            return n->LeftLeftRotation();
        }
    }
    else
    {
        int a;
        int b;
        if (n->right->left)
        {
            a = n->right->left->height;
        }
        else
        {
            a = -1;
        }
        if (n->right->right)
        {
            b = n->right->right->height;
        }
        else
        {
            b = -1;
        }

        if (a <= b)
        {
            return n->RightRightRotation();
        }
        else
        {
            return n->RightLeftRotation();
        }
    }
}

void sab_barabar_kardo(SymNode *n, SymNode *&root)
{
    SymNode *mover = n;

    H_up(n);
    while (mover->par)
    {
        int iska_balance = balance_batao(mover);
        if (abs(iska_balance) > 1)
        {
            // unbalabce hai
            if (mover->par->key < mover->key)
            {
                SymNode *parent = mover->par;
                mover->par->right = balancer(mover);
                mover = parent->right;
            }
            else
            {
                SymNode *parent = mover->par;
                mover->par->left = balancer(mover);
                mover = parent->left;
            }
        }
        H_up(mover);
        mover = mover->par;
    }
    if (abs(balance_batao(mover)) > 1)
    {
        root = balancer(mover);
        root->par = NULL;
    }
    H_up(root);
}

void SymbolTable::insert(string k)
{
    // empty table
    if (root == NULL)
    {
        SymNode *n1 = new SymNode(k);
        root = n1;
        return;
        size++;
    }

    SymNode *temp = root;
    while (temp)
    {
        if (temp->key < k)
        {
            if (temp->right)
            {
                temp = temp->right;
            }
            else
            {
                break;
            }
        }
        else if (temp->key > k)
        {
            if (temp->left)
            {
                temp = temp->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            return;
        }
    }

    SymNode *nayanode = new SymNode();
    nayanode->key = k;

    size++;
    if (temp->key > k)
    {
        temp->left = nayanode;
        nayanode->par = temp;
    }
    else
    {
        temp->right = nayanode;
        nayanode->par = temp;
    }

    sab_barabar_kardo(nayanode, root);
}

// rewriting search
int SymbolTable ::search(string k)
{
    // cout<<"okay"<<endl;
    if (root == NULL)
    {
    }
    // cout<<"not okay"<<endl;
    if (root == NULL)
    {
        return -2;
    }
    SymNode *temp = root;
    int ans = -2;
    while (temp)
    {
        if (temp->key < k)
        {
            temp = temp->right;
        }
        else if (temp->key > k)
        {
            temp = temp->left;
        }
        else
        {
            // cout<<"wtf"<<endl;
            // cout<<temp->address<<endl;
            ans = temp->address;
            // return temp->address;
            // cout<<"after return statement"<<endl;
            break;
        }
    }
    return ans;
}

void SymbolTable::remove(string k)
{
    if (root == NULL)
    {
        return;
    }
    SymNode *temp = root;
    while (temp)
    {
        if (temp->key < k)
        {
            temp = temp->right;
        }
        else if (temp->key > k)
        {
            temp = temp->left;
        }
        else
        {
            break;
        }
    }
    if (!temp)
    {
        return;
    }
    size--;
    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp == root)
        {
            root = NULL;
        }
        else
        {
            if (temp->par->key < temp->key)
            {
                temp->par->right = NULL;
                sab_barabar_kardo(temp->par, root);
            }
            else
            {
                temp->par->left = NULL;
                sab_barabar_kardo(temp->par, root);
            }
        }
    }
    else if (temp->left == NULL)
    {

        if (temp == root)
        {
            root = temp->right;
            root->par = NULL;
        }
        else
        {

        bool leftchild = false;
        bool rightchild = false;
        if (temp->par->left == temp)
        {
            leftchild = true;
        }
        else
        {
            rightchild = true;
        }
        if (leftchild)
        {
            temp->par->left = temp->right;
        }
        else
        {
            temp->par->right = temp->right;
        }
        temp->right->par = temp->par;
        sab_barabar_kardo(temp->right, root);
        }
    }
    else if (temp->right == NULL)
    {

        if (temp == root)
        {
            root = temp->left;
            root->par = NULL;
        }
        else
        {

        bool leftchild = false;
        bool rightchild = false;
        if (temp->par->left == temp)
        {
            leftchild = true;
        }
        else
        {
            rightchild = true;
        }
        if (leftchild)
        {
            temp->par->left = temp->left;
        }
        else
        {
            temp->par->right = temp->left;
        }
        temp->left->par = temp->par;
        sab_barabar_kardo(temp->left, root);
        }
    }
    else
    {
            // cout<<"here"<<endl;
        SymNode *succ = successor_dhundo(temp);
        int swapper = succ->address;
        succ->address = temp->address;
        temp->address = swapper;
        string sw = succ->key;
        succ->key = temp->key;
        temp->key = sw;
        if (temp->right == succ)
        {
            temp->right = succ->right;
            if (succ->right)
            {
                succ->right->par = temp;
                sab_barabar_kardo(succ->right, root);
            }
            else
            {
                sab_barabar_kardo(succ->par, root);
            }
        }
        else
        {
            succ->par->left = succ->right;
            if (succ->right)
            {
                succ->right->par = succ->par;
                sab_barabar_kardo(succ->right, root);
            }
            else
            {
                sab_barabar_kardo(succ->par, root);
            }
        }
    }
}

void SymbolTable::assign_address(string k, int idx)
{
    SymNode *n1 = root;
    if (root == NULL)
    {
        return;
    }
    while (n1->key != k && n1 != NULL)
    {
        if (k < n1->key)
        {
            n1 = n1->left;
        }
        else
        {
            n1 = n1->right;
        }
    }
    if(n1)
    {
    n1->address = idx;
    }
}


int SymbolTable::get_size() { return size; }

SymNode *SymbolTable::get_root() { return root; }



void del(SymNode *n1)
{
    if (n1 == NULL)
    {
        return;
    }
    else
    {
        del(n1->left);
        del(n1->right);
        delete n1;
    }
    return;
}

void inorder(SymNode* root)
{
    if(root == NULL)
    {
        // cout<<"Empty Tree"<<endl;
        return ;
    }
    if(root->left)
    {
        inorder(root->left) ;
    }
    // cout<<root->key<<" ";
    if(root->par)
    {
        // cout<<root->par->key;
    }
    // cout<<endl;

    if(root->right)
    {
        inorder(root->right) ;
    }
}

SymbolTable::~SymbolTable()
{
    del(root);
    size = 0;
}

// int main()
// {
//     SymbolTable* a = new SymbolTable() ;
//     a->insert("Dba7");
//     a->insert("0Mav");
//     a->insert("IWAD");
//     a->insert("d2h0");
//     a->insert("nfpi");
//     a->insert("HZUp");
//     a->remove("HZUp");
//     a->insert("jcTV");
//     a->insert("mNPq");
//     a->insert("aSQs");
//     a->remove("Dba7");
//     inorder(a->get_root());
//     cout<<endl;
//     cout<<"start checking"<<endl;
// }