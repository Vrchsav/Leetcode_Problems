class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        bool flag =true;
        for(int i=0;i<word.size();i++){
            if(flag){
                ans=word[i]+ans;
            }
            else{
                // break;
                ans=ans+word[i];
            }
            if(word[i]==ch){
                flag=false;
            }
            if(i==word.size()-1 && flag){
                return word;
            }
        }
        return ans;
    }
};