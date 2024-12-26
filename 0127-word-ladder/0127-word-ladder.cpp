class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int s = wordList[0].size();
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string str = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i=0;i<str.length();i++){
                char oc = str[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    str[i]=ch;
                    if(st.find(str)!=st.end()){
                        if(str==endWord) return step+1;
                        q.push({str,step+1});
                        st.erase(str);
                    }
                }
                str[i]=oc;
            }
        }
        return 0;
    }
};