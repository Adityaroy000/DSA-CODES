class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string>ans;

        vector<int>freq(26,0);
        unordered_map<char,int>curr;

        string f = words[0];

        for(char ch : f){
            curr[ch]++;
        }

        for(auto it : curr){
            freq[it.first-'a'] = it.second;
        }

        for(int i=1;i<n;i++){
            curr.clear();
            for(char ch:words[i]){
                curr[ch]++;
            }

            for(int i=0;i<26;i++){
                char ch = i+'a';
                freq[i] = min(freq[i], curr[ch]);
            }
        }

        for(int i=0;i<26;i++){
            int cnt = freq[i];

            if(cnt > 0){
                while(cnt--){
                    ans.push_back(string(1,i+'a'));
                }
            }
        }

        return ans;
    }
};