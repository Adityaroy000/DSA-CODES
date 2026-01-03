class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool>ans(n,false);

        vector<int>pre(s.size()+1,0);

        /*
        string is abcda
        s[0] = a , bit = a-'a' = 0
        (1<<0) put 1 at 0th position in 26 bit integer => 00000...001
        s[1] = b, bit = b-'a' = 1
        (1<<1) put 1 at 1st pos in 26 bit integer => 0000...010

        pre[0] = 0000..000
        (1<<0) = 0000..001
               ^ __________
        pre[1]=  0000..001 (1 means char have odd freq. and 0 means char have even freq)        
        (1<<1)=  0000..010 
                ___________
        pre[2]=  0000..011 (two char have odd freq.)

        A string can be rearranged to form a palindrome if and only if:
	    At most one character has an odd frequency.

        One replacement can fix two odd-frequency characters.
        So, oddCount/2 <= k is true.
        */
        for(int i=0;i<s.size();i++){
            int bit = s[i]-'a';
            pre[i+1] = pre[i] ^ (1 << bit);
        }

        for(int i=0;i<n;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];

            int mask = pre[r+1]^pre[l];

            int oddCount = __builtin_popcount(mask);

            if(oddCount/2 <= k) ans[i] = true;
        }
        return ans;
    }
};