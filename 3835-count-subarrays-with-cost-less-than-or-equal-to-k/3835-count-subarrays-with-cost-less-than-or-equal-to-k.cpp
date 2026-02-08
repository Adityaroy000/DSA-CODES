class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans=0;

        int l=0,r=0;
        deque<int>dq1;
        deque<int>dq2;

        while(r<n){
            
            while(!dq1.empty() && nums[r]<nums[dq1.back()]) dq1.pop_back();
            dq1.push_back(r);
            while(!dq2.empty() && nums[r]>nums[dq2.back()]) dq2.pop_back();
            dq2.push_back(r);

            long long cost = 1LL*(nums[dq2.front()]-nums[dq1.front()])*(r-l+1);
            while(cost>k && l<=r){
                if(!dq1.empty() && dq1.front()==l) dq1.pop_front();
                if(!dq2.empty() && dq2.front()==l) dq2.pop_front();
                l++;
                if(!dq1.empty() && !dq2.empty()) cost = 1LL*(nums[dq2.front()]-nums[dq1.front()])*(r-l+1);
            }
            ans += (r-l+1);

            r++;
        }

        return ans;
    }
};