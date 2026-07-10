class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0,idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                cnt++;
                idx = i;
            } 
        }

        if(cnt > 1){
            vector<int>ans(n,0);
            return ans;
        }else if(cnt == 1){
            int prod = 1;
            for(int x : nums) if(x!=0) prod *= x;
            vector<int>ans(n,0);
            ans[idx] = prod;
            return ans;
        }


        for(int i=1;i<n;i++){
            nums[i] *= nums[i-1];
        }
        int prod = nums[n-1];

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int el;
            if(i==0) el = (prod/nums[i]);
            else el = (prod/nums[i])*nums[i-1];
            ans[i] = el;
        }

        return ans;
    }
};