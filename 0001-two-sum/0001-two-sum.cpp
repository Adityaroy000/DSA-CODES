class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int x = nums[i];
            int need = target - x;
            if(mpp.find(need)!= mpp.end()){
                return {mpp[need],i};
            }
            mpp[x] = i;
        }
        return {-1,-1};
    }
};