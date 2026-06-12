class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& temp,vector<vector<int>>& ans) {
        temp.push_back(node);
        if (node == adj.size() - 1) {
            ans.push_back(temp);            
            return;
        }
        for (auto it : adj[node]) {
            dfs(it, adj, temp, ans);
            temp.pop_back();
        }
      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>> ans;
        int n = adj.size();

        vector<int> temp;
        dfs(0, adj, temp, ans);
        return ans;
    }
};