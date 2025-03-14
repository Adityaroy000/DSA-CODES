class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>indegree(V,0);
        vector<vector<int>>graphcopy(V);
        
        for(int i = 0; i<V; i++){
            //currently i->it , we need it->i
            for(auto it : graph[i]){
                graphcopy[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i = 0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : graphcopy[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};