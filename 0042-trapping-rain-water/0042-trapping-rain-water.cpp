class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l=0,r=n-1;
        int lm=0,rm=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=lm) lm = height[l];
                else ans += lm-height[l];
                l++;
            }else{
                if(height[r]>=rm) rm = height[r];
                else ans += rm-height[r];
                r--;
            }
        }
        return ans;
    }
};