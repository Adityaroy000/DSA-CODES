class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        vector<int>temp;
        for(int i=0;i<n-1;i++){
            int diff = abs(nums[i]-nums[i+1]);
            temp.push_back(diff);
        }
        temp.push_back(abs(nums[n-1]-nums[0]));
        return *max_element(temp.begin(),temp.end());
    }
};