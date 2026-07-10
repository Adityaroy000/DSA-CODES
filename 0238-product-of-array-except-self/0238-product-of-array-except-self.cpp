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

        vector<int>pre(n+1,1);

        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1]*nums[i-1];
        }
        int prod = 1;
        for(int x : nums) prod *= x;

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int el = (prod/pre[i+1])*pre[i];
            ans[i] = el;
        }

        return ans;
    }
};