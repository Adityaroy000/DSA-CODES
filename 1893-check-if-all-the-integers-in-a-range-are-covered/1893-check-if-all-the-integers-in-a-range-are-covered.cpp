class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();

        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=ranges[i][0];j<=ranges[i][1];j++){
                st.insert(j);
            }
        }

        for(int i=left;i<=right;i++){
            if(st.find(i)==st.end()) return false;
        }
        return true;
    }
};