class Solution {
public:
int Maxarea(vector<int>& m){
    int n = m.size();
    int maxarea = 0;
    stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty()&&(m[st.top()])>(m[i])){
            int height = m[st.top()];
            st.pop();
            int width = st.empty()?i:(i-st.top()-1);
            maxarea = max(maxarea,height*width);
        }
        st.push(i);
    }
    while(!st.empty()){
        int height = m[st.top()];
        st.pop();
        int width = st.empty()?n:(n-st.top()-1);
        maxarea = max(maxarea,height*width);
    }
    return maxarea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        vector<vector<int>> psum(n,vector<int>(m,0)) ;
        for(int j = 0; j<m; j++){
            int sum = 0;
            for(int i = 0; i<n; i++){
                if(matrix[i][j]=='1') sum += 1;
                else sum =  0;
                psum[i][j] = sum;
            }
        }
        for(int i = 0; i<n;i++){
            maxarea = max(maxarea,Maxarea(psum[i]));
        }
        return maxarea;
    }
};