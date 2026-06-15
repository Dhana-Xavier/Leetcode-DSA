class Solution {
    public int solve(int idx,int[] coins,int amount,int[][] dp){
        if(idx==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return (int)1e9;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int notTake=solve(idx-1,coins,amount,dp);
        int take=(int)1e9;
        if(amount>=coins[idx]){
            take=1+solve(idx,coins,amount-coins[idx],dp);
        }
        return dp[idx][amount]=Math.min(take,notTake);
    }
    public int coinChange(int[] coins, int amount) {
        int n=coins.length;
        if(amount==0){
            return 0;
        }
        int dp[][]=new int [n][amount+1];
        for(int i[] : dp){
            Arrays.fill(i,-1);
        }


        int ans=solve(n-1,coins,amount,dp);
        return ans==(int)1e9?-1:ans;
    }
}