class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n,1e9);
        queue<vector<int>>q;
        q.push({0,src,0}); //{stops,node,dist}
        dist[src]=0;

        while(!q.empty()){
          auto it=q.front();
          q.pop();
          int stops=it[0];
          int node=it[1];
          int time=it[2];

          if(stops>k){
            continue;
          }

          for(auto nbr:adj[node]){
            int adjNode=nbr.first;
            int adjTime=nbr.second;



            if(((time+adjTime) < dist[adjNode]) && stops<=k){
                dist[adjNode]=time+adjTime;
                q.push({stops+1,adjNode,time+adjTime});
            }
          }
        }

        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};