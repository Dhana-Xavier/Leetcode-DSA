class Solution {
public:
    int count=0;
    void solve(int idx,vector<int>& nums,int sum,int target){
        if(idx>=nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }
       
        solve(idx+1,nums,sum+nums[idx],target);

        solve(idx+1,nums,sum-nums[idx],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        solve(0,nums,0,target);
        return count;
        

    }
};