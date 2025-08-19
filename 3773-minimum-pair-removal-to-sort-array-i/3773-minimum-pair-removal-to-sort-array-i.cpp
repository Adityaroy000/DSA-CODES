class Solution {
public:
    bool isSorted(vector<int>& nums){
        bool flag = false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                flag = true;
                break;
            }
        }
        if(!flag) return true;
        return false;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int i = -1,j = -1;
        int n = nums.size();
        
        int cnt = 0;
        while(!isSorted(nums)){
            int minsum = INT_MAX;
            for(int s = 0;s<nums.size()-1;s++){
                int sum = nums[s]+nums[s+1];
                if(sum < minsum){
                    i = s;
                    j = s+1;
                    minsum = sum;
                }
            }
            nums[i] = minsum;
            nums.erase(nums.begin()+j);
            cnt++;
        }
        return cnt;
    }
};