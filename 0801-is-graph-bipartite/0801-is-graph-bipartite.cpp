class Solution {
public:
    bool check(int start,vector<vector<int>>& graph,vector<int>& color){
        queue<int>q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &adj : graph[node]){
                if(color[adj] == -1){
                    if(color[node] == 0) color[adj] = 1;
                    else color[adj] = 0;
                    q.push(adj);
                }else{
                    if(color[adj]==color[node]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i] == -1){
                if(!check(i,graph,color)) return false;
            }
        }
        return true;
    }
};