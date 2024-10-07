class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int i = nums2.size()-1;i>=0;i--){
            int n = nums2[i];
            while(!st.empty()&&st.top()<=n){
                st.pop();
            }
            if(st.empty()){
                mpp[n] = -1;
            }else{
                mpp[n]=st.top();
            }
            st.push(n);
        }
        for(int i = 0; i<nums1.size();i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                ans.push_back(mpp[nums1[i]]);
            }
        }
        return ans;
    }
};