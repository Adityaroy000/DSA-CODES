class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int>ans(m);
        sort(nums.begin(),nums.end());
        vector<int>psum(n);
        int s = 0;
        for(int i=0;i<n;i++){
            s += nums[i];
            psum[i] = s;
        }
        for(int i=0;i<m;i++){
            int maxlen = 0;
            int low=0,high=n-1;
            while(low<=high){
                int mid = (high+low)/2;
                if(psum[mid]<=queries[i]){
                    maxlen = max(maxlen,mid+1);
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            ans[i] = maxlen;
        }
        return ans;
    }
};