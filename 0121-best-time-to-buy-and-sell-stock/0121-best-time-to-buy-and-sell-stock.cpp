class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(minn < prices[i]){
                profit=max(profit,prices[i]-minn);
            }
            else{
                minn=min(minn,prices[i]);
            }

        }
return profit;

    
    }
};