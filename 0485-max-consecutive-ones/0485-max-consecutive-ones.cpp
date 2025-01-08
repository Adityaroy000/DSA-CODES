class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0,maxcnt=0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                maxcnt = max(maxcnt,cnt);
                cnt = 0;
            }else cnt++;
        }
        maxcnt = max(maxcnt,cnt);
        return maxcnt;
    }
};