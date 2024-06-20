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
    int find(vector<int>& inorder,int num){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==num){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int size,int start_in,int end_in){
        if(index>=size || start_in>end_in){
            return NULL;
        }
        int ele=preorder[index++];
        TreeNode*root=new TreeNode(ele);
        int inorder_index=find( inorder,ele);

        root->left=solve(preorder,inorder,index,size,start_in,inorder_index-1);
        root->right=solve(preorder,inorder,index,size,inorder_index+1,end_in);

        return root;
    } 

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;
        TreeNode*ans=solve(preorder,inorder,index,n,0,n-1);
        return ans;
    }
};