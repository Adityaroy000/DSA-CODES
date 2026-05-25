class Solution {
public:
    int n;
    unordered_map<int,int>mpp;
    vector<int>vis;
    int dfs(int i, vector<int>& arr, int d){

        vis[i] = 1;
        int cnt = 1;
        //d forward
        for(int x = 1; x<=d; x++){
            int j = i+x;
            if(j>=n || arr[j]>=arr[i]) break;

            if(vis[j]) cnt = max(cnt,1+mpp[j]);
            else  cnt= max(cnt,1+dfs(j,arr,d));
        }

        //d back
        for(int x = 1; x<=d; x++){
            int j = i-x;
            if(j<0 || arr[j]>=arr[i]) break;

            if(vis[j]) cnt = max(cnt,1+mpp[j]);
            else  cnt= max(cnt,1+dfs(j,arr,d));
        }

        mpp[i] = cnt;
        return cnt;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        vis.resize(n,0);

        int cnt = INT_MIN;

        for(int i=0;i<n;i++){
            int temp = 0;
            if(!vis[i]) {
                temp = dfs(i,arr,d);
                cnt = max(cnt,temp);
            }
        }

        return cnt;
    }
};