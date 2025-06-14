class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n),preProd(n),posProd(n);

        int prod = 1;
        preProd[0] = 1;
        for(int i=1;i<n;i++){
            preProd[i] = preProd[i-1]*nums[i-1];
        }
        posProd[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            posProd[i] = posProd[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i] = preProd[i]*posProd[i];
        }
        
        return ans;
    }
};