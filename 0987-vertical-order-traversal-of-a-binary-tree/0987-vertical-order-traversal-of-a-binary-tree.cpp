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


public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* n=temp.first;
            int ind=temp.second.first;
            int ind2=temp.second.second;
            
            mpp[ind][ind2].push_back(n->val);

            if(n->left!=NULL){
                q.push({n->left,{ind-1,ind2+1}});
                
            }
            if(n->right!=NULL){
                q.push({n->right,{ind+1,ind2+1}});
                
            }
        }
        
        vector<vector<int>>ans;

        
        for(auto it =mpp.begin();it!=mpp.end();it++)
        {
            vector<int>temp={};
            for(auto im=it->second.begin();im!=it->second.end();im++){
                
            vector<int>t=im->second;
            sort(t.begin(),t.end());
            temp.insert(temp.end(), t.begin(), t.end());

            }ans.push_back(temp);
        }
        return ans;

    }
};