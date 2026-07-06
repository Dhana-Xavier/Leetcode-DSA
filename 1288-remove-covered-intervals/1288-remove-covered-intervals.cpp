class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& itv) {
        sort(itv.begin(),itv.end(),[](auto &a,auto &b){
            if(a[0]==b[0])
             return a[1]>b[1];
            return a[0]<b[0];
        });
        int st=itv[0][0];
        int end=itv[0][1];
        int n=itv.size();
        int count=1;

        for(int i=1;i<n;i++){
           if(itv[i][1]>end){
            count++;
            end=itv[i][1];
           }
        }
        return count;
    }
};