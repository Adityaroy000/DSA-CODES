class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>res(n1,-1);

        for(int i=0;i<n1;i++) mpp[nums1[i]] = i;

        stack<int>st;

        for(int num : nums2){
            while(!st.empty() && num>st.top()){
                int el = st.top();
                st.pop();
                int idx = mpp[el];
                res[idx] = num;
            }

            if(mpp.count(num)) st.push(num);
        }

        return res;
    }
};