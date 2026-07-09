class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        int m = arr1.size();
        vector<int>temp;
        vector<int>ans;
        unordered_set<int>st(arr2.begin(),arr2.end());

        for(int x : arr2){
            for(int y : arr1){
                if(y == x) ans.push_back(y);
            }
        }

        for(int x : arr1){
            if(st.count(x)==0) temp.push_back(x);
        }

        sort(temp.begin(),temp.end());

        for(int x : temp){
            ans.push_back(x);
        }

        return ans;
    }
};