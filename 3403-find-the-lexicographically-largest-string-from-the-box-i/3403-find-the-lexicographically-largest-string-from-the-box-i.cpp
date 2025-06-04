class Solution {
public:
    string answerString(string word, int numFriends) {
        char ch='a';
        if(numFriends==1){
            return word;
        }
        for(int i=0;i<word.size();i++){
            if((word[i]-'a')>(ch-'a')){
                ch=word[i];
            }
        }
        int n=word.size();
        int total_w= n-(numFriends-1);
        string ans="";
        string tracker="";
        for(int i=0;i<n;i++ ){
            if(word[i]==ch){
                int k=i;
                for(int j=0;j<total_w && j<n && k<n;j++ ){
                    tracker+=word[k];
                    k++;
                }
            }
            if(ans<tracker){
                ans=tracker;
                tracker="";
            }
            tracker="";
        }

        return ans;
    }
};