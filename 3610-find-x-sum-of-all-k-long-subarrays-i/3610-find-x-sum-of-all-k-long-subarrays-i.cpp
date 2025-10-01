class Solution {
public:
    typedef pair<int,int> p;
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans(n-k+1);
        unordered_map<int,int>mpp;
        
        int l=0,r=0,idx = 0;;
        while(r<n){
            mpp[nums[r]]++;
            if(r-l+1 == k){
                priority_queue<p,vector<p>>pq;
                for(auto & it: mpp){
                    pq.push({it.second,it.first});
                }
                int sum = 0;
                for(int i=1;i<=x&&!pq.empty();i++){
                    int mfe = pq.top().second;
                    int mfc = pq.top().first;
                    pq.pop();
                    sum += (mfe*mfc);
                }
                ans[idx] = sum;
                idx++;
                mpp[nums[l]]==1?mpp.erase(nums[l]):mpp[nums[l]]--;
                l++;
            }
            r++;
        }

        return ans;
    }
};