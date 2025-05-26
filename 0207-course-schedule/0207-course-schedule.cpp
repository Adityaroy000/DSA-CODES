class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indeg(n);
        vector<vector<int>>adj(n);

        for(auto &it:prerequisites){
            int u = it[0];
            int v = it[1];

            indeg[u]++;
            adj[v].push_back(u);
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        if(q.empty()) return false;
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;
            for(auto& v : adj[node]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        if(cnt!=n) return false;

        return true;
    }
};