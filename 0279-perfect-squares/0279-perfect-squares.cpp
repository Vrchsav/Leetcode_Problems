class Solution {
private:
    int solve(int n){
        if(n==0){
            return 0;
        }
       int ans=n;
        for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solve(n-i*i));
            
        }
        return ans;
    }
//=========================================================
      int solve_memo(int n,vector<int>&dp){
      
        if(dp[n]!=-1){
            return dp[n];
        }
       int ans=n;
        for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solve_memo(n-i*i,dp));
            
        }
        dp[n]=ans;
        return dp[n];
    }
//===========================================================
      int solve_tab(int n){
      vector<int>dp(n+1,INT_MAX);
       dp[0]=0;
       
        for(int i=1;i<=n;i++){
        for(int j=1;j*j<=n;j++){
            int temp=j*j;
            if((i-temp)>=0){
        dp[i]=min(dp[i],1+dp[i-temp]);
            }
        }}
        return dp[n];
    }




public:
    int numSquares(int n) {
        
        //dp[0]=0;
        int ans =solve_tab(n);
        return ans;
    }
};