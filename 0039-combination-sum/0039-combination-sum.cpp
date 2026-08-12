class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& arr,int target,int sum,vector<int>temp){
        if(sum>target || idx>=arr.size()){
            return;
        }
        if(sum==target){
          ans.push_back(temp);
          return;
        }
        // take
        temp.push_back(arr[idx]);
        solve(idx,arr,target,sum+arr[idx],temp);

        //not take
        temp.pop_back();
        solve(idx+1,arr,target,sum,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int>temp;
        solve(0,can,target,0,temp); //{idx,candidates,target,sum}
        return ans;
    }
};