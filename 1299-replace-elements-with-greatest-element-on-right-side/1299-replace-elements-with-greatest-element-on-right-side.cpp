class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int maxi = -1;
        for(int i=n-1;i>=0;i--){
            if(i==n-1) {
                maxi = max(maxi,arr[i]);
                arr[i] = -1;
            }else{
                int el = arr[i];
                arr[i] = maxi;
                maxi = max(maxi,el);
            }
        }
        return arr;
    }
};