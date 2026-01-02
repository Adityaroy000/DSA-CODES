class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int twon =nums.size();

        unordered_map<int,int>mpp;
        for(int i=0;i<twon;i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){
            if(it.second == (twon/2)) return it.first;
        }
        return 0;
    }
};