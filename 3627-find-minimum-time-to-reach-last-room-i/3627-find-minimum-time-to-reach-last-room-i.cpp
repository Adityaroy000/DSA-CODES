class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>direc = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;

        vis[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int currtime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();
            if(i==n-1 && j == m-1) return vis[i][j];
            for(auto &dir:direc){
                int nr = i+dir[0];
                int nc = j+dir[1];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int waittime = max(moveTime[nr][nc]-currtime,0);
                    int arrtime = waittime+currtime+1;
                    if(vis[nr][nc]>arrtime){
                        vis[nr][nc] = arrtime;
                        pq.push({arrtime,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};