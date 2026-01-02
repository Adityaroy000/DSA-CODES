class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int ss = shifts.size();
        vector<int>pre(n+1);
        //prefix sum gave tle and as it is a rage increment problem so we will use difference array technique where,
        // [l,r,x] => arr[l] += x and arr[r] -= x
        for(int i=0;i<ss;i++){
            if(shifts[i][2]==0){
                pre[shifts[i][0]] -= 1;
                pre[shifts[i][1]+1] += 1;
            }else{
                pre[shifts[i][0]] += 1;
                pre[shifts[i][1]+1] -= 1;
            }
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += pre[i];
            pre[i] = sum;
        }

        string copy = s;
        for(int i=0;i<n;i++){
            int shift = (copy[i]-'a' + pre[i])%26;
            if(shift<0) shift += 26;
            copy[i] = char('a'+shift);
        }
        return copy;
    }
};