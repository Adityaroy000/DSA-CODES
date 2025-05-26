class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int>indeg(n);

        vector<vector<int>>adj(n);
        for(auto& it:edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indeg[v]++;
        }

        vector<vector<int>>dp(n,vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }
        int cnt = 0,ans=0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            ans = max(ans,dp[u][colors[u]-'a']);
            cnt++;

            for(auto& v:adj[u]){

                for(int i=0;i<26;i++){
                    dp[v][i] = max(dp[v][i],dp[u][i]+(colors[v]-'a' == i));
                }
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        if(cnt < n) return -1;

        return ans;
    }
};