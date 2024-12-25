/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int count_swap(vector<pair<int, int>>& vcc) {
        int count = 0;
        sort(vcc.begin(), vcc.end());
        vector<int> visited( vcc.size(),false);
        for (int i = 0; i < vcc.size(); i++) {
            if (visited[i] || vcc[i].second == i) {
                continue;
            }
            int counter = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = vcc[j].second;
                counter++;
            }
            if (counter > 1) {
                count += (counter - 1);
            }
        }
        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int index=0;
            vector<pair<int,int>> arr;
            for (int i = 0; i < n; i++) {
                auto frontt = q.front();
                arr.push_back({frontt->val,index});
                index++;
                q.pop();
                if (frontt->left != NULL) {
                    q.push(frontt->left);
                }
                if (frontt->right != NULL) {
                    q.push(frontt->right);
                }
            }
            ans += count_swap(arr);
        }
        return ans;
    }
};