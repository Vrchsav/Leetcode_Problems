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
    int totalcount(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int ans=1+totalcount(root->left)+totalcount(root->right);
        return ans;

    }
    bool isCBT(TreeNode* root ,int index,int cnt){
        if(root==NULL){
            return 1;
        }
        if(index>=cnt){
            return 0;
        }
        else{
            return(isCBT(root->left,index*2+1,cnt) && isCBT(root->right,index*2+2,cnt));
        }
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int cnt=totalcount(root);
        return(isCBT(root,0,cnt));
    }
};