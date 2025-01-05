class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j=1,cnt=1;
        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }else{
                nums[i+1] = nums[j];
                i++;
                j++;
                cnt++;
            }

        }
        return cnt;
    }
};