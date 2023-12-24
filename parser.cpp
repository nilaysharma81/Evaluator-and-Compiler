/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"
// iostream aur namespace hata dena
// #include <iostream>
// using namespace std;

// Write your code below this line

Parser::Parser()
{
    symtable = new SymbolTable();
    if(symtable->get_root() == NULL)
    {
        // cout<<"created symbol table with root null"<<endl;
    }
    // vector<ExprTreeNode *> expr_trees;
    last_deleted = -1;
}

void Parser::parse(vector<string> code)
{
    // vector<ExprTreeNode *> v;vector<ExprTreeNode *> ops;

    // for (int i = 2; i < code.size(); i++)
    // {
    //     if (code[i] == "(")
    //     {
    //         continue;
    //     }
    //     else if (code[i] == ")")
    //     {
    //         ExprTreeNode *third = ops.back();ops.pop_back();
    //         ExprTreeNode *second = v.back();v.pop_back();
    //         ExprTreeNode *first = v.back();v.pop_back();
    //         third->left = first;third->right = third;
    //         v.push_back(third);
    //     }
    //     else
    //     {
    //         ExprTreeNode *temp = new ExprTreeNode();
    //         if (code[i] == "+")
    //         {
    //             temp->type = "ADD";
    //         }
    //         else if (code[i] == "-")
    //         {
    //             temp->type = "SUB";
    //         }
    //         else if (code[i] == "*")
    //         {
    //             temp->type = "MUL";
    //         }
    //         else if (code[i] == "/")
    //         {
    //             temp->type = "DIV";
    //         }
    //         else
    //         {
    //             bool is_number = true;
    //             for (int j = 0; j < code[i].size(); j++)
    //             {
    //                 if (code[i][j] == '-' || (code[i][j] >= '0' && code[i][j] <= '9'))
    //                 {
    //                 }
    //                 else
    //                 {
    //                     is_number = false;
    //                     break;
    //                 }
    //             }
    //             if (is_number)
    //             {
    //                 temp->type = "VAL";
    //                 temp->num = std::stoi(code[i]);
    //             }
    //             else
    //             {
    //                 temp->type = "VAR";
    //                 temp->id = code[i];
    //             }
    //         }
    //         expr_trees.push_back(temp);
    //     }
    // }
    // for (int i = 2; i < code.size(); i++)
    // {
    //     if (code[i] == "(")
    //     {
    //         continue;
    //     }
    //     else if (code[i] == ")")
    //     {
    //         ExprTreeNode *third = expr_trees.back();
    //         expr_trees.pop_back();
    //         ExprTreeNode *second = expr_trees.back();
    //         expr_trees.pop_back();
    //         ExprTreeNode *first = expr_trees.back();
    //         expr_trees.pop_back();
    //         second->left = first;
    //         second->right = third;
    //         expr_trees.push_back(second);
    //     }
    //     else
    //     {
    //         ExprTreeNode *temp = new ExprTreeNode();
    //         if (code[i] == "+")
    //         {
    //             temp->type = "ADD";
    //         }
    //         else if (code[i] == "-")
    //         {
    //             temp->type = "SUB";
    //         }
    //         else if (code[i] == "*")
    //         {
    //             temp->type = "MUL";
    //         }
    //         else if (code[i] == "/")
    //         {
    //             temp->type = "DIV";
    //         }
    //         else
    //         {
    //             bool is_number = true;
    //             for (int j = 0; j < code[i].size(); j++)
    //             {
    //                 if (code[i][j] == '-' || (code[i][j] >= '0' && code[i][j] <= '9'))
    //                 {
    //                 }
    //                 else
    //                 {
    //                     is_number = false;
    //                     break;
    //                 }
    //             }
    //             if (is_number)
    //             {
    //                 temp->type = "VAL";
    //                 UnlimitedInt *digits1 = new UnlimitedInt("1");
    //                 temp->val = new UnlimitedRational(new UnlimitedInt(code[i]), digits1);
    //                 temp->evaluated_value = new UnlimitedRational(new UnlimitedInt(code[i]), digits1);
    //             }
    //             else
    //             {
    //                 temp->type = "VAR";
    //                 temp->id = code[i];
    //             }
    //         }
    //         expr_trees.push_back(temp);
    //     }
    // }
    // Treemid->right = expr_trees.back();
    // expr_trees.pop_back();
    // expr_trees.push_back(Treemid);
    // vector<ExprTreeNode*> expr_trees;

    // cout << "hi" << endl;
    for (int i = 2; i < code.size(); i++)
    {
        if (code[i] == "(")
        {
            continue;
        }
        else if (code[i] == ")")
        {
            ExprTreeNode *third = expr_trees.back();
            expr_trees.pop_back();
            ExprTreeNode *second = expr_trees.back();
            expr_trees.pop_back();
            ExprTreeNode *first = expr_trees.back();
            expr_trees.pop_back();
            second->left = first;
            second->right = third;
            expr_trees.push_back(second);
        }
        else
        {
            ExprTreeNode *temp = new ExprTreeNode();
            if (code[i] == "+")
            {
                temp->type = "ADD";
            }
            else if (code[i] == "-")
            {
                temp->type = "SUB";
            }
            else if (code[i] == "*")
            {
                temp->type = "MUL";
            }
            else if (code[i] == "/")
            {
                temp->type = "DIV";
            }
            else
            {
                bool is_number = true;
                for (int j = 0; j < code[i].size(); j++)
                {
                    if (code[i][j] == '-' || (code[i][j] >= '0' && code[i][j] <= '9'))
                    {
                    }
                    else
                    {
                        is_number = false;
                        break;
                    }
                }
                if (is_number)
                {
                    temp->type = "VAL";
                    // cout<<"type is VAL "<<code[i]<<endl;
                    temp->num = std::stoi(code[i]);
                    // cout<<temp->num<<endl;
                }
                else
                {
                    temp->type = "VAR";
                    temp->id = code[i];
                }
            }
            expr_trees.push_back(temp);
        }
    }
    // if (!expr_trees.empty()) {
    //     expr_trees[0]->id = code[0];
    //     expr_trees[0]->type = "VAR";
    //     expr_trees[0]->right = expr_trees.back();
    //     expr_trees.pop_back();
    //     expr_trees.push_back(expr_trees[0]);
    // }
    ExprTreeNode *n1 = expr_trees.back();
    ExprTreeNode *n2 = new ExprTreeNode();
    ExprTreeNode *n3 = new ExprTreeNode();
    string f = code[0];
    if (f == "ret")
    {
        n3->right = n1;n3->left = n2;
        n3->type = "Equal";n2->type = "RET";
        n2->id = f;expr_trees.push_back(n3);
        return;
    }
    else if (f == "del")
    {
        // cout<<"del ke andar aa gaya"<<endl;
        n3->right = n1;n3->left = n2;
        n3->type = "Equal";n2->type = "DEL";
        n2->id = f;
        last_deleted = symtable->search(n1->id);expr_trees.push_back(n3);
        last_deleted = symtable->search(n1->id) ;symtable->remove(n1->id);
        return;
    }
    else
    {
        n3->right = n1;n3->left = n2;
        n3->type = "Equal";n2->type = "VAR";
        n2->id = f;expr_trees.push_back(n3);
        // cout<<f<<endl;
        // cout<<symtable->search(f) <<endl;
        // cout<<"reached here inside parser"<<endl;
        if (symtable->search(f) == -2){symtable->insert(f);}
        return;
    }
    return;
}

void whoosh(ExprTreeNode *node)
{
    if (node == NULL){return;}
    whoosh(node->left);whoosh(node->right);
    delete node;
}

Parser::~Parser()
{
    // for (int i = 0; i < expr_trees.size(); i++)
    // {
    //     whoosh(expr_trees[i]);
    // }
    // delete symtable;
}

// int main()

// {
//     Parser *a = new Parser();
//     vector<string> a1 = {"a", ":=", "(", "(", "2", "*", "4", ")", "+", "10", ")"};
//     vector<string> b = {"b", ":=", "(", "3", "*", "4", ")"};
//     vector<string> c = {"ret", ":=", "(", "a", "+", "b", ")"};
//     cout << "hello" << endl;
//     a->parse(a1);
//     ExprTreeNode *root = a->expr_trees.back();
//     cout << root->type << endl;
//     cout << root->left->type << endl;
//     cout << root->right->type << endl;
// }