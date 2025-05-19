class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int wordSize = beginWord.length();

        unordered_set<string>st(wordList.begin(),wordList.end());

        if(st.find(endWord)==st.end()) return 0;

        queue<string>q;
        unordered_set<string>vis;
        q.push(beginWord);
        vis.insert(beginWord);

        int countsteps = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string currWord = q.front();
                q.pop();

                if(currWord == endWord) return countsteps;

                for(auto &word:wordList){
                    if(vis.find(word)==vis.end()){
                        int charCount=0;

                        for(int i=0;i<wordSize;i++){
                            if(currWord[i]!=word[i]) charCount++;
                        }

                        if(charCount>1) continue;
                        else{
                            q.push(word);
                            vis.insert(word);
                        }
                    }
                }
            }
            countsteps++;
        }

        return 0;
    }
};