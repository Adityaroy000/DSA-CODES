class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int cnt = 1,maxcnt = 1;
        for(int i = 0; i<n-1; i++){
            if(nums[i]==nums[i+1]) continue;
            else if(nums[i] == (nums[i+1]-1)){
                cnt++;
                maxcnt = max(maxcnt,cnt);
            }else{
                maxcnt = max(maxcnt,cnt);
                cnt = 1;
            }
        }
        return maxcnt;
    }
};