class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }
        int findup(int node){
            if(node == parent[node]) return node;
            return parent[node] = findup(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u = findup(u);
            int ulp_v = findup(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>mpp;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            mpp[nodeRow] = 1;
            mpp[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it:mpp){
            if(ds.findup(it.first)==it.first) cnt++;
        }
        return stones.size()-cnt;
    }
};