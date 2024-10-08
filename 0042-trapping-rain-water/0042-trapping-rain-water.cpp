class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int>suffixmax(n);
        suffixmax[n-1]=height[n-1];
        for(int i = n-2; i>=0;i--){
            suffixmax[i]=max(suffixmax[i+1],height[i]);
        }
        int lm = 0;
        for(int i = 0; i<n; i++){
            int lm = max(lm,height[i]);
            int rm = suffixmax[i];
            if(height[i]<lm && height[i]<rm){
                ans += min(lm,rm)-height[i];
            }
        }
        return ans;
    }
};