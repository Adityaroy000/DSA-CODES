class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>mpp1;
        unordered_map<char,string>mpp2;
        vector<string>words;

        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        if(words.size() != pattern.size()) return false;

        for(int i=0;i<words.size();i++){
            char ch = pattern[i];
            string word = words[i];

            if(mpp1.count(word) && mpp1[word] != ch) return false;
            if(mpp2.count(ch) && mpp2[ch] != word) return false;

            mpp1[word] = ch;
            mpp2[ch] = word;
        }

        return true;
    }
};