class Solution {
    vector<vector<string>>ans;
    unordered_map<string,int>mpp;
    string b;
    private:
        void dfs(string word,vector<string>& seq){
            if(word == b){
                reverse(seq.begin(),seq.end());
                ans.push_back(seq);
                reverse(seq.begin(),seq.end());
                return;
            }
            int step = mpp[word];
            for(int i = 0; i<word.size(); i++){
                char oc = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(mpp.find(word)!=mpp.end()){
                        if(mpp[word]+1 == step){
                            seq.push_back(word);
                            dfs(word,seq);
                            seq.pop_back();
                        }
                    }
                }
                word[i]=oc;
            }
        }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        b = beginWord;
        st.erase(beginWord); 
        mpp[beginWord] = 1;
        while(!q.empty()){
            string word =q.front();
            int step = mpp[word];
            q.pop();
            if(word==endWord) break;
            for(int i = 0; i<word.size(); i++){
                char oc = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = step+1;
                    }
                }
                word[i]=oc;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};