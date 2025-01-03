class DisjointSet{
    vector<int>parent,sizes;
    public:
        DisjointSet(int n){
            sizes.resize(n);
            parent.resize(n);
            for(int i = 0; i<n; i++){
                parent[i] = i;
                sizes[i] = 1;
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
            if(sizes[ulp_u]<sizes[ulp_v]){
                parent[ulp_u] = ulp_v;
                sizes[ulp_v] += sizes[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                sizes[ulp_u] += sizes[ulp_v];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        
        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findup(u) == ds.findup(v)){
                extra++;
            }
            ds.unionBySize(u,v);
        }
        int nc = 0;
        for(int i = 0;i<n; i++){
            if(i == ds.findup(i)) nc++;
        }
        if(extra>=(nc-1)) return nc-1;
        return -1;
    }
};