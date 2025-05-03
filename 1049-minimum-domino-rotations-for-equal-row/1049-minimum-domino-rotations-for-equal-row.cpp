class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms,int val){
        int n = tops.size();
        int swaptop = 0;
        int swapbot = 0;
        for(int i = 0;i<n;i++){
            if(tops[i]!=val&&bottoms[i]!=val) return -1;
            else if(tops[i]!=val) swaptop++;
            else if(bottoms[i]!=val) swapbot++;
        }
        return min(swapbot,swaptop);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for(int i = 1;i<=6;i++){
            int steps = find(tops,bottoms,i);
            if(steps != -1) ans = min(ans,steps);
        }
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};