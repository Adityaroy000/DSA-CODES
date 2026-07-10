class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1') st.insert(i);
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int td = 0;
            for(auto it : st){
                if(it != i) {
                    int d = abs(it-i);
                    td += d;
                }
            }
            ans[i] = td;
        }
        return ans;
    }
};