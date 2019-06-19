#include <vector>
#include <queue>

using namespace std;


typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:

    void pre(TreeNode *root, int depth, vector<vector<int>> &ans) {
        if (!root) return ;
        
        // 如果找到一个新的层级，新建一个vector
        if (depth >= ans.size()){
            ans.push_back(vector<int> {});
        }
        ans[depth].push_back(root->val);
        pre(root->left, depth + 1, ans);
        pre(root->right, depth + 1, ans);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        pre(root, 0, ans);
        return ans;
    }
    

};