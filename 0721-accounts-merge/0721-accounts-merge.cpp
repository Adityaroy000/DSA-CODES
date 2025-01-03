class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i = 0; i<n; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }
        int findup(int node){
            if(node == parent[node]) return node;
            return parent[node] = findup(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp_u = findup(u);
            int ulp_v = findup(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mpp;
        for(int i= 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(mpp[accounts[i][j]],i);
                }
            }
        }

        vector<string>store[n];
        for(auto it : mpp){
            string mail = it.first;
            int loc = ds.findup(it.second);
            store[loc].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i = 0; i<n; i++){
            if(store[i].size() == 0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(store[i].begin(),store[i].end());
            for(auto it: store[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};