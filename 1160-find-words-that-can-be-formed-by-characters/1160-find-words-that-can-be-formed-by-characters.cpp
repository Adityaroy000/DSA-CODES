class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mpp;
        int n = words.size();

        for(char ch : chars) mpp[ch]++;

        int ans = 0;

        for(int i=0;i<n;i++){
            string temp = words[i];
            unordered_map<char,int>mp = mpp;
            bool flag = true;
            for(char ch:temp) {
                if(mp.count(ch)){
                    (mp[ch]==1)?mp.erase(ch):mp[ch]--;
                }else{
                    flag = false;
                    break;
                }
            }

            if(flag) ans += temp.size();
        }

        return ans;
    }
};