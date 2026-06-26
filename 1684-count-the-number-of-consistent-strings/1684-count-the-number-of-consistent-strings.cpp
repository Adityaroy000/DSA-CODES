class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();
        vector<int>vis(26,0);

        for(char &ch : allowed) vis[ch-'a'] = 1;

        int ans = 0;
        for(string &word : words){
            bool cons = true;
            for(char ch : word){
                if(vis[ch-'a']==0){
                    cons = false;
                    break;
                }
            }

            if(cons) ans++;
        }
        return ans;
    }
};