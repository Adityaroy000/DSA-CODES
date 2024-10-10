class Solution {
public:
    vector<int>fnse(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int>fpse(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i = 0; i<n; i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int  n = heights.size();
        int maxarea = 0;
        vector<int>ans;
        vector<int>nse = fnse(heights);
        vector<int>pse = fpse(heights);
        for(int i = 0 ;i<n; i++){
            int width = nse[i]-pse[i]-1;
            int area = heights[i]*width;
            maxarea = max(area,maxarea);
        }
        return maxarea;
    }
};