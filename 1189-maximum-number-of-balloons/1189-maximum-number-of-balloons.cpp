class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int>mpp;

        for(char ch: text){
            mpp[ch]++;
        }
        int ans = INT_MAX;
        if(mpp.count('b') && mpp['b'] >= 1) ans = min(ans,mpp['b']);
        else ans = 0;

        if(mpp.count('a') && mpp['a'] >= 1) ans = min(ans,mpp['a']);
        else ans = 0;

        if(mpp.count('l') && mpp['l'] >= 2){
            int inst = mpp['l']/2;
            ans = min(ans,inst);
        }else ans = 0;

        if(mpp.count('o') && mpp['o'] >= 2){
            int inst = mpp['o']/2;
            ans = min(ans,inst);
        }else ans = 0;

        if(mpp.count('n') && mpp['n'] >= 1) ans = min(ans,mpp['n']);
        else ans = 0;
        
        return ans==INT_MAX?0:ans;
    }
};