class Solution {
public:
// permutation means: You want the next bigger number you can form using the same digits.
//1 3 5 4 2 --> here breakpoint is 3(as 3<5) and after 3 all are in decreasing order. so we once we found breakpoint then will iterate from right till breakpoint to find just bigger element then 3 (in this case) so that we can swap and get the next permutation. so after swapping permutation will be 1 4 5 3 2. Once we swap, the right side is still in descending order. For the “next” permutation, we want it in ascending order (the smallest possible order). So we reverse from index + 1 to end. --> 1 4 2 3 5
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;
        //finding breakpoint --> means after that point everything to right is in decreasing order(means its the max arrangement of those digits)
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        // if no breakpoint is present means that is the largest permutation of those digits so we just reversed to get the next permutation 
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>idx;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+idx+1,nums.end());
        return;
    }
};