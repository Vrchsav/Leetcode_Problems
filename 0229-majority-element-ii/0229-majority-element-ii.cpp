class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1;
        int count1=0;
        int ele2;
        int count2=0;
        for(int i=0;i<nums.size();i++)    {
            if(count1==0 && nums[i]!=ele2){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1){
                count2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count2=0;
        count1=0;

        int n=nums.size()/3+1;
        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]){
                count1++;
            }
            if(ele2==nums[i]){
                count2++;
            }
        }
        vector<int>ans;
        
        if(count1>=n){
            ans.push_back(ele1);
        }
        if(ele1==ele2){
            return ans;
        }
        if(count2>=n){
            ans.push_back(ele2);
        }
return ans;
    }
};