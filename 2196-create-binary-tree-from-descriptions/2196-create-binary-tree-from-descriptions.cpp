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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>mp;
        set<int>stt;

        int root;
        for(int i=0;i<descriptions.size();i++){
            stt.insert(descriptions[i][1]);
            
            if(mp.find(descriptions[i][0])==mp.end()){
                TreeNode* root = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]]=root;
            }
            if(mp.find(descriptions[i][1])==mp.end()){
                TreeNode* root = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]]=root;
            }
            if(descriptions[i][2]==1){
                mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
            }
            else{
               
                mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
             
            }

        }
         for(int i=0;i<descriptions.size();i++){
            if(stt.find(descriptions[i][0])==stt.end()){
                root=descriptions[i][0];
                break;
            }}
        return mp[root];
    }
};