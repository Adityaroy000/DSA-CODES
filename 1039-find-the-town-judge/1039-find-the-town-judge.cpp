class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>>mpp;
        unordered_set<int>vis;

        for(auto& it : trust){
            int u = it[0];
            int v = it[1];

            vis.insert(u);
            mpp[v].push_back(u); //v has u as a trusty
        }

        vector<int>check;//possibile judge needs to be checked
        for(int i=1;i<=n;i++){
            if(vis.find(i)==vis.end()) check.push_back(i);
        }

        for(int i=0;i<check.size();i++){
            if(mpp[check[i]].size()==(n-1)){
                return check[i];
            }
        }

        return -1;
    }
};