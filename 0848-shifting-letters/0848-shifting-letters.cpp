class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        string copy = s;

        vector<long long>pre(n+1);
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i]+shifts[i];
        }

        for(int i=0;i<n;i++){
            int inc = (pre[n] - pre[i])%26;
            char newchar ='a' + (copy[i]-'a'+inc)%26;
            copy[i] = newchar;
        }
        return copy;
    }
};