class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=1;
        for(auto it:edges){
            n=max(n,max(it[0],it[1]));
        }
        vector<vector<int>>adj(n+1);
        int m=edges.size();
        vector<int>degree(n+1);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[v]++;
            degree[u]++;
        }
        for(int i=1;i<=n;i++){
            if(degree[i]==n-1){
                return i;
            }
        }
         return -1;
    }
};