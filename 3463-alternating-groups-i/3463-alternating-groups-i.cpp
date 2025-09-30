class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();

        int cnt = 0;
        for(int r = 1;r<n-1;r++){
            if(colors[r] != colors[r-1] && colors[r] != colors[r+1]) cnt++;
        }

        if(colors[n-1] !=colors[n-2] && colors[n-1] != colors[0]){
            cnt++;
        }
        if(colors[0] !=colors[1] && colors[0] != colors[n-1]){
            cnt++;
        }
        return cnt;
    }
};