class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int  n = heights.size();
        int maxarea = 0;
        stack<int>st;
        for(int i = 0 ;i<n; i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty()?i:(i-st.top()-1);
                maxarea = max(maxarea,height*width);
            }
            st.push(i);
        }
        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty()?n:(n-st.top()-1);
            maxarea = max(maxarea,height*width);
        }
        return maxarea;
    }
};