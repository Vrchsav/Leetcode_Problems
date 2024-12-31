class Solution {
private:
    int solve (int n, vector<int> days, vector<int> cost,int i,int validity){
    
    if(i>=n){
        return 0;
    }
    while(validity>days[i]){
        i++;
    if(i==n){
        return 0;
    }    
    }
    int a=cost[0]+solve(n, days, cost, i+1, days[i]+1);
    int b=cost[1]+solve(n, days, cost, i+1, days[i]+7);
    int c=cost[2]+solve(n, days, cost, i+1, days[i]+30);
    return(min(a,min(b,c)));

}


int solve_meme(int n, vector<int> days, vector<int> cost,int i,int validity, vector<int> &dp){
    
    if(i>=n){
        return 0;
    }
    while(validity>days[i]){
        i++;
        if (i == n) {
        return 0;
        }
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    
    int a=cost[0]+solve_meme(n, days, cost, i+1, days[i]+1,dp);
    int b=cost[1]+solve_meme(n, days, cost, i+1, days[i]+7,dp);
    int c=cost[2]+solve_meme(n, days, cost, i+1, days[i]+30,dp);
    dp[i]=min(a,min(b,c));
    return(dp[i]);

}
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        int ans=solve_meme(n,days,costs,0,-1,dp);
        //int ans=solve(n,days,costs,0,-1);
        return ans;
        
    }
};