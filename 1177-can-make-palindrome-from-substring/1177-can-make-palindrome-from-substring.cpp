class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool>ans(n,false);

        vector<int>pre(s.size()+1,0);

        for(int i=0;i<s.size();i++){
            int bit = s[i]-'a';
            pre[i+1] = pre[i] ^ (1 << bit);
        }

        for(int i=0;i<n;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];

            int mask = pre[r+1]^pre[l];

            int oddCount = __builtin_popcount(mask);

            if(oddCount/2 <= k) ans[i] = true;
        }
        return ans;
    }
};