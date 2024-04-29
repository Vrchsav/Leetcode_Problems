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
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL){
            pair<int,bool> p=make_pair(0,true);
            return p;
        }
    pair<int,bool>op1=solve(root->left);
    pair<int,bool>op2=solve(root->right);
    bool left_p=op1.second;
    bool right_p=op2.second;
    bool diff =abs(op1.first -op2.first)<=1;

pair<int,bool>t;
t.first=max(op1.first,op2.first)+1;
    if(left_p && right_p && diff){
        
       
        t.second=true;
        return(t);
    }

    else{
        t.second=false;
        return t;
    }

    



    }
public:
    bool isBalanced(TreeNode* root) {
        pair<int,bool>ans=solve(root);
        return ans.second;
        
    }
};