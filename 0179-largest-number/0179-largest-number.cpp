class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>stt;
        long long sum;
        for(auto a:nums){
            sum+=a;
            stt.push_back(to_string(a));
        }
        if(sum==0){
            return "0";
        }
        sort(stt.begin(),stt.end(),[](string a,string b){
            if(a+b>b+a)return true;
            return false;
        });
        string ans="";
        for(auto g:stt){
            ans+=g;
        }
        return ans;
    }
};