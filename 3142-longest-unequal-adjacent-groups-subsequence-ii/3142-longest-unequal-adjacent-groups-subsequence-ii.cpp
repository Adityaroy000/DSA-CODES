class Solution {
public:
    bool checkHammingDist(string& s1,string& s2){
        int diff = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff++;
            }
            if(diff>1) return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int>dp(n,1);
        vector<int>parent(n,-1);

        int longestsubseq = 0;
        int longestsubseqidx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && words[i].length()==words[j].length() && checkHammingDist(words[i],words[j])){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                        if(longestsubseq<dp[i]){
                            longestsubseq = dp[i];
                            longestsubseqidx = i;
                        }
                    }
                }
            }
        }

        vector<string>result;
        while(longestsubseqidx != -1){
            result.push_back(words[longestsubseqidx]);
            longestsubseqidx = parent[longestsubseqidx];
        }

        reverse(result.begin(),result.end());

        return result;
    }
};