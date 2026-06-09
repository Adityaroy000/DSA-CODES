class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int len = 0;    
        s.erase(s.find_last_not_of(' ') + 1);
        
        int i=s.size()-1;
        while(i>=0 && s[i] != ' '){
            len++;
            i--;
        }

        return len;
    }
};