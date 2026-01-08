class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(int i,int j, vector<int>& nums1,vector<int>& nums2){
        if(i == nums1.size() || j == nums2.size()){
            return LLONG_MIN;
        }
        if(dp[i][j] != LLONG_MIN) return dp[i][j];

        long long val = 1LL*nums1[i]*nums2[j];
        long long take_i_j = LLONG_MIN;
        long long next = solve(i + 1, j + 1, nums1, nums2);
        if (next != LLONG_MIN) {
            take_i_j = val + next; 
        }
        long long take_i = solve(i,j+1,nums1,nums2);
        long long take_j = solve(i+1,j,nums1,nums2);

        return dp[i][j] = max({val,take_i_j,take_i,take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        dp.assign(n1,vector<long long>(n2,LLONG_MIN));

        long long ans = solve(0,0,nums1,nums2);

        return (int)ans;
    }
};