class Solution {
public:
    int trap(vector<int>& height) {
       vector<int>left;
       vector<int>right;
       int left_max=0;
       int right_max=0;
       int n=height.size()-1;
       for(int i=0;i<height.size();i++){
            left_max=max(left_max,height[i]);
            left.push_back(left_max);
            right_max=max(right_max,height[n-i]);
            right.push_back(right_max);
       }
       int ans=0;
       
       for(int i=0;i<height.size()-1;i++){
            int peak=min(left[i],right[n-i]);
            ans+=peak-height[i];
            
            cout<<i<<" "<<left[i]<<" "<<right[i]<<" "<<ans<<endl;
            
            
       }
       return ans;

    }
};