/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode*Leftt=lowestCommonAncestor(root->left,p,q);
        TreeNode*Rightt=lowestCommonAncestor(root->right,p,q);
        if(Leftt!=NULL && Rightt!=NULL){
            return root;
        }
         else if(Leftt==NULL && Rightt!=NULL){
            return Rightt;
        }
         else  if(Leftt!=NULL && Rightt==NULL){
            return Leftt;
        }
        else{
            return NULL;
        }
 
        
    }
};