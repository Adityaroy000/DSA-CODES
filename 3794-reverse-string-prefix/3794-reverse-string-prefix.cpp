class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.size();

        string res = s.substr(0,k);
        string left = s.substr(k,n-k);

        reverse(res.begin(),res.end());

        string ans = res+left;
        return ans;
    }
};