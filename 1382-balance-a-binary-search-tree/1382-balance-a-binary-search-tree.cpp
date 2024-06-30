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
     void inorder(TreeNode* root,vector<TreeNode*>&arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    TreeNode* makebalance( TreeNode*root,vector<TreeNode*>arr,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
         TreeNode*head=arr[mid];
         head->left=makebalance(head->left,arr,start,mid-1);
         head->right=makebalance(head->right,arr,mid+1,end);
         return head;


    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>arr;
        inorder(root,arr);
        root = makebalance(root,arr,0,arr.size()-1);
        return root;
        
    }
};