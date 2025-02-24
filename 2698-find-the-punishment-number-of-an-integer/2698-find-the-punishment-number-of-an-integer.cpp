class Solution {
    bool solve(int num,int total) {
        if(total==0 && num==0){
            return true;
        }
        else if(num==0 || total<0){
            return false;
        }
    
        string s = to_string(num);
        for (int i=0;i<s.size();i++){
            int left = stoi(s.substr(0, i + 1));
            int right =0;
            if(s.substr(i + 1)!=""){
                right = stoi(s.substr(i + 1)); 
            }
            if (solve(right,total-left)){
                return true;
            }
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(solve(i*i,i)){
                ans+=i*i;
            }
        }
        return ans;
    }
};