class Solution {
public:
    int n;
    bool checkZeroArray(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) return false;
        }
        return true;
    }
    bool diffarray(vector<int>& nums, vector<vector<int>>& queries,int k){
        vector<int>diff(n,0);

        for(int i=0;i<=k;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];

            diff[start] += val;
            if(end+1 < n) diff[end+1] -= val;
        }
        int cumsum = 0;
        for(int i =0;i<n;i++){
            cumsum += diff[i];
            diff[i] = cumsum;
            if(nums[i]-diff[i]>0) return false;
        }
        
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();

        if(checkZeroArray(nums)) return 0;

        int q = queries.size();
        int ans = -1;
        int low = 0,high = q-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(diffarray(nums,queries,mid)){
                ans = mid+1;
                high= mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};