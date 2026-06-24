class Solution {
public:
    bool bs(int target,vector<int>& nums){
        int n = nums.size();

        int low=0,high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        sort(nums.begin(),nums.end());

        for(int i=1;i<=n;i++){
            if(bs(i,nums)==false){
                ans.push_back(i);
            }
        }

        return ans;
    }
};