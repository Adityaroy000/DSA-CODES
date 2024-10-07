class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){\
            int cnt = 0;
            for(int j = i+1; j<=i+n-1;j++){
                int idx = j%n;
                if(nums[idx]>nums[i]){
                    ans.push_back(nums[idx]);
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};