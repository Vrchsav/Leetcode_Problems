class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> mapp(3,0);
        for(int i=0;i<students.size();i++){
            mapp[students[i]]++;
        }
        int i=0;
        int j=0;
        while(i<students.size() && j<sandwiches.size()){
            if(students[i]==sandwiches[j]){
                mapp[students[i]]--;
                i++;
                j++;
                

            }
            else{
                 if(mapp[sandwiches[j]]>0){
                    students.push_back(students[i]);
                    i++;
                 }
                 else{
                    return students.size()-i;
                 }
            }
        }
        return 0;
    }
};