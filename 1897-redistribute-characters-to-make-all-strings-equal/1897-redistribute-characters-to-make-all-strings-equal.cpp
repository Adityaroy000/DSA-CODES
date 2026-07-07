class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n==1) return true;
        unordered_map<char,int>mpp;

        for(string s : words){
            for(char ch : s){
                mpp[ch]++;
            }
        }

        for(auto it: mpp){
            if(it.second%n != 0) return false;
        }
        return true;
    }
};