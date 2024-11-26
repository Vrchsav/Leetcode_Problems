class Solution {
    bool solve(string s, vector<string>& wordDict,int i){

        if(i<0){
            return true;
        }
        
        for(int j=0;j<wordDict.size();j++){
        int n=wordDict[j].size();
        if((i-(n-1)>=0) && s.substr(i-(n-1),n)==wordDict[j]){
            if (solve(s,wordDict,i-n)){
                return true;
            }
        }
        
}
return false;
        
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n1=s.size();
        int n2=wordDict.size();
        return solve(s,wordDict,n1-1);
    }
};