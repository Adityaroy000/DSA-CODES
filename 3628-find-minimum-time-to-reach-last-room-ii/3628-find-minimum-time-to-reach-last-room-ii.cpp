class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        vector<vector<int>>direc = {{-1,0},{1,0},{0,1},{0,-1}};
        vis[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int currtime = pq.top().first;
            auto cell = pq.top().second;
            int r = cell.first;
            int c = cell.second;
            pq.pop();
            if(r==n-1 && c == m-1) return vis[n-1][m-1];
            for(auto &it : direc){
                int nr = r+it[0];
                int nc = c+it[1];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int moveCost = (nr+nc)%2==0?2:1;
                    int waitTime = max(moveTime[nr][nc]-currtime,0);
                    int  arrTime = waitTime+currtime+moveCost;

                    if(vis[nr][nc]>arrTime) {
                        vis[nr][nc] = arrTime;
                        pq.push({arrTime,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};