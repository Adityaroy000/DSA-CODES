class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        stack<int>st;

        int n = nums.size();
        for(int i=(n*2-1);i>=0;i--){
            if(i>=n){
                int idx = i%n;
                while(!st.empty()&&st.top()<=nums[idx]){
                    st.pop();
                }
                st.push(nums[idx]);
            }else{
                while(!st.empty()&&st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                }else{
                    ans.push_back(st.top());
                }
                st.push(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};