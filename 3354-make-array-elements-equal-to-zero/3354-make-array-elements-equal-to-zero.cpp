class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt  = 0;
        vector<int>psum(n),ssum(n);

        for(int i=1;i<n;i++){
            psum[i] = psum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            ssum[i] = ssum[i+1]+nums[i+1];
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int L = psum[i];
                int R = ssum[i];

                if(R == L) ans += 2;
                else if(abs(L-R)==1) ans += 1;
            }
        }
        return ans;
    }
};