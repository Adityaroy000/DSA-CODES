class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>og = heights;

        sort(heights.begin(),heights.end());

        int cnt =0;
        for(int i=0;i<og.size();i++){
            if(og[i] != heights[i]) cnt++;
        }

        return cnt;
    }
};