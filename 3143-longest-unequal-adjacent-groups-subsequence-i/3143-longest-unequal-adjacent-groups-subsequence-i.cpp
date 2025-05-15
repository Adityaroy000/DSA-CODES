class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string>ans;

        int maxlen = 0;
        for(int i=0;i<n;i++){
            int cnt = 1;
            int check = groups[i];
            vector<string>temp;
            temp.push_back(words[i]);
            for(int j=i+1;j<n;j++){
                if(check != groups[j]){
                    cnt++;
                    temp.push_back(words[j]);
                    check = groups[j];

                }
            }
            if(cnt>maxlen){
                maxlen = cnt;
                ans = temp;
            }
        }
        return ans;
    }
};