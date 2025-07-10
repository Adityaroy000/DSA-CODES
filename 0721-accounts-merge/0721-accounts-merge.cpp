class Solution {
public:
    vector<int>parent,rank;
    int find(int i){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void unionrank(int u,int v){
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]] = i;
                }else{
                    unionrank(i,mpp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>>temp(n);
        for(auto it : mpp){
            int idx = it.second;
            string email = it.first;

            int ulp_idx = find(idx);
            temp[ulp_idx].push_back(email);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(!temp[i].empty()) {
                sort(temp[i].begin(),temp[i].end());
                vector<string> merged;
                merged.push_back(accounts[i][0]);  // name
                merged.insert(merged.end(), temp[i].begin(), temp[i].end());
                ans.push_back(merged);
            }
        }

        return ans;
    }
};