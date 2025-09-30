class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int cntZero = 0,cntOne = 0;
        int l=0,r=0;
        int cnt = 0;
        while(r<n){
            if(s[r]=='0') cntZero++;
            if(s[r]=='1') cntOne++;

            while(cntZero > k && cntOne > k)
            {
                if(s[l]=='0') cntZero--;
                else cntOne--;
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};