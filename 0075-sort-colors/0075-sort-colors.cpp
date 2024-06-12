class Solution {
public:
    void sortColors(vector<int>& nums) {
       int  index_0=0;
       int index_2=nums.size()-1;
       int i=0;
       while(i<nums.size()){
        if(nums[i]==0 ){
            
            
                if(i<=index_0){
                i++;
                continue;

            }
            else{
                swap(nums[i],nums[index_0]);
                index_0++;
            }
            }
        else if(nums[i]==2  ){
            
            
            if(i>=index_2){
                i++;
                continue;

            }
            else{
              swap(nums[i],nums[index_2]);
                index_2--;  
            }
            }
        if(nums[i]==1 ){
                i++;
            }
        }
        return ;
       }
    
};