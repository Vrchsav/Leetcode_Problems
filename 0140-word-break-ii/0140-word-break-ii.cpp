class Solution {
    void solve(int i,string s, vector<string> wordDict,vector<string> ds, vector<string> &ans){
        if(s.size()==i){
            string f="";
            for(int g=0;g<ds.size();g++){
                f+=ds[g];
                if(g==ds.size()-1){
                    break;
                }
                f+=" ";
            }
            ans.push_back(f);
            return ;
        }

        for(int j=i;j<s.size();j++){
            string r=s.substr(i,j-i+1);
            if(find(wordDict.begin(),wordDict.end(),r)!=wordDict.end()){
                ds.push_back(r);
                solve(j+1,s,wordDict,ds,ans);
                ds.pop_back();


            }
        }
    }
    

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       vector<string>ans;
        vector<string>ds;
        solve(0,s,wordDict,ds,ans);
                
        return ans;

    }
};