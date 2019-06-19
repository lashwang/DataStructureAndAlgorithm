#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
 
using namespace std;
 
int N,cur;
vector<int> preOrder;
vector<int> inOrder;
 
typedef struct TreeNode *Node;
struct TreeNode{
    int num;
    Node left,right;
 
    TreeNode(){
        left = NULL;
        right = NULL;
    }
 
};
 
int findRootIndex(int rootNum){
 
    for(int i = 0;i < N; i++){
        if(inOrder[i] == rootNum){
            return i;
        }
    }
    return -1;
 
}
 
Node CreateTree(int left, int right){
    if(left > right) return NULL;
    int root = preOrder[cur];
    cur++;
    int rootIndex = findRootIndex(root);
    Node T = new TreeNode();
    T->num = root;
    if(left != right){
        T->left = CreateTree(left,rootIndex-1);
        T->right = CreateTree(rootIndex+1,right);
    }
    return T;
 
}
 
bool firstOutPut = true;
void PostOrder(Node T){
    if(!T) return;
    PostOrder(T->left);
    PostOrder(T->right);
    if(firstOutPut){
        printf("%d",T->num);
        firstOutPut = false;
    }else{
        printf(" %d",T->num);
    }
}
 
 
int main()
{
    stringstream ss;
    string Nstr;
    getline(cin,Nstr);
    ss << Nstr;
    ss >> N;
    ss.clear();
    string input;
    stack<int> stk;
    int value;
    for(int i = 0; i < N * 2; i++){
        getline(cin,input);
        if(input[1] == 'u'){
            string num = input.substr(5);
            ss << num;
            ss >> value;
            ss.clear();
            stk.push(value);
            preOrder.push_back(value);
        }else{
            value = stk.top();
            stk.pop();
            inOrder.push_back(value);
        }
    }
    Node T = CreateTree(0,N-1);
    PostOrder(T);
    return 0;
}