/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

// Write your code below this line

ExprTreeNode::ExprTreeNode()
{
    {   
        this->num = -10;
        this->left = NULL;
        this->right = NULL;
        this->id = "";
        this->type = "";
    }
}

ExprTreeNode::ExprTreeNode(string t, int v)
{
    {
        this->num = v;
        this->left = NULL;
        this->right = NULL;
        this->id = "";
        this->type = t;
    }
}

ExprTreeNode::~ExprTreeNode()
{
    // if(this==NULL) return;

    // if (right!=NULL)
    // {
    //     delete this->right;
    // }
    // if (left!=NULL)
    // {
    //     delete this->left;
    // }
    // // if (num != NULL)
    // // {
    // //     delete num;
    // // }
}
