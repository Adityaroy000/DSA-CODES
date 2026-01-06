class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int>ans;

        vector<int>preXor(n+1);

        for(int i=0;i<n;i++){
            preXor[i+1] = preXor[i]^arr[i];
        }

        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];

            int req = preXor[r+1]^preXor[l];
            ans.push_back(req);
        }

        return ans;
    }
};