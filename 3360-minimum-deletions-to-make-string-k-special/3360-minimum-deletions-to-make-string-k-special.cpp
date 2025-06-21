class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mpp;
        int n = word.size();

        for(int i=0;i<n;i++){
            mpp[word[i]]++;
        }
        vector<int>temp;
        for(auto it:mpp){
            temp.push_back(it.second);
        }
        int ans = INT_MAX;
        for(auto it:mpp){
            int cnt = 0;
            char ch = it.first;
            int freqCh = it.second;
            for(auto i : mpp){
                char c = i.first;
                int freqC = i.second;
                if(ch != c){
                    if(freqC < freqCh){
                        cnt += freqC;
                    }else if(freqC > freqCh+k) {
                          cnt += freqC-freqCh-k;
                    }
                }
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
};