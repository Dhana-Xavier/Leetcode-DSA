class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8){
            return n;
        }
        int ans=8;
        int cnt=2;
        int eight=8;

        for(int i=8;i<n;i++){
           ans+=cnt;
           eight--;
           if(eight==0){
            cnt++;
            eight=8;

           }
        }
        return ans;
    }
};