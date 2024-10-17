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
    TreeNode*solve(vector<int>& inorder,int in_start,int in_end, vector<int>& postorder,int pos_start,int pos_end,map<int,int>mpp){
        if(in_start>in_end || pos_start>pos_end){
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[pos_end]);
        int midpoint=mpp[postorder[pos_end]];
        int left_ele=midpoint-in_start;
        root->left=solve(inorder,in_start,midpoint-1,  postorder, pos_start,pos_start+left_ele-1,mpp);
        root->right=solve(inorder,midpoint+1,in_end,  postorder, pos_start+left_ele,pos_end-1,mpp);

        return root;




    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      map<int,int>mpp;
      for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
      }  
      int n=inorder.size()-1;
      TreeNode*root=solve(inorder,0,n,  postorder, 0,n,mpp);
      return root;
    }
};