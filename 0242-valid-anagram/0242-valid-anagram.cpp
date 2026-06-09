class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int>freq(26);

        int n = s.size();
        for(int i=0;i<n;i++) freq[s[i]-'a']++;

        for(int i=0;i<n;i++){
            if(freq[t[i]-'a']){
                freq[t[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i] > 0) return false;
        }
        return true;
    }
};