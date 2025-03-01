class Solution {
    int solve(string text1,string text2,int idx1,int idx2,vector<vector<int>>&dp){
        // if(idx1==0 && idx2==0){
        //     if(text1[idx1]==text2[idx2]){
        //         return 1;
        //     }
        //     else return 0;
        // }
        if(idx1<0 || idx2<0){
            return 0;
            }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int a=0;
        if(text1[idx1]==text2[idx2]){
            a=1+solve(text1,text2,idx1-1,idx2-1,dp);
        }
        int b=max(solve(text1,text2,idx1,idx2-1,dp),solve(text1,text2,idx1-1,idx2,dp));

        return dp[idx1][idx2]=max(a,b);

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int idx1=text1.size()-1;
        int idx2=text2.size()-1;   
        vector<vector<int>>dp(idx1+1,vector<int>(idx2+1,-1));

        int ans=solve(text1,text2,idx1,idx2,dp);

        return ans;

        
    }
};