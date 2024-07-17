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
    TreeNode*solve(TreeNode* root, int startValue, int destValue){
        if(root==NULL){
            return NULL;
        }
        if(root->val ==  startValue || root->val==destValue){
            return root ; 
        }
        TreeNode* left=solve(root->left,startValue,destValue);
        TreeNode* right=solve(root->right,startValue,destValue);

        if(left!=NULL && right!=NULL){
            return root;
        }
        else if(left!=NULL && right ==NULL){
            return left;
        }
        else if(left==NULL && right !=NULL){
            return  right;
        }
        else{
            return NULL;

        }
    }
    bool path(TreeNode* root, int destValue,string &str){
        if(root==NULL){
            return 0;
        }
        if(root->val==destValue){
            return 1;
        }
        str.push_back('L');
        if(path(root->left,destValue,str)){
            return 1;
        }
        str.pop_back();
        str.push_back('R');
        if(path(root->right,destValue,str)){
            return 1;
        }
            str.pop_back();

    
        return 0;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        //TreeNode* ance = solve(root,  startValue,  destValue);
        string str;
        bool m=path(root,startValue,str);
        string des="";
        bool h=path(root,destValue,des);
        int i=0;
        int j=0;
        string ans;
        while(i<str.size()||j<des.size()){
            if(str[i]!=des[j]){
                while(i<str.size()){
                    ans+='U';
                    i++;
                }
                while(j<des.size()){
                    ans+=des[j];
                    j++;
                }
            }
            i++;
            j++;
        }
        
        return ans;
        
    }
};