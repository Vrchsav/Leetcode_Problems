class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>stt;
        stt.push("+");
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                string frontt=stt.top();
                if(frontt!="+"){
                    stt.pop();
              }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                stt.push(logs[i]);
            }
        }
        return stt.size()-1;
        
    }
};