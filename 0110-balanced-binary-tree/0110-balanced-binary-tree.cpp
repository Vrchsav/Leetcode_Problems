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
private:
    int height(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int left_h=height(root->left);
        int right_h=height(root->right);
        
        return( max(left_h ,right_h)+1);
    }
public:
    bool isBalanced(TreeNode* root) {
       
       if(root==NULL){
        return true;
       }

       bool op1=isBalanced(root->left);
       bool op2=isBalanced(root->right);
       bool op3 = abs(height(root->left)-height(root->right)) <=1;


       if(op1 && op2 && op3){
        return 1;
       }
       else
       return 0;


        
    }
};