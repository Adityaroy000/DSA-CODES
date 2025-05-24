class Solution {
public:
    int v;
    vector<vector<int>>ans;

    void dfs(int node,vector<vector<int>>& graph,vector<int>& temp){
        temp.push_back(node);

        if(node == v-1){
            ans.push_back(temp);
        }
        else{
            for(auto& it:graph[node]){
                dfs(it,graph,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        v = graph.size();
        vector<int>path;
        dfs(0,graph,path);

        return ans;
    }
};