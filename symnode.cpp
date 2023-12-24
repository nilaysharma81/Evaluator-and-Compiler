
/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

// Write your code below this line

SymNode::SymNode(){key = "please";height = 0;address = -1;par = NULL;left = NULL;right = NULL;}

SymNode::SymNode(string k){key = k;height = 0;address = -1;par = NULL;left = NULL;right = NULL;}
void H_up1(SymNode* n) {
    if(n == NULL)
    {
        return ;
    }
    if (n->left == NULL && n->right == NULL) {n->height = 0;} 
    else if (n->right == NULL) {n->height = 1 + n->left->height;} 
    else if (n->left == NULL) {n->height = 1 + n->right->height;} 
    else {n->height = 1 + std::max(n->left->height, n->right->height);}
}

// void H_up11 (SymNode* x)
// {
//     // cout<<"came inside Hup"<<endl;
//     // if(x == NULL)
//     // {
//     //     // cout<<"x was null"<<endl;
        
//     //     return  ;
//     // }
//     // cout<<"random "<<endl;
//     // cout<<x->key<<endl;
//     if (x->right != NULL && x->left != NULL)
//     {
//         // cout<<"came insider correct if"<<endl;
//         // cout<<x->left->height<<endl;
//         // cout<<x->right->height<<endl;
//         x->height = 1 + std::max(x->right->height, x->left->height);
//         // cout<<x->height<<endl;
//     }
//     else if (x->right == NULL && x->left != NULL)
//     {
//         x->height = 1 + x->left->height;
//         //  cout<<x->height<<endl;
//     }
//     else if (x->right != NULL && x->left == NULL)
//     {
//         x->height = 1 + x->right->height;
//         //  cout<<x->height<<endl;
//     }
//     else if (x->right == NULL && x->left == NULL)
//     {
//         x->height = 0;
//         //  cout<<x->height<<endl;
//     }
// }

// SymNode *SymNode::LeftLeftRotation()
// {
//     SymNode *n1 = this->left;
//     this->left = n1->right;
//     n1->right = this;
//     n1->par = this->par;
//     this->par = n1;
//     if(n1->left)
//     {
//         this->left->par = this ;
//     }
//     H_up1(this);
//     H_up1(n1);
    

//     // H_up1(n1->left);
//     // H_up1(n1->right);
//     // H_up1(n1);
//     // H_up1(n1->par);
    
//     // if (left)
//     // {
//     //     left->par = this;
//     // }
//     // if (n1->left != NULL && n1->right != NULL)
//     // {
//     //     n1->height = 1 + std::max(n1->left->height, n1->right->height);
//     // }
//     // else if (n1->left == NULL && n1->right != NULL)
//     // {
//     //     n1->height = 1 + n1->right->height;
//     // }
//     // else if (n1->left != NULL && n1->right == NULL)
//     // {
//     //     n1->height = 1 +n1->left->height;
//     // }
//     // else if (n1->left == NULL && n1->right == NULL)
//     // {
//     //     n1->height = 0;
//     // }
//     // if (left != NULL && right != NULL)
//     // {
//     //     height = 1 + std::max(left->height, right->height);
//     // }
//     // else if (left == NULL && right != NULL)
//     // {
//     //     height = 1 + right->height;
//     // }
//     // else if (left != NULL && right == NULL)
//     // {
//     //     height = 1 + left->height;
//     // }
//     // else if (left == NULL && right == NULL)
//     // {
//     //     height = 0;
//     // }

//     // if(par!=NULL && par->key<key){par->right = n1;}
//     // else if(par!=NULL && par->key>key){par->left = n1;}
//     // height-=2;
//     return n1;
// }

// SymNode *SymNode::RightRightRotation()
// {
//     // cout<<"here"<<endl;

//     SymNode *n1 = this->right;
//     this->right = n1->left;
//     // cout<<"here1 "<<endl;
//     n1->left = this;
//     if(n1->right)
//     {
//         this->right->par = this ;
//     }
//     n1->par = this-> par;
//     this->par = n1;
//     // if(this->par)
//     // {
//     //     if(n1->key < this->par->key)
//     //     {
//     //         this->par->left = n1 ;
//     //     }
//     //     else
//     //     {
//     //         this->par->right = n1 ;
//     //     }
//     // }
//     // cout<<"rr started"<<endl;
//     H_up1(this);
//     H_up1(n1);
//     // H_up1(n1->left);
//     // H_up1(n1->right);
//     // H_up1(n1);
//     // H_up1(n1->par);
//     // cout<<"here2 "<<endl;
//     return n1;
//     // cout<<"n1->right->key "<<n1->right->key<<endl;

