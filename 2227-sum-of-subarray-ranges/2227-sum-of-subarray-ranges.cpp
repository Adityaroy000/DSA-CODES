class Solution {
public:
    vector<int>fnse(vector<int>& nums){
        stack<int>st;
        vector<int>nse(nums.size());
        int n = nums.size();
        for(int i = n-1; i>=0; i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i] = st.empty()?nums.size():st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>fpse(vector<int>& nums){
        stack<int>st;
        vector<int>pse(nums.size());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                st.pop();
            }
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    long long subarrmin(vector<int>& nums){
        long long sum = 0;
        vector<int>nse = fnse(nums);
        vector<int>pse = fpse(nums);
        for(int i = 0; i<nums.size(); i++){
            long long left = i-pse[i];
            long long right = nse[i]-i;
            sum += (left*right*(long long)nums[i]);
        }
        return sum;
    }
    vector<int>fnge(vector<int>& nums){
        stack<int>st;
        vector<int>nge(nums.size());
        int n = nums.size();
        for(int i = n-1; i>=0; i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                st.pop();
            }
            nge[i] = st.empty()?nums.size():st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>fpge(vector<int>& nums){
        stack<int>st;
        vector<int>pge(nums.size());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                st.pop();
            }
            pge[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }
    long long subarrmax(vector<int>& nums){
        long long sum = 0;
        vector<int>nge = fnge(nums);
        vector<int>pge = fpge(nums);
        for(int i = 0; i<nums.size(); i++){
            long long left = i-pge[i];
            long long right = nge[i]-i;
            sum += (left*right*(long long)nums[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subarrmax(nums)-subarrmin(nums);
    }
};