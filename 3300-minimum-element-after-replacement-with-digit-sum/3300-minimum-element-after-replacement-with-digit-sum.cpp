class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> ds(10001);

        for (int i = 1; i <= 10000; i++) {
            ds[i] = ds[i / 10] + i % 10;
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            nums[i] = ds[nums[i]];
            mini = min(mini,nums[i]);
        }
        return mini;
    }
};