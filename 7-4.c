#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list> 
#include <vector>
#include <map>
#include <queue>

using namespace std;

/*
Each input file contains one test case. 
For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. 
Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. 
If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
*/

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : left(NULL), right(NULL) {}
}TreeNode;

typedef struct {
    char left;
    char right;
}SubTreeNode;

map<int,SubTreeNode> g_tree_map;
map<int,bool> g_node_map;

TreeNode *g_tree_root = NULL;
int g_total_number;

void check_node_map(char val){
    if(val == '-'){
        return;
    }
    
    g_node_map.erase(val - '0');
}


int find_root(){
    return g_node_map.rbegin()->first;
}

void read_input(){
    int N;
    
    cin>>N;
    
    g_total_number = N;
    
    for(int i = 0;i < N;i++){
        g_node_map[i] = true;
    }
    
    for(int i = 0;i < N;i++){
        SubTreeNode node;
        char left,right;
        cin>>left;
        cin>>right;
        
        node.left = left;
        node.right = right;
        check_node_map(left);
        check_node_map(right);
        g_tree_map[i] = node;
    }
}


TreeNode *alloc_tree_node(char val){
    if(val == '-'){
        return NULL;
    }else{
        return new TreeNode(val - '0');
    }
}

void create_sub_tree(TreeNode *parent){
    if(parent == NULL){
        return;
    }
    
    SubTreeNode node = g_tree_map[parent->val];
    
    parent->left = alloc_tree_node(node.left);
    parent->right = alloc_tree_node(node.right);
    
    create_sub_tree(parent->left);
    create_sub_tree(parent->right);
}


void create_tree(){
    int root_value = -1;
    
    root_value = find_root();
    
    if(root_value == -1){
        return;
    }
    
    g_tree_root = new TreeNode(root_value);
    create_sub_tree(g_tree_root);
}


void pre(TreeNode *root, int depth, vector<vector<TreeNode *>> &ans) {
    if (!root) return ;
    
    // 如果找到一个新的层级，新建一个vector
    if (depth >= ans.size()){
        ans.push_back(vector<TreeNode *> {});
    }
    ans[depth].push_back(root);
    pre(root->left, depth + 1, ans);
    pre(root->right, depth + 1, ans);
}

vector<vector<TreeNode *>> levelOrder(TreeNode* root) {
    vector<vector<TreeNode *>> ans;
    pre(root, 0, ans);
    return ans;
}

int main()
{   
    vector<vector<TreeNode *>> ans;
    read_input();
    create_tree();
    ans = levelOrder(g_tree_root);
    bool first = true;
    for(auto it=ans.cbegin();it != ans.cend();++it){
        vector<TreeNode *> sub_vec = *it;
        for(auto it2=sub_vec.cbegin();it2 != sub_vec.cend();++it2){
            TreeNode *node = *it2;
            if(node->left == NULL && node->right == NULL){
                if(!first){
                    printf(" ");
                }else{
                    first = false;
                }
                printf("%d",node->val);
            }
        }
    }
    return 0;
}





