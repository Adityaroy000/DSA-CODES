class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int>ans(m);
        sort(nums.begin(),nums.end());

        for(int i=0;i<m;i++){
            int sum = 0;
            int maxlen = 0,len=0;
            for(int j=0;j<n;j++){
                sum += nums[j];
                if(sum<=queries[i]){
                    len++;
                    maxlen = max(maxlen,len);
                }else break;
            }
            ans[i] = maxlen;
        }
        return ans;
    }
};