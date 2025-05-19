class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n = nums.size();

        if((nums[0]+nums[1] > nums[2]) && (nums[1]+nums[2]>nums[0]) && (nums[0]+nums[2] > nums[1])){
            int cnt = 0;
            if(nums[0]==nums[1]) cnt++;
            if(nums[1]==nums[2]) cnt++;
            if(nums[0]==nums[2]) cnt++;


            if(cnt==3) return "equilateral";
            if(cnt>=1) return "isosceles";
            if(cnt==0) return "scalene";
        }
        return "none";
    }
};