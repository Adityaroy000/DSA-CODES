class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int>vec(n+1,0);
        vector<int>ans;

        for(int x : nums){
            vec[x]++;
        }

        for(int i=1;i<n+1;i++) if(vec[i]>1) ans.push_back(i);
            
        for(int i=1;i<n+1;i++) if(vec[i] == 0) ans.push_back(i);

        return ans;
    }
};