class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n<3) return 0;

        int l=0,r=1,cnt=0;
        while(r<n){
            if(r==n-1 && r-l+1 >=3){
                int len = r-l+1;
                cnt += ((len-2)*(len-1))/2;
            }
            else if(r<n-1 && nums[r]-nums[r-1] != nums[r+1]-nums[r]){
                if(r-l+1 >= 3){
                    int len = r-l+1;
                    cnt += ((len-2)*(len-1))/2;
                }
                l=r;
            }
            r++;
        }

        return cnt;
    }
};