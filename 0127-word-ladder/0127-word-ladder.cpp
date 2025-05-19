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

                for(int i=0;i<wordSize;i++){
                    int originalChar = currWord[i];
                    for(char ch ='a';ch<='z';ch++){
                        currWord[i] = ch;
                        if(vis.find(currWord)==vis.end() && st.find(currWord)!=st.end()){
                            q.push(currWord);
                            vis.insert(currWord);
                        }
                    }
                    currWord[i] = originalChar;
                }
            }
            countsteps++;
        }

        return 0;
    }
};