class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end(),greater{});
        sort(verticalCut.begin(),verticalCut.end(),greater{});
        int i=0;int j=0;
        int h=1;
        int v=1;
        int ans=0;
        while(i<horizontalCut.size() && j<verticalCut.size()){
            if(horizontalCut[i]>verticalCut[j]){
                ans+=horizontalCut[i]*v;
                h++;
                i++;
            }
            else{
                ans+=verticalCut[j]*h;
                v++;
                j++;
            }
        }
        while(i<horizontalCut.size()){
            ans+=horizontalCut[i]*v;
                i++;
        }
        while(j<verticalCut.size()){
            ans+=verticalCut[j]*h;
                j++;
        }

return ans;
    }
};