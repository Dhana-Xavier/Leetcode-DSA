class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,int dst){
        vis[node]=1;
        if(node==dst){
            return true;
        }
        for(auto it:adj[node]){
            if(!vis[it]){
             if( dfs(it,adj,vis,dst)){
                return true;
             }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        
        return dfs(src,adj,vis,dst); 
    }
};