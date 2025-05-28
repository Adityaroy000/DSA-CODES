class Solution {
public:
    int n,m;
    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};
    bool isposs(vector<vector<int>>& heights,int maxdiffsofar){
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            if(r==n-1 && c==m-1) return true;

            for(int i=0;i<4;i++){
                int nrid = r+drow[i];
                int ncid = c+dcol[i];

                if(nrid<n&&nrid>=0&&ncid<m&&ncid>=0&&!vis[nrid][ncid]){
                    int maxdiff = abs(heights[r][c]-heights[nrid][ncid]);
                   
                    if(maxdiff <= maxdiffsofar){
                        q.push({nrid,ncid});
                        vis[nrid][ncid] = 1;
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        int low =0,high = 1e6;
        int ans = 0;
        while(low<=high){
            int mid = (high+low)/2;

            if(isposs(heights,mid)){
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        
        return ans;
    }
};