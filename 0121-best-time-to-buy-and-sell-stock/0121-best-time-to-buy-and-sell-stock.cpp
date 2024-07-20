class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>stt;
        int high=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            if(high<prices[i]){
                stt.push(prices[i]);
                high=prices[i];
            }
            else{
                stt.push(high);
            }
        }
        // stt.pop();
        // return stt.top();
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++){
            
            ans=max(ans,(stt.top()-prices[i]));
            stt.pop();

        }
        return ans;
    }
};