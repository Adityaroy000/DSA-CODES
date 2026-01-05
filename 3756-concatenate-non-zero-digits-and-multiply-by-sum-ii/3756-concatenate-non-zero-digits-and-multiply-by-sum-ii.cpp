class Solution {
public:
    int mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<int> pre(m+1, 0), nz(m+1, 0);
        vector<long long> num(m+1, 0), pow10(m+1, 1);

        for (int i = 0; i < m; i++) {
            pow10[i+1] = (pow10[i] * 10) % mod;

            pre[i+1] = pre[i];
            nz[i+1] = nz[i];
            num[i+1] = num[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                pre[i+1] += d;
                nz[i+1]++;
                num[i+1] = (num[i] * 10 + d) % mod;
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int digitSum = pre[r+1] - pre[l];
            int k = nz[r+1] - nz[l];

            long long x = (num[r+1] - num[l] * pow10[k]) % mod;
            if (x < 0) x += mod;

            ans.push_back((x * digitSum) % mod);
        }
        return ans;
    }
};