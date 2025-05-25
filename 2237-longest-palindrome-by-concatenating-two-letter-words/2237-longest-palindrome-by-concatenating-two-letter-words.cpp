class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mpp;
        int len =0;

        for(auto& word:words){
            string rev = word;
            swap(rev[0],rev[1]);

            if(mpp[rev]>0){
                len += 4;
                mpp[rev]--;
            }else{
                mpp[word]++;
            }
        
        }

        for(auto& it:mpp){
            string word = it.first;
            int cnt = it.second;

            if(word[0]==word[1] && cnt>0){
                len+=2;
                break;
            }
        }
        return len;
    }
};