class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> mapp(n + 1, 0);
        vector<int> ans;
        int c = 0;
        for (int i = 0; i < n; i++) {
            mapp[A[i]]++;
            mapp[B[i]]++;
            if (mapp[A[i]] > 1) {
                c++;
            }
            if (A[i]!=B[i] &&mapp[B[i]] > 1) {
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};