class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prevrow(n,0);
        for(int i =0;i<m;i++){
            vector<int>temp(n,0);
            for(int j = 0;j<n;j++){
                if(i==0 && j==0) temp[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prevrow[j];
                    if(j>0) left = temp[j-1];
                    temp[j] = up+left;
                }
            }
            prevrow = temp;
        }
        return prevrow[n-1];
    }
};