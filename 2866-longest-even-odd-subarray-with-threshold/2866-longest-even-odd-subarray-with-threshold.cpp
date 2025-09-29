class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxlen = 0;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0 && nums[i]<=threshold){
                int j = i;
                while(j+1<n && nums[j+1]<=threshold && nums[j]%2 != nums[j+1]%2) j++;
                maxlen = max(maxlen,j-i+1);
                i = j;
            }
        }
        return maxlen;
    }
};