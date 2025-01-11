class Solution {
public:
    bool canConstruct(string s, int k) {

        int n=s.size();
        map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        if(mpp.size()<k){
            return false;
        }
        int c=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            if(it->second%2!=0){
                c++;
            }
        }
        if(c>k){
            return false;
        }
        return true;
        
    }
};