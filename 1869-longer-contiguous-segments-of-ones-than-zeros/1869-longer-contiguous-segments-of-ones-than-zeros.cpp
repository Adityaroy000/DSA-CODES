class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();

        int onemaxi = 0,zeromaxi = 0,cntone=0,cntzero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') {
                cntone++;
                cntzero = 0;
            }
            if(s[i]=='0') {
                cntzero++;
                cntone = 0;
            }

            onemaxi = max(onemaxi,cntone);
            zeromaxi = max(zeromaxi,cntzero);

        }
        if(onemaxi > zeromaxi) return true;
        return false;
    }
};