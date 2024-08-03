class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>stt;
        for(auto a:nums){
            stt.insert(a);
        }
        int ele;
        int ans=-1;
        int count =0;
        for(auto it:stt){
            if(it == *stt.begin()){
                ele=it;
                count++;
            }
            else{
                int d=it;
                if(d-ele==1 ){
                    count++;
                }
                else{
                    ans=max(count,ans);
                    count=1;
                }
                ele=d;
            }
        }
                    ans=max(count,ans);

        return ans;
    }
};