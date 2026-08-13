class Solution {
public:
    int solve(int idx,vector<int>&arr,int k,int n,vector<int>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int end=min(n,idx+k);
        int currMax=0;
        int ans=0;
        for(int i=idx;i<end;i++){
            currMax=max(currMax,arr[i]);
            ans=max(ans,currMax * (i-idx+1) +solve(i+1,arr,k,n,dp));
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,k,n,dp);
    }
};