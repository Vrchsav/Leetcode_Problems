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
    vector<int>solve (TreeNode* root,int distance,int &ans){
        if(root==NULL){
            return {0};
        }
        if(root->left==NULL && root->right==NULL){
            return {1};
        }

        vector<int>left=solve(root->left,distance,ans);
        vector<int>right=solve(root->right,distance,ans);
        for(int i=0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if((left[i]!=0 && right[j]!=0) && left[i]+right[j]<=distance){
                    ans++;
                }
            }
        }
        vector<int>am;
        for(int i=0;i<left.size();i++){
            int a=left[i]+1;
            if(left[i]!=0 && a<=distance)
            am.push_back(a);
        }
        for(int j=0;j<right.size();j++){
                int a=right[j]+1;
                if(right[j]!=0 && a<=distance)

                am.push_back(a);
            }
        return am;

    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        vector<int>aa=solve(root,distance,ans);
        return ans;
    }
};