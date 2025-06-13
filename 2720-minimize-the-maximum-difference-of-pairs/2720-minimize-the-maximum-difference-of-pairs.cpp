class Solution {
public:
    int n,ans;
    bool check(vector<int>& nums,int mid,int p){
        int cnt = 0;
        int i=0;
        while(i<n-1){
            if(abs(nums[i]-nums[i+1])<=mid) {
                cnt++;
                i+=2;
            }else{
                i++;
            }
            if(cnt == p){
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        ans = 0;
    
        int left = 0,right = abs(nums[n-1]-nums[0]);

        while(left<=right){
            int mid = (left+right)/2;

            if(check(nums,mid,p)) {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }

        return ans;
    }
};