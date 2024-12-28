class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int n = prerequisites.size();
        for(int i = 0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int V = numCourses;
        vector<int>indeg(V,0);
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<V; i++){
            if(indeg[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        return count==V;
    }
};