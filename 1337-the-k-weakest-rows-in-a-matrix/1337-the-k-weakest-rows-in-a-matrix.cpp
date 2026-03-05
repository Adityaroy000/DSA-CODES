class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();

        vector<pair<int,int>>ones;
        for(int i= 0;i<r;i++){
            int sum = accumulate(mat[i].begin(),mat[i].end(),0);
            ones.push_back({sum,i});
        }

        sort(ones.begin(),ones.end());

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(ones[i].second);
        }
        return ans;
    }
};