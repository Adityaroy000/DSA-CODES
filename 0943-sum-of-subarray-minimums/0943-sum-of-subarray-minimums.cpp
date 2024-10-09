class Solution {
public:
    vector<int>findnse(vector<int>& arr){
        stack<int>st;
        int n = arr.size();
        vector<int>nse(n);
        int sum = 0,r;
        for(int i= n-1; i>=0; i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int>findpsee(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>psee(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
            }else{
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum= 0;
        int mod = (1e9+7);
        vector<int>nse = findnse(arr);
        vector<int>psee = findpsee(arr);
        for(int i = 0; i<n; i++){
            int left = i-psee[i];
            int right = nse[i]-i;
            long contribution = (long)left*right*arr[i];
            sum = (sum+contribution)%mod;
        }
        return sum;
    }
};