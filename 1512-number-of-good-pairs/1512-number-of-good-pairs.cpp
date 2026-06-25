class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mpp;
        for(int x : nums) mpp[x]++;

        int cnt = 0;
        for(auto it : mpp){
            int num = it.second;
            int tp = (num*(num-1))/2;
            cnt += tp;
        }
        return cnt;
    }
};