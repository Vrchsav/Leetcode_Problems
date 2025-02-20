class Solution {
    bool solve(int i,int j,string s,vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
             dp[i][j]=solve(i+1,j-1,s,dp);
        }else{
           dp[i][j]=false;
        }
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=-1;
        int sp=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,dp)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
        
    }
};