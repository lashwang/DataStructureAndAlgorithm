#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : left(NULL), right(NULL) {}
}TreeNode;

#define PRINT_END_LINE cout << endl
//#define DEBUG_LOG

int search(int arr[], int strt, int end, int value)
{  
    int i;  
    for (i = strt; i <= end; i++){  
        if (arr[i] == value)  {
            return i;  
        }
    }
    
    return -1;
}

TreeNode* buildTree(int in[], int pre[], int inStrt, int inEnd)  
{  
    static int preIndex = 0; 
  
    if (inStrt > inEnd) {
        return NULL;  
    }
        
  
    TreeNode* tNode = new TreeNode(pre[preIndex++]);
  
    if (inStrt == inEnd){
        return tNode;
    }
    
    int inIndex = search(in, inStrt, inEnd, tNode->val);  
  
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);  
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);  
    return tNode;  
}


void printPostorder(TreeNode* node) 
{
    static bool first_output = true;
    if (node == NULL) {
        return; 
    }
        
    printPostorder(node->left); 
    printPostorder(node->right);
    if(first_output){
        first_output = false;
        cout << node->val;  
    }else{
       cout <<" "<<node->val;  
    }
}





int main()
{
    int N,val;
    char opt[10];
    TreeNode* root;
    
    cin>>N;
    
    vector<int> inOrd;
    vector<int> preOrd;
    stack<int> op_stack;
    
    for(int i = 0;i < N*2;i++){
        cin>>opt;
        #ifdef DEBUG_LOG
        cout<<"read:"<<opt;
        #endif
        if(!strcmp("Push",opt)){
            cin>>val;
            #ifdef DEBUG_LOG
            cout << ",value:" << val;
            #endif
            op_stack.push(val);
            preOrd.push_back(val);
        }else if(!strcmp("Pop",opt)){
            val = op_stack.top();
            op_stack.pop();
            inOrd.push_back(val);
        }
        #ifdef DEBUG_LOG
        PRINT_END_LINE;
        #endif
    }
    
    root = buildTree(&inOrd[0],&preOrd[0],0,N-1);
    
    printPostorder(root);
    
    return 0;
}


int main2(){
    int N = 6;
    int preOrd[] = {1,2,3,4,5,6};
    int inOrd[] = {3,2,4,1,6,5};
    TreeNode* root;
    root = buildTree(inOrd,preOrd,0,N - 1);
    printPostorder(root);
    return 0;
}
