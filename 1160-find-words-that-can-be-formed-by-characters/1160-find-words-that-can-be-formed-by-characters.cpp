class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mpp;
        int n = words.size();

        for(char ch : chars) mpp[ch]++;

        int ans = 0;

        for(int i=0;i<n;i++){
            string temp = words[i];
            unordered_map<char,int>mp;
            for(char ch:temp) mp[ch]++;

            bool flag = false;
            for(auto it : mp){
                if(mpp.count(it.first) && mpp[it.first] >= it.second){
                    flag = true;
                }else {
                    flag = false;
                    break;
                }
            }

            if(flag) ans += temp.size();
        }

        return ans;
    }
};