class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumOfS = 0,sumOfT=0;
        for(int i=0;i<s.size();i++){
            sumOfS += (int)(s[i]);
            sumOfT += (int)(t[i]);
        }
        sumOfT += t[t.size()-1];

        int dif = sumOfT - sumOfS;

        return (char)dif;
    }
};