//     // cout<<n1->right->height<<endl;
// //     SymNode* n1 = right;right = n1->left;n1->left = this;
// //     ///height update:
// //     int lH = 0;int rH = 0;
// //     if (left!=NULL) {lH = left->height;}
// //     if (right!=NULL) {rH = right->height;}
// //     height = 1 + max(lH, rH);
// //     // Update parent
// //     if (par!=NULL) {
// //         if(key>par->key){par->right=n1;}
// //         else if(key<par->key){par->left=n1;}
// //     }
// //     n1->par = par;par = n1;return n1;
// // }
//     // if (right)
//     // {
//     //     // cout<<"cmae 1"<<endl;
//     //     right->par = this;
//     // }
//     // if (n1->right != NULL && n1->left != NULL)
//     // {
//     //             // cout<<"cmae 2"<<endl;
//     //             // cout<<"n1->right->key "<<n1->right->height<<endl;
//     //                         //    cout<<"n1->left->key "<<n1->left->height<<endl;
//     //     n1->height = 1 + std::max(n1->right->height, n1->left->height);
//     // }
//     // else if (n1->right == NULL && n1->left != NULL)
//     // {
//     //             // cout<<"cmae 3"<<endl;
//     //     n1->height = 1 + n1->left->height;
//     // }
//     // else if (n1->right != NULL && n1->left == NULL)
//     // {
//     // //    cout<<"n1->l=key" << n1->key<<" " << n1->height<<endl;
//     //     n1->height = 1 + n1->right->height;
//     // }
//     // else if (n1->right == NULL && n1->left == NULL)
//     // {
//     //     n1->height = 0;
//     // }
//     // if (right != NULL && left != NULL)
//     // {
//     //     height = 1 + std::max(right->height, left->height);
//     // }
//     // else if (right == NULL && left != NULL)
//     // {
//     //     height = 1 + left->height;
//     // }
//     // else if (right != NULL && left == NULL)
//     // {
//     //     height = 1 + right->height;
//     // }
//     // else if (right == NULL && left == NULL)
//     // {
//     //     height = 0;
//     // }

//     // if(par!=NULL && par->key<key){par->right = n1;}
//     // else if(par!=NULL && par->key>key){par->left = n1;}
//     // height-=2;



//     // cout<<"inside rr rotation"<<endl;
//     // cout<<"n1->l=key" << n1->key<<" " << n1->height<<endl;
// }
SymNode* SymNode::LeftLeftRotation(){
    // SymNode* n1=this->left;
    // this->left=n1->right;
    // n1->right=this;
    // n1->par=this->par;
    // this->par=n1;
    // if (this->left!=NULL) this->left->par=this;
    // H_up1(this);
    // H_up1(n1);
    // return n1;

    SymNode* n1 = this->left ;
    this->left = n1->right ;
    if(n1->right)
    {
        n1->right->par = this ;
    }
    n1->right = this ;
    n1->par = this->par ;
    if(n1->par)
    {
        if(n1->par->key < this->key) 
        {
            n1->par->right = n1 ;
        }
        else
        {
            n1->par->left = n1 ;
        }
    }
    this->par = n1 ;

    H_up1(n1->right) ;
    H_up1(n1->left) ;
    H_up1(n1) ;
    H_up1(n1->par) ;
    return n1 ;

}

SymNode* SymNode::RightRightRotation(){
    // SymNode* n1=this->right;
    // this->right=n1->left;
    // n1->left=this;
    // n1->par=this->par;
    // this->par=n1;
    // if (this->right!=NULL) this->right->par=this;
    // H_up1(n1);
    // H_up1(this);
    // return n1;

    SymNode* n1 = this->right ;
    this->right = n1->left ;
    if(n1->left)
    {
        n1->left->par = this ;
    }

    n1->left = this ;
    n1->par = this->par ;
        if(n1->par)
    {
        if(n1->par->key < this->key) 
        {
            n1->par->right = n1 ;
        }
        else
        {
            n1->par->left = n1 ;
        }
    }

    this->par = n1 ;

        H_up1(n1->right) ;
    H_up1(n1->left) ;
    H_up1(n1) ;
    H_up1(n1->par) ;
    return n1 ;

    
    return n1 ;
}

SymNode *SymNode::LeftRightRotation()
{
    // cout<<"called"<<endl;
    left = left->RightRightRotation();
    return LeftLeftRotation();
}
SymNode *SymNode::RightLeftRotation()
{
    right = right->LeftLeftRotation();
    // cout<<"returning from rl"<<endl;

    return RightRightRotation();
}

SymNode::~SymNode(){}
