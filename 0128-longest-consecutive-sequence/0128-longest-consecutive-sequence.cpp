class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ls=0;
        int currcnt=0;
        sort(nums.begin(),nums.end());
        int lastsm=INT_MIN;
        for(int i=0;i<n;i++){
            if(lastsm == nums[i]-1){
                currcnt++;
                lastsm = nums[i];
            }else if(lastsm!=nums[i]){
                currcnt=1;
                lastsm = nums[i];
            }
            ls = max(ls,currcnt);
        }
        return ls;
    }
};