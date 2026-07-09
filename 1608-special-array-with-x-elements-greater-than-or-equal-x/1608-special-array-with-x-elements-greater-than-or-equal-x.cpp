class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=1;i<=n;i++){
            int low=0,high=n-1;
            while(low<=high){
                int mid = low+(high-low)/2;

                if(nums[mid] >= i){
                    high = mid-1;
                }else low = mid+1;
            }

            int len = n-low;

            if(i==len) return i;
        }

        return -1;
    }
};