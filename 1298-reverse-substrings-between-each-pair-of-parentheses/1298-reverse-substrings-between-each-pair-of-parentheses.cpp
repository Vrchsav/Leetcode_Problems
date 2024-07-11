class Solution {
public:
    string reverseParentheses(string s) {
        int i=0;
        int start=0;
        int end =0;
        string st="";
        while(i<s.size()){
            if(s[i] =='(' ){
                    i++;
                    st="";
                    start=i;
                    end=1;
            }
            else if(s[i]==')'){
                i=0;
                end++;
                cout<<st<<endl;
                s.replace(start-1, end , st);
                st="";
                end=0;
            }
            else{
                st=s[i]+st;
                i++;
                end++;
            }
        }
        return s;
    }
};