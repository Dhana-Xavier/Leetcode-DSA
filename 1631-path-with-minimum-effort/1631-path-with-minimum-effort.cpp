class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col ==m-1){
                return time;
            }

            for(int i=0;i<4;i++){
                int nr=dr[i]+row;
                int nc=dc[i]+col;

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort=max(abs(heights[row][col]-heights[nr][nc]),time);
                    if(newEffort<dist[nr][nc]){
                        pq.push({newEffort,{nr,nc}});
                        dist[nr][nc]=newEffort;
                    }
                }
            }

        }
        return 0;
    }
};