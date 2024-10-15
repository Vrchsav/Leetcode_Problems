/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
int maxDepth(TreeNode* root,bool &xx) {
        if(root ==NULL){
            
            return 0;
        }
        int left=maxDepth(root->left,xx);
        int right=maxDepth(root->right,xx);
        int ans=max(left,right)+1;
        if(abs(left-right)>1){
          xx =false;
        }
        return ans;
        
    }
    bool isBalanced(TreeNode* root) {
        bool x=true;
        int a=maxDepth(root,x);
        return x;
    }
};