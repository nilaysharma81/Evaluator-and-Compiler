/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
//include aur namespace hata dena
#include "eppcompiler.h"
// #include <iostream>
// using namespace std ;
// Write your code below this line

EPPCompiler::EPPCompiler(){mem_loc = {};output_file = "";memory_size = 0;}

EPPCompiler::EPPCompiler(string out_file, int mem_limit)
{   
    memory_size = mem_limit;output_file = out_file;
    for (int i = 0; i < mem_limit; i++){mem_loc.push_back(memory_size - i - 1);}
}
vector<ExprTreeNode *> modifPostOrder(ExprTreeNode *root)
{
    vector<ExprTreeNode *> stk;
    vector<ExprTreeNode *> postOrder;
    ExprTreeNode *n1;
    stk.push_back(root);
    while (!stk.empty())
    {
        // cout<<"inside loop"<<endl;
        n1 = stk[stk.size()-1];
        postOrder.push_back(n1);
        stk.pop_back();
        if (n1->right != NULL)
        {
            stk.push_back(n1->right);
        }
        if (n1->left != NULL)
        {
            stk.push_back(n1->left);
        }
    }
    return postOrder;
}

void EPPCompiler::compile(vector<vector<string>> code)
{
        std::ofstream output;
        output.open(output_file, ios::out);
        output.close();
    // cout<<"hi"<<endl;
    for (auto x : code)
    {
        // cout<<"starting iteration"<<endl;
        targ.parse(x);
        // cout<<"parsed"<<endl;

        ExprTreeNode *n1 = targ.expr_trees.back();
        if (n1->left->type == "DEL")
        {
            targ.symtable->search(n1->right->id);
            // cout<<"mc"<<endl;

            mem_loc.push_back(targ.last_deleted);
            // cout<<"search done"<<endl;
            // targ.symtable->remove(n1->right->id);
        }
        else if (n1->left->type == "RET")
        {
            // continue;
        }
        else if (n1->left->type == "VAR")
        {
            // cout<<"left type is var"<<endl;
            if (targ.symtable->search(n1->left->id) == -1)
            {
                int mx = mem_loc.back();
                // cout<<mx<<endl;
                targ.symtable->assign_address(n1->left->id, mx);
                mem_loc.pop_back();
            }
            // cout<<"hi"<<endl;
        }
        vector<string> gtc;
        gtc = generate_targ_commands();
        // cout<<"generated commands are"<<endl;
        // for(auto y : gtc)
        // {
        //     cout<<y<<endl;
        // }
        write_to_file(gtc);
    }
}

vector<string> EPPCompiler::generate_targ_commands()
{
    // cout<<"came inside here"<<endl;
    ExprTreeNode *n1;
    n1 = targ.expr_trees.back();
    vector<ExprTreeNode *> v;
    v = modifPostOrder(n1->right);
    // cout<<"hello"<<endl;
    int s=v.size();
    // cout<<"gtc called"<<endl;
    vector<string> comms;
    vector<ExprTreeNode*> temp_v ;
    for(int i = v.size()-1 ; i>=0 ; i-- )
    {
        temp_v.push_back(v[i]);
    }
    v = temp_v ;
    // reverse(v.begin() , v.end()) ;
    if(n1->left->type == "DEL")
    {
        comms.push_back("DEL = mem[" + to_string(targ.last_deleted) + "]") ;
    }
    else
    {

    for (auto x : v)
    {
        // cout<<x->type<<endl;
        if (x->type == "ADD")
        {
            comms.push_back("ADD");
        }
        else if (x->type == "SUB")
        {
            comms.push_back("SUB");
        }
        else if (x->type == "MUL")
        {
            comms.push_back("MUL");
        }
        else if (x->type == "DIV")
        {
            comms.push_back("DIV");
        }
        else if (x->type == "RET")
        {
            comms.push_back("RET=POP");
        }
        else if (x->type =="VAL")
        {
            comms.push_back("PUSH "+to_string(x->num));
        }
        else if (x->type == "VAR" )
        {
            
            comms.push_back("PUSH mem[" + std::to_string(targ.symtable->search(x->id)) + "]");
        }
        
        else if(x->type=="RET" && x==v[s - 2])
        {
            comms.push_back("RET = POP");
        }
        // else{
        //     comms.push_back("mem["+std::to_string(targ.symtable->search(v[s-3]->id))+"] = POP");
        // }
    }
    if(n1->left->type == "RET")
    {
        comms.push_back("RET = POP") ;
    }
    else
    {
        comms.push_back("mem[" + to_string(targ.symtable->search(n1->left->id)) + "] = POP");
    }
    }
    return comms;
}

    void EPPCompiler::write_to_file(vector<string> commands)
    {
        std::ofstream output;
    
        output.open(output_file, ios::app);
        for (int i = 0; i < commands.size(); i++)
        {
            output << commands[i] << endl;
        }
        output.close();
    }

    EPPCompiler::~EPPCompiler()
    {
    }


// int main()
// {
//     // cout<<"yes"<<endl;
//     EPPCompiler* a = new EPPCompiler("check.txt" , 1000) ;
// //     Test case 1:
// // a := (1+2)

// // b := (1+2)
// // ret := (a+b)

// // Test case 2:

// // a := (1+2)

// // b := (1+2)
// // del := b
// // c := (1+2)
// // ret := (a+c)
//     vector<string> a1 = {"a" , ":=" , "(" ,"1","+" ,"2" , ")"};
//     vector<string> b = {"b" , ":=" , "(" , "1" , "+" , "2" , ")" };
//     vector<string> c = {"del" , ":=" , "b"  };
//     vector<string> d = {"c" , ":=" , "(" , "1" , "+" , "2" , ")" };
//     vector<string> e = {"ret" , ":=" , "(" , "a" , "+" , "c" , ")" } ;
//     vector<vector<string>> code ;
//     code.push_back(a1) ;
//     code.push_back(b) ;
//     code.push_back(c) ;
//     code.push_back(d) ;
//     code.push_back(e) ;

//     a->compile(code) ;

// }