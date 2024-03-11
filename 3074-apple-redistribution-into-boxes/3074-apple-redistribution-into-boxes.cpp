class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_app=0;
        for(int i=0;i<apple.size();i++){
            total_app+=apple[i];
        }
        int ans=0;
        sort(capacity.begin(),capacity.end());
         for(int i=capacity.size()-1;i>=0;i--){
            total_app-=capacity[i];
             ans++;
             if(total_app<=0){
                 break;
             }
        }
        return ans;
    }
};