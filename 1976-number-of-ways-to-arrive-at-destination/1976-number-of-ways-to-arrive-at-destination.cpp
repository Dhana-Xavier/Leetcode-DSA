class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0}); //{dist,node}
        dist[0]=0;
        ways[0]=1;

        int mod=(int)1e9+7;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long time=it.first;
            long long node=it.second;
            if (time > dist[node])
            continue;

            for(auto nbr:adj[node]){
                long long adjNode=nbr.first;
                long long adjTime=nbr.second;
                



                if(time+adjTime < dist[adjNode]){
                    dist[adjNode]=time+adjTime;
                    pq.push({time+adjTime,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(time+adjTime == dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
 
            }
        }
        return ways[n-1]%mod;
        
    }
};