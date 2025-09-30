class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();

        int cnt = 0;
        for(int r = 0;r<n;r++){
            int curr = colors[r];
            int next = colors[(r+1)%n];
            int after_next = colors[(r+2)%n];

            if(curr != next && next != after_next) cnt++;
        }

        return cnt;
    }
};