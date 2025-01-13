class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mpp[nums[i]] ++;
            }else mpp[nums[i]] = 1;
        }
        for(auto it : mpp){
            if(it.second>(n/2)) return it.first;
        }
        return -1;
    }
};