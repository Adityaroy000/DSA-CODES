class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>t1;
        vector<int>t2;
        for(int i = 0; i<n; i++){
            if(nums[i]>0) t1.push_back(nums[i]);
            else if(nums[i]<0) t2.push_back(nums[i]);
        }
        vector<int>ans;
        int i=0,j=0;
        while(i<n/2 && j<n/2){
            ans.push_back(t1[i]);
            i++;
            ans.push_back(t2[j]);
            j++;
        }
        return ans;
    }
};