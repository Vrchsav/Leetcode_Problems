class Solution {
    bool check(int &i,string &s){
        for(int j=0;j<=i;j++){
            if(s[j]!='*'){
                return false;
            }
        }
        return true;

    }
    bool solve(string &s, string &p, int i, int j,vector<vector<int>>&dp) {
      
        if (i < 0 && j < 0) {
            return true;
        }
        if (i <0 && j >= 0) {
            return check(j,p);
        }
        if(j<0 && i>=0 ){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (s[i] == p[j] || (p[j] == '?')) {
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        } else {
            if(p[j]=='*'){
                return dp[i][j]=( solve(s,p,i,j-1,dp) ||   solve(s,p,i-1,j,dp));
            }
            else{
                return false;
            }
        }
    }

public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(s, p, n1-1, n2-1,dp);
    }
};