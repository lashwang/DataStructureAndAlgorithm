#include <vector>


using namespace std;


typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:

    class Solution {
public:
    
    bool check(TreeNode* root,TreeNode* left,TreeNode* right){
        if(!root){
            return true;
        }
        
        if(left){
           if(left->val >= root->val){
               return false;
           }

           if(!check(left,left->left,left->right)){
               return false;
           }
        }
        
        if(right){
            if(right->val <= root->val){
                return false;
            }
            
            if(!check(right,right->left,right->right)){
                return false;
            }
        }
        
        return true;
        
    }


    bool isValidBST(TreeNode* root) {
        
        return check(root,root->left,root->right);
        

    }
};
    

};