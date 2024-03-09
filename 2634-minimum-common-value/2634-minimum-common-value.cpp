class Solution {
public:
    int getCommon(vector<int>& num1, vector<int>& num2) {
        int i=0;
        int j=0;
        while(i<num1.size() && j<num2.size()){
            if(num1[i]==num2[j]){
                return num1[i];
            }
            if(num1[i]>num2[j])
            j++;
            else
            i++;
        }
        return -1;
    }
};