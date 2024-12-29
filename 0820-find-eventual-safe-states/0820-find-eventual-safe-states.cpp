class Solution {
private:
    bool dfsCheck(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& graph,vector<int>& check){
            vis[node] = 1;
            pathvis[node] = 1;
            check[node] = 0;
            for(auto it : graph[node]){
                if(!vis[it]){
                    if(dfsCheck(it,vis,pathvis,graph,check)==true) {
                        check[node]=0;
                        return true;
                    }
                }
                else if(pathvis[it]){
                    check[node]= 0;
                    return true;
                }
            }
            check[node] = 1;
            pathvis[node] = 0;
            return false;
        }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        for(int i = 0; i<V; i++){
            dfsCheck(i,vis,pathvis,graph,check);
        }
        vector<int>ans;
        for(int i = 0; i<V; i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};