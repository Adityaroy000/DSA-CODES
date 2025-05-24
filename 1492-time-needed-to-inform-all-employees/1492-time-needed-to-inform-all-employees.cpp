class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int msize = manager.size();
        int isize = informTime.size();

        vector<vector<int>>adj(msize);
        for(int i=0;i<msize;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }

        vector<int>vis(msize,0);
        queue<pair<int,int>>q;
        q.push({headID,0});
        vis[headID] = 1;
        int timetaken = 0;
        while(!q.empty()){
            auto [emp,time] = q.front();
            q.pop();
            timetaken = max(timetaken,time);
            for(auto &it : adj[emp]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,informTime[emp]+time});
                }
            }
        }
        return timetaken;
    }
};