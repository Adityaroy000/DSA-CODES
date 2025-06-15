class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long cnt = 0;
        int i=0;
        while(i<n){
            int l= -1,r= -1;
            if(nums[i]==0){
                l = i;
                r = i;
                while(r<n&&nums[r]==0) r++;
                int len = (r-l);
                cnt += (1LL*len*(len+1))/2;
                i = r;
            }else i++;
        }
        return cnt;
    }
};