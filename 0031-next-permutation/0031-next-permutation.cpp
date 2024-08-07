class Solution {
public:
vector<int>permut(vector<int>& nums){
    int n = nums.size();
        int index = -1;
        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        for(int i =n-1; i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
    reverse(nums.begin()+index+1,nums.end());
    return nums;
}
    void nextPermutation(vector<int>& nums) {
        vector<int>ans = permut(nums);
        for(auto it : ans){
            cout<<it<<" ";
        }
    }
};