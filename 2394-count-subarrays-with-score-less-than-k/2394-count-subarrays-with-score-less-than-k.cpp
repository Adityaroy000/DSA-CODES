class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long count = 0;
        int l=0,r=0;
        long long sum=0,cnt=0,score;
        
        while(r<n){
            cnt++;
            sum += nums[r];
            score = sum*cnt;
            while(score>=k){
                cnt--;
                sum -= nums[l];
                l++;
                score = sum*cnt;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
};