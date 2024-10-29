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
    void preorder(TreeNode*root,vector<int>&arr){
        if(root==NULL){
            return ;
        }
        preorder(root->left,arr);
        arr.push_back(root->val);
        preorder(root->right,arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>preo;
        preorder(root,preo);
        int i=0;
        int j=preo.size()-1;
        while(i<j){
            int sum=preo[i]+preo[j];
            if(sum==k){
                return true;
            }
            else if (sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
        
    }
};