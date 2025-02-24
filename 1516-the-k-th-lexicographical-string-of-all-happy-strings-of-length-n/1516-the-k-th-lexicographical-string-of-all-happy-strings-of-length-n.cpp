class Solution {
    vector<char>list={'a','b','c'};
    bool solve(int n,int &k,string ss,string& ans,char prev='*'){
        if(ss.size()==n){
            k--;
            if(k==0){
                ans=ss;
                return true;
            }else{
                return false;
            }
        }


        for(int i=0;i<3;i++){
            if(prev!=list[i]){
            if(solve(n,k,ss+list[i],ans,list[i])) return true;}
            

        }
        return false;
        
    }

public:
    string getHappyString(int n, int k) {
        string ans;
        bool temp =solve(n,k,"",ans);
        return ans;

        
        
    }
};