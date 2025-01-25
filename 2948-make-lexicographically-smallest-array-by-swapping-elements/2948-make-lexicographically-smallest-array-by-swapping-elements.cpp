class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0;
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        map<int, vector<int>*> mpp;
        vector<int>* gp = new vector<int>;  
        gp->push_back(sorted[0]);
        mpp[sorted[0]]=gp;
        for(int i=1;i<nums.size();i++){
            if(sorted[i]-sorted[i-1]<=limit){
                gp->push_back(sorted[i]);
                mpp[sorted[i]]=gp;
            }else{
                
                gp = new vector<int>;  
                gp->push_back(sorted[i]);
                mpp[sorted[i]]=gp;


            }
        }




        for(int i=0;i<nums.size();i++){
            vector<int>*temp=mpp[nums[i]];
            swap(nums[i],(*temp)[0]);
            if (temp->size() > 1) {    
                temp->erase(temp->begin()); 
            }
        }



        
        return nums;
        
    }
